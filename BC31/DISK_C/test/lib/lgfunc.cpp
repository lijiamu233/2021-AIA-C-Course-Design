#include "./include/header.h"

/*********************************************
FUNCTION:admin_judge
DESCRIPTION：管理员身份是否匹配
INPUT:admin,pass
RETURN:无
***********************************************/
int admin_judge(char* admin, char* pass)
{
	//setfillstyle(SOLID_FILL, BLACK);
	DrawBar(245, 120 + 63, 245 + 60, 120 + 80, BLACK);
	DrawBar(245, 240 + 63, 245 + 60, 240 + 80, BLACK);
	DrawBar(265, 360 + 74, 265 + 20 * 150, 360 + 90, BLACK);
	if (strlen(admin) == 0)
	{
		drawtext(230 + 15, 120 + 65, "未输入", 16, 17, 17, RED);
	}
	if (strlen(pass) == 0)
	{
		drawtext(230 + 15, 240 + 65, "未输入", 16, 17, 17, RED);
		return 0;
	}
	if (strcmp(admin, "admin") == 0);

	else
	{
		drawtext(265, 360 + 75, "管理员信息有误", 16, 20, 20, RED);
		return 0;
	}
	if (strcmp(pass, "aia666") == 0)
	{
		drawtext(295, 360 + 70, "登录成功", 16, 20, 20, RED);
		return 1;
	}
	drawtext(265, 360 + 75, "管理员信息有误", 16, 20, 20, RED);
	return 0;
}

/*********************************************
FUNCTION:forgetpass_complete
DESCRIPTION：检查是否可以更改新密码
INPUT:u,id,np,cp
RETURN:1/0
***********************************************/
int forgetpass_complete(char* u, char* id, char* np, char* cp)
{
	int st1 = 1;//用户名是否输入的变量
	int st2 = 1;//身份证是否输入的变量
	int st3 = 1;//新密码是否输入的变量
	int st4 = 1;//确认密码是否输入的变量
	int state1 = 1;//身份证输入格式是否正确的变量
	int state2 = 1;//密码输入格式是否正确的变量
	int state3 = 1;//确认密码是否一致的变量
	while (1)
	{
		recoverhz(95 + 452, 138, WHITE);//遮盖汉字
		recoverhz(95 + 452, 218, WHITE);
		recoverhz(95 + 452, 298, WHITE);
		recoverhz(95 + 452, 348 + 30, WHITE);
		judge(u, &st1, 95 + 452, 140); //判断是否输入,未输入会=1
		judge(id, &st2, 95 + 452, 220);
		judge(np, &st3, 95 + 452, 300);
		judge(cp, &st4, 95 + 452, 380);
		if (st1 == 1 || st2 == 1 || st3 == 1 || st4 == 1)
		{
			break;
		}
		else if (st1 == 0 && st2 == 0 && st3 == 0 && st4 == 0)
		{
			if (judge_sameuser(u, 2))//用户名不存在
			{
				drawtext(95 + 450, 140, "用户不存在", 16, 17, 17, RED);
				state1 = checkright_ID(id, 95 + 452, 220, 2);//判断各项格式是否正确
				state2 = checkright_password(np, 95 + 452, 300);
				state3 = checkright_confirmedpassword(np, cp, 95 + 452, 380);
				break;
			}
			else if (!judge_sameuser(u, 2))//用户名存在
			{
				state1 = checkright_ID(id, 95 + 452, 220, 2);
				state2 = checkright_password(np, 95 + 452, 300);
				state3 = checkright_confirmedpassword(np, cp, 95 + 452, 380);
				if (state1 != 0 || state2 != 0 || state3 != 0)
				{
					break;
				}
				else if (state1 == 0 && state2 == 0 && state3 == 0)
				{
					if (name_id(u, id, np, cp))//写入数据库
					{
						return 1;//返回登录界面
					}
					else
					{
						break;
					}
				}
			}
		}
	}
	return 0;
}


/*********************************************
FUNCTION:login_complete
DESCRIPTION：用来判断登录信息是否输入完全和正确
INPUT:u,p
RETURN:1/0
***********************************************/
int login_complete(char* u, char* p)
{
	int state1 = 1;//是否输入的变量
	int state2 = 1;
	while (1)
	{
		recoverhz(450, 156, BLACK);
		recoverhz(450, 284, BLACK);
		judge(u, &state1, 450, 170);
		judge(p, &state2, 450, 290);
		if (state1 == 1 || state2 == 1)
		{
			break;
		}
		else if (state1 == 0 && state2 == 0)
		{
			if (judge_rightpassword(u, p))
			{
				return 1;
			}
			else
			{
				break;
			}
		}
	}
	return 0;
}

/*********************************************
FUNCTION:register_complete
DESCRIPTION：用来判断注册信息是否输入完全和正确
INPUT:u,p,cp,id,vc,rdvc,b,bp
RETURN:1/0
***********************************************/
int register_complete(char* u, char* p, char* cp, char* id, char* vc, char* rdvc)//rdvc为randomvc
{
	int i;
	int state = 0;//是否输入的变量
	int state1 = 1;//用户名输入格式是否正确的变量
	int state2 = 1;//密码输入格式是否正确的变量
	int state3 = 1;//确认密码是否一致的变量
	int state4 = 1;//学号输入格式是否正确的变量
	int state5 = 1;//验证码是否一致的变量
	while (1)
	{
		recoverhz(547, 80, BLACK);
		recoverhz(547, 140, BLACK);
		recoverhz(547, 200, BLACK);
		recoverhz(547, 260, BLACK);
		recoverhz(547, 320, BLACK);
		recoverhz(130, 53, BLACK);
		recoverhz(280, 420, BLACK);
		judge(u, &state, 547, 90);          //judge:未输入就state=1
		judge(p, &state, 547, 150);
		judge(cp, &state, 547, 210);
		judge(id, &state, 547, 270);
		judge(vc, &state, 547, 330);
		if (state == 1)
		{
			break;
		}
		else if (state == 0)
		{
			if (!judge_sameuser(u, 1))          //  重名则返回0，未重名返回1
			{
				state1 = checkright_user(u, 547, 90);
				state2 = checkright_password(p, 547, 150);
				state3 = checkright_confirmedpassword(p, cp, 547, 210);
				state4 = checkright_ID(id, 547, 270, 1);
				state5 = checkright_verificationcode(rdvc, vc, 547, 330);
				break;
			}
			else if (judge_sameuser(u, 2))//用户名没有重名
			{
				drawtext(135, 60, "可用的用户名", 16, 17, 17, RED);
				state1 = checkright_user(u, 547, 90);
				state2 = checkright_password(p, 547, 150);
				state3 = checkright_confirmedpassword(p, cp, 547, 210);
				state4 = checkright_ID(id, 547, 270, 1);
				state5 = checkright_verificationcode(rdvc, vc, 547, 330);
				if (state1 != 0 || state2 != 0 || state3 != 0 || state4 != 0 || state5 != 0)
				{
					break;
				}
				else if (state1 == 0 && state2 == 0 && state3 == 0 && state4 == 0 && state5 == 0)
				{
					input_database(u, id, p);
					//写入数据库
					drawtext(280, 420, "注册成功", 16, 17, 17, RED);
					delay(2000);
					return 1;//返回
				}
			}
		}
	}
	return 0;
}

/*********************************************
FUNCTION:name_id
DESCRIPTION：判断账号与身份证是否匹配，
	并判断两次输入的密码是否相同，
	若匹配且相同则写入新密码。
INPUT:name,id,pass,againpass
RETURN:1/0
***********************************************/
int name_id(char* name, char* id, char* pass, char* againpass)
{
	int str;
	int len;
	int i, j;
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen("database\\UserData.dat", "rb+")) == NULL)
	{
		printf("cannot open file UserDat.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);//文件指针定位到最后一位
	len = ftell(fp) / sizeof(USER);//计算用户个数
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);//每次往后移一个用户
		fread(u, sizeof(USER), 1, fp);//将信息读入u
		if (strcmp(name, u->user) == 0)
		{
			if (strcmp(id, u->ID) != 0)
			{
				recoverhz(95 + 452, 220, WHITE);
				drawtext(95 + 452, 220, "证件不匹配", 16, 17, 17, RED);
				break;
			}
			else if (strcmp(id, u->ID) == 0)
			{
				setcolor(BLUE);
				setlinestyle(SOLID_LINE, 0, 3);
				line(550, 228, 560, 238);
				line(560, 238, 570, 218);
				if (strcmp(pass, againpass) == 0)//两次输入密码相同
				{
					u->password[0] = '\0';
					/*for (j = 0; j < 16; j++)
					{
						if (pass[j] == '\0')
						{
							str = j + 1;
							break;
						}
					}
					for (j = 0; j < str; j++)
					{
						u->password[j] = pass[j];
					}
					for (j = str; j < 16; j++)
					{
						u->password[j] = '\0';
					}*/
					strcpy(u->password, pass);
					fseek(fp, i * sizeof(USER), SEEK_SET);
					fwrite(u, sizeof(USER), 1, fp);//修改完后一定要记得写入数据
					drawtext(150, 480 - 10 - 60, "密码修改成功", 16, 17, 17, RED);
					if (u != NULL)
					{
						free(u);
						u = NULL;
					}
					if (fclose(fp) != 0)
					{
						printf("\n cannot close Database");
						exit(1);
					}
					delay(2000);
					return 1;
				}
			}
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}

	}

	if (u != NULL)
	{
		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database");
		exit(1);
	}
	return 0;
}

/*********************************************
FUNCTION:judge_rightpassword
DESCRIPTION：判断用户名和密码是否匹配
	匹配则登录
INPUT:name,id,pass,againpass
RETURN:1/0
***********************************************/
int judge_rightpassword(char* name, char* pass)
{
	int len;
	int i;
	FILE* fp;
	USER* u;
	if ((fp = fopen("database\\UserData.dat", "rb+")) == NULL)
	{
		printf("cannot open file UserData.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	u = (USER*)malloc(sizeof(USER));
	for (i = 0; i < len; i++)
	{
		
		if (u == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(name, u->user) == 0)//用户名匹配
		{
			if (strcmp(pass, u->password) != 0)//密码不配
			{
				drawtext(450, 290, "密码错误", 16, 17, 17, RED);
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				break;
			}
			else if (strcmp(pass, u->password) == 0)//密码匹配
			{
				drawtext(290, 355, "登录成功", 16, 17, 17, RED);
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				delay(1000);
				if (fclose(fp) != 0)
				{
					printf("\n cannot close Database");
					delay(3000);
					exit(1);
				}
				return 1;
				//切换界面
			}
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
		u = (USER*)malloc(sizeof(USER));
	}
	if (i == len)
	{
		drawtext(450, 170, "账户未注册", 16, 17, 17, RED);//走到最后一位
	}

	if (u != NULL)
	{
		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database");
		delay(3000);
		exit(1);
	}
	return 0;
}

/*********************************************
FUNCTION:input_database
DESCRIPTION：把用户注册或者开户信息写入文件
INPUT:name,id,code,bank,bankcode
RETURN:1/0
***********************************************/
void input_database(char* name, char* id, char* code)
{
	FILE* fp;
	USER* u;
	char n;
	if ((fp = fopen("database\\UserData.dat", "rb+")) == NULL)//建立数据库
	{
		printf("cannot open file UserData.dat");
		delay(3000);
		exit(1);
	}
	if ((u = (USER*)malloc(sizeof(USER))) == NULL)
	{
		printf("memoryallocation runs wrong in lgfunc.c");
		delay(3000);
		exit(1);
	}
	memset(u, '\0', sizeof(USER));
	strcpy(u->user, name);
	strcpy(u->ID, id);
	strcpy(u->password, code);
	fseek(fp, 0, SEEK_END);//跳转至文件末尾
	fwrite(u, sizeof(USER), 1, fp);//把用户信息写入文件 余额默认为0
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
}

/*********************************************
FUNCTION:judge_sameuser
DESCRIPTION：判断账户是否出现重名,
	flag为1判断是否注册，
	flag为2判断找回密码中是否存在
INPUT:new_user,flag
RETURN:1/0
***********************************************/
int judge_sameuser(char* new_user, int flag)
{
	int len;
	int i;
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen("database\\UserData.dat", "rb+")) == NULL)//建立数据库
	{
		printf("cannot open file UserData.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(u->user, new_user) == 0)
		{
			switch (flag)
			{
			case 1:
				drawtext(135, 60, "用户已被注册", 16, 17, 17, RED);
				break;
			case 2:
				drawtext(450, 110, "账号存在", 16, 17, 17, RED);
				break;
			default:
				printf("something wrong");
				delay(3000);
				exit(1);
			}
			if (u != NULL)
			{
				free(u);
				u = NULL;
			}
			if (fclose(fp) != 0)
			{
				printf("\n cannot close Database.");
				delay(3000);
				exit(1);
			}
			return 0;
		}
		free(u);
		u = NULL;
	}
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
	return 1;
}

/*********************************************
FUNCTION:checkright_user
DESCRIPTION：检查用户名是否大于6位
INPUT:str,x,y
RETURN:1/0
***********************************************/
int checkright_user(char* str, int x, int y)
{
	if (strlen(str) < 6 /*小于6位*/)
	{
		drawtext(x, y, "名称应", 16, 17, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(x + 53, y - 5, ">6");
		return 1;
	}
	else if (strlen(str) >= 6 && strlen(str) <= 12)
	{
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 3);
		//line(550, 98, 560, 108); 
		//line(560, 108, 570, 88); 
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;
}

/*********************************************
FUNCTION:checkright_password
DESCRIPTION：检查密码是否大于8位
INPUT:str,x,y
RETURN:1/0
***********************************************/
int checkright_password(char* str, int x, int y)
{
	if (strlen(str) < 8)//小于8位
	{
		drawtext(x, y, "密码应", 16, 17, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(x + 53, y - 5, ">8");
		return 1;
	}
	else if (strlen(str) >= 8 && strlen(str) <= 16)
	{
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 3);
		//line(550, 158, 560, 168);
		//line(560, 168, 570, 148);
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;
}

/*********************************************
FUNCTION:checkright_password
DESCRIPTION：检查确认密码是否一致
INPUT:str1,str2,x,y
RETURN:1/0
***********************************************/
int checkright_confirmedpassword(char* str1, char* str2, int x, int y)
{
	if (strcmp(str1, str2) != 0)
	{
		drawtext(x, y, "两次不一致", 16, 17, 17, RED);
		return 1;
	}
	else if (strcmp(str1, str2) == 0)
	{
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 3);
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;
}

/*********************************************
FUNCTION:checkright_ID
DESCRIPTION：检查身份证位数与格式
INPUT:str,x,y,flag
RETURN:1/0
***********************************************/
int checkright_ID(char* str, int x, int y, int flag)
{
	int i;
	int state = 1;
	if (strlen(str) != 18)
	{
		drawtext(x, y, "证件为", 16, 17, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(x + 50, y - 5, "18");
		drawtext(x + 73, y, "位", 16, 17, 17, RED);//长度不符合
		return 1;
	}
	else if (strlen(str) == 18)
	{
		for (i = 0; i < 17; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				continue;
			}
			else
			{
				drawtext(x, y, "格式不正确", 16, 17, 17, RED);
				return 0;
			}

		}
		if (str[17] == 'X' || (str[17] >= '0' && str[17] <= '9'))
		{
			state = 0;//判断最后一位是否为数字和X
		}
		else
		{
			drawtext(x, y, "格式不正确", 16, 17, 17, RED);
			return 1;
		}
	}
	if (state == 0)
	{
		switch (flag)
		{
		case 1:
			setcolor(BLUE);
			setlinestyle(SOLID_LINE, 0, 3);
			line(x + 3, y + 8, x + 13, y + 18);
			line(x + 13, y + 18, x + 23, y - 2);
			break;
		case 2:
			break;
		}
		return 0;
	}
	return 1;
}

/*********************************************
FUNCTION:checkright_verificationcode
DESCRIPTION：检查验证码是否一致
INPUT:str1,str2,x,y
RETURN:1/0
***********************************************/
int checkright_verificationcode(char* str1, char* str2, int x, int y)
{
	/*	char* cstr1 = NULL,*cstr2 = NULL;
		cstr1 = str1;
		cstr2 = str2;
		while(*cstr1 != '\0')
		{
			if(*cstr1 >= 'a' && *cstr1 <= 'z' || *cstr1 >= 'A' && *cstr1 <= 'Z')
			{   //大小写字符
				if(*cstr2 >= 'a' && *cstr2 <= 'z')     //'A'<'a'
				{
					if(*cstr1 == *cstr2 || *cstr1 == *cstr2 - 32)
					{
						cstr1++;
						cstr2++;
					}  //如果一致
					else
					{
						drawtext(x, y, "验证码错误", 16, 17, RED);
						return 1;
					}
				}
				else if(*cstr2 >= 'A' && *cstr2 <= 'Z')
				{
					if(*cstr1 == *cstr2 || *cstr1 == *cstr2 + 32)
					{
						cstr1++;
						cstr2++;
					}
					else
					{
						drawtext(x, y, "验证码错误", 16, 17, RED);
						return 1;
					}
				}
			}
			else //验证码不是字母
			{
				if(*cstr1 == *cstr2)
				{
					cstr1++;
					cstr2++;
				}
				else
				{
					drawtext(x, y, "验证码错误", 16, 17, RED);
					return 1;
				}
			}
		}
		if(*cstr2 != '\0')
		{
			drawtext(x, y, "验证码错误", 16, 17, RED);
			return 1;
		}
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 3);
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	*/
	if (strcmp(str1, str2) != 0)
	{
		drawtext(x, y, "验证码错误", 16, 17, 17, RED);
		return 1;
	}
	else if (strcmp(str1, str2) == 0)
	{
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 3);
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;
}


/*********************************************
FUNCTION:judge
DESCRIPTION：判断注册的状态
INPUT:str,p,x,y
RETURN:无
***********************************************/
void judge(char* str, int* p, int x, int y)
{
	if (strlen(str) == 0)
	{
		*p = 1;
		drawtext(x, y, "未输入", 16, 17, 17, RED);
	}
	else
	{
		*p = 0;
	}
}

void recoverhz(int x, int y, int color)
{
	setfillstyle(SOLID_FILL, color);
	bar(x, y, x + 100, y + 30);
}

/*********************************************
FUNCTION:inputadmin
DESCRIPTION：输入账号、学号等无需隐藏的信息
INPUT:id,x1,y1,charnum,color
RETURN:无
***********************************************/
void inputadmin(char* id, int x1, int y1, int charnum, int color)//输入的字符串，输入的xy，输入的字符限制，输入框的颜色
{
	int k = 0;
	int i = 0;
	char t;
	//clrmous(mousex, mousey);
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
	//while (bioskey(1))
	//{
	//	k = bioskey(0);//吃
	//}
	while (1)
	{

		if (t = get_c())
		{
			//if (t == '\n') exit(t);
			if (i < charnum)
			{
				if (t != '\n'
					&& t != '\r'
					&& t != ' '
					&& t != 033)//Esc
				{
					//exit(t);
					if (t != '\b')
					{
						*(id + i) = t;
						*(id + i + 1) = '\0';
						bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //遮盖光标
						//outtextxy(x1 + 8 + i * 18, y1 - 1, id + i);//输出t字符(16)
						drawletter(x1 + 8 + i * 18, y1 - 1, *(id + i));
						i++;
						line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
					}
					else if (t == '\b' && i > 0)//退格键
					{
						bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标
						bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//遮盖文字
						i--;//减少一个字数
						line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
						*(id + i) = '\0';
						*(id + i + 1) = '\0';
					}
				}
				else
				{
					//exit(t);
					setfillstyle(SOLID_FILL, color);
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标
					break;
				}
			}
			else if (i >= charnum)
			{
				if (t != '\n'
					&& t != '\r'
					&& t != ' '
					&& t != 033)//Esc
				{
					if (t == '\b' && i > 0)//退格键
					{
						bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标
						bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//遮盖文字
						i--;//减少一个字数
						line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
						*(id + i) = '\0';
					}
				}
				else
				{
					setfillstyle(SOLID_FILL, color);
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标  
					break;
				}
			}
		}
#ifdef _MSC_VER
		delay_ms(50);
#else
		delay(50);
#endif
	}

}

/*********************************************
FUNCTION:inputpassword
DESCRIPTION：函数功能：输入密码等需要隐藏的信息
INPUT:id,x1,y1,charnum,color
RETURN:无
***********************************************/
void inputpassword(char* id, int x1, int y1, int charnum, int color)
{
	int k = 0;
	int i = 0;
	char t;
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
	//while (bioskey(1))
	//{
	//	k = bioskey(0);//吃
	//}
	while (1)
	{
		if(t = get_c())//读取键值
		{
			if (i < charnum)
			{
				if (t != '\n'
					&& t != '\r'
					&& t != ' '
					&& t != 033)//033表示Esc
				{
					if (t != '\b')
					{
						*(id + i) = t;
						*(id + i + 1) = '\0';
						bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
						outtextxy(x1 + 8 + i * 18, y1 + 4, "*");//输出*字符
						i++;
						line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
					}
					else if (t == '\b' && i > 0)//退格键
					{
						bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
						bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 22);//遮盖文字
						i--;//减少一个字数
						line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
						*(id + i) = '\0';
						*(id + i + 1) = '\0';
					}
				}
				else
				{
					setfillstyle(SOLID_FILL, color);
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
					break;
				}
			}
			else if (i >= charnum)
			{
				if (t != '\n'
					&& t != '\r'
					&& t != ' '
					&& t != 033)//Esc
				{
					if (t == '\b' && i > 0)//退格键
					{
						bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
						bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 22);//遮盖文字
						i--;//减少一个字数
						line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
						*(id + i) = '\0';
					}
				}
				else
				{
					setfillstyle(SOLID_FILL, color);
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
					break;
				}
			}
		}
#ifdef _MSC_VER
		delay_ms(50);
#else
		delay(50);
#endif
	}
}

/*********************************************
FUNCTION:input_uinfo
DESCRIPTION：函数功能：输入用户信息
INPUT:us
RETURN:无
***********************************************/
int input_uinfo(USER* us)
{
	int i;
	int len;
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen("database\\UserData.dat", "rb+")) == NULL)
	{
		printf("cannot open file UserDat.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);//文件指针定位到最后一位
	len = ftell(fp) / sizeof(USER);//计算用户个数
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);//每次往后移一个用户
		fread(u, sizeof(USER), 1, fp);		  //将信息读入u
		if (strcmp(us->user, u->user) == 0)
		{
			memset(us, '\0', sizeof(USER));              //先重置
			strcpy(us->user, u->user);
			strcpy(us->password, u->password);
			strcpy(us->ID, u->ID);
			if (u != NULL)
			{
				free(u);
				u = NULL;
			}
			if (fclose(fp) != 0)
			{
				printf("\n cannot close Database");
				exit(1);
			}
			delay(2000);
			return 1;
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	}
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database");
		exit(1);
	}
	return 0;
}
