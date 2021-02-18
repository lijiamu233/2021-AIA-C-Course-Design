#include"./include/lgfunc.h"
#include"./include/public.h"
#include"./include/database.h"




/*********************************************
FUNCTION:admin_judge
DESCRIPTION������Ա����Ƿ�ƥ��
INPUT:admin,pass
RETURN:��
***********************************************/
int admin_judge(char* admin, char* pass)
{
	setfillstyle(SOLID_FILL, BLACK);
	bar(245, 120 + 63, 245 + 60, 120 + 80);
	bar(245, 240 + 63, 245 + 60, 240 + 80);
	bar(265, 360 + 74, 265 + 20 * 150, 360 + 90);
	if (strlen(admin) == 0)
	{
		puthz(230 + 15, 120 + 65, "δ����", 16, 17, RED);
	}
	if (strlen(pass) == 0)
	{
		puthz(230 + 15, 240 + 65, "δ����", 16, 17, RED);
		return 0;
	}
	if (strcmp(admin, "adminone") == 0);

	else
	{
		puthz(265, 360 + 75, "����Ա��Ϣ����", 16, 20, RED);
		return 0;
	}
	if (strcmp(pass, "aia666") == 0)
	{
		puthz(295, 360 + 70, "��¼�ɹ�", 16, 20, RED);
		return 1;
	}
	puthz(265, 360 + 75, "����Ա��Ϣ����", 16, 20, RED);
	return 0;
}

/*********************************************
FUNCTION:forgetpass_complete
DESCRIPTION������Ƿ���Ը���������
INPUT:u,id,np,cp
RETURN:1/0
***********************************************/
int forgetpass_complete(char* u, char* id, char* np, char* cp)
{
	int st1 = 1;//�û����Ƿ�����ı���
	int st2 = 1;//���֤�Ƿ�����ı���
	int st3 = 1;//�������Ƿ�����ı���
	int st4 = 1;//ȷ�������Ƿ�����ı���
	int state1 = 1;//���֤�����ʽ�Ƿ���ȷ�ı���
	int state2 = 1;//���������ʽ�Ƿ���ȷ�ı���
	int state3 = 1;//ȷ�������Ƿ�һ�µı���
	while (1)
	{
		recoverhz(95 + 452, 138, WHITE);//�ڸǺ���
		recoverhz(95 + 452, 218, WHITE);
		recoverhz(95 + 452, 298, WHITE);
		recoverhz(95 + 452, 348 + 30, WHITE);
		judge(u, &st1, 95 + 452, 140); //�ж��Ƿ�����,δ�����=1
		judge(id, &st2, 95 + 452, 220);
		judge(np, &st3, 95 + 452, 300);
		judge(cp, &st4, 95 + 452, 380);
		if (st1 == 1 || st2 == 1 || st3 == 1 || st4 == 1)
		{
			break;
		}
		else if (st1 == 0 && st2 == 0 && st3 == 0 && st4 == 0)
		{
			if (judge_sameuser(u,2))//�û���������
			{
				puthz(95 + 450, 140, "�û�������", 16, 17, RED);
				state1 = checkright_ID(id, 95 + 452, 220, 2);//�жϸ����ʽ�Ƿ���ȷ
				state2 = checkright_password(np, 95 + 452, 300);
				state3 = checkright_confirmedpassword(np, cp, 95 + 452, 380);
				break;
			}
			else if (!judge_sameuser(u,2))//�û�������
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
					if (name_id(u, id, np, cp))//д�����ݿ�
					{
						return 1;//���ص�¼����
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
DESCRIPTION�������жϵ�¼��Ϣ�Ƿ�������ȫ����ȷ
INPUT:u,p
RETURN:1/0
***********************************************/
int login_complete(char* u, char* p)
{
	int state1 = 1;//�Ƿ�����ı���
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
DESCRIPTION�������ж�ע����Ϣ�Ƿ�������ȫ����ȷ
INPUT:u,p,cp,id,vc,rdvc,b,bp
RETURN:1/0
***********************************************/
int register_complete(char* u, char* p, char* cp, char* id, char* vc,char* rdvc)//rdvcΪrandomvc
{
	int i;
	int state = 0;//�Ƿ�����ı���
	int state1 = 1;//�û��������ʽ�Ƿ���ȷ�ı���
	int state2 = 1;//���������ʽ�Ƿ���ȷ�ı���
	int state3 = 1;//ȷ�������Ƿ�һ�µı���
	int state4 = 1;//ѧ�������ʽ�Ƿ���ȷ�ı���
	int state5 = 1;//��֤���Ƿ�һ�µı���
	while (1)
	{
		recoverhz(547, 80, BLACK);
		recoverhz(547, 140, BLACK);
		recoverhz(547, 200, BLACK);
		recoverhz(547, 260, BLACK);
		recoverhz(547, 320, BLACK);
		recoverhz(130, 53, BLACK);
		recoverhz(280, 420, BLACK);
		judge(u, &state, 547, 90);          //judge:δ�����state=1
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
			if (!judge_sameuser(u,1))          //  �����򷵻�0��δ��������1
			{
				state1 = checkright_user(u, 547, 90);
				state2 = checkright_password(p, 547, 150);
				state3 = checkright_confirmedpassword(p, cp, 547, 210);
				state4 = checkright_ID(id, 547, 270, 1);
				state5 = checkright_verificationcode(rdvc, vc, 547, 330);
				break;
			}
			else if(judge_sameuser(u,2))//�û���û������
			{
				puthz(135, 60, "���õ��û���", 16, 17, RED);
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
					//д�����ݿ�
					puthz(280,420, "ע��ɹ�", 16, 17, RED);
					delay(2000);
					return 1;//����
				}
			}
		}
	}
	return 0;
}

/*********************************************
FUNCTION:name_id
DESCRIPTION���ж��˺������֤�Ƿ�ƥ�䣬
	���ж���������������Ƿ���ͬ��
	��ƥ������ͬ��д�������롣
INPUT:name,id,pass,againpass
RETURN:1/0
***********************************************/
int name_id(char* name, char* id, char* pass, char* againpass)
{
	int str;
	int len;
	int i,j;
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen("database\\UserData.dat", "rb+" )) == NULL)
	{
		printf("cannot open file UserDat.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);//�ļ�ָ�붨λ�����һλ
	len = ftell(fp) / sizeof(USER);//�����û�����
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);//ÿ��������һ���û�
		fread(u, sizeof(USER), 1, fp);//����Ϣ����u
		if (strcmp(name, u->user) == 0)
		{
			if (strcmp(id, u->ID) != 0)
			{
				recoverhz(95 + 452, 220, WHITE);
				puthz(95 + 452, 220, "֤����ƥ��", 16, 17, RED);
				break;
			}
			else if (strcmp(id, u->ID) == 0)
			{
				setcolor(BLUE);
				setlinestyle(SOLID_LINE, 0, 3);
				line(550, 228, 560, 238);
				line(560, 238, 570, 218);
				if (strcmp(pass, againpass) == 0)//��������������ͬ
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
					fwrite(u, sizeof(USER), 1, fp);//�޸����һ��Ҫ�ǵ�д������
					puthz(150, 480 - 10 - 60, "�����޸ĳɹ�", 16, 17, RED);
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
DESCRIPTION���ж��û����������Ƿ�ƥ��
	ƥ�����¼
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
		if (strcmp(name, u->user) == 0)//�û���ƥ��
		{
			if (strcmp(pass, u->password) != 0)//���벻��
			{
				puthz(450, 290, "�������", 16, 17, RED);
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				break;
			}
			else if (strcmp(pass, u->password) == 0)//����ƥ��
			{
				puthz(290, 355, "��¼�ɹ�", 16, 17, RED);
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
				//�л�����
			}
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	}
	if (i == len)
	{
		puthz(450, 170, "�˻�δע��", 16, 17, RED);//�ߵ����һλ
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
DESCRIPTION�����û�ע����߿�����Ϣд���ļ�
INPUT:name,id,code,bank,bankcode
RETURN:1/0
***********************************************/
void input_database(char* name, char* id, char* code)
{
	FILE* fp;
	USER* u;
	char n;
	if ((fp = fopen("database\\UserData.dat", "rb+" )) == NULL)//�������ݿ�
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
	memset(u,'\0',sizeof(USER));
	strcpy(u->user, name);
	strcpy(u->ID, id);
	strcpy(u->password, code);
	fseek(fp, 0, SEEK_END);//��ת���ļ�ĩβ
	fwrite(u, sizeof(USER), 1, fp);//���û���Ϣд���ļ� ���Ĭ��Ϊ0
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
DESCRIPTION���ж��˻��Ƿ��������,
	flagΪ1�ж��Ƿ�ע�ᣬ
	flagΪ2�ж��һ��������Ƿ����
INPUT:new_user,flag
RETURN:1/0
***********************************************/
int judge_sameuser(char* new_user,int flag)
{
	int len;
	int i;
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen("database\\UserData.dat", "rb+")) == NULL)//�������ݿ�
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
				puthz(135, 60, "�û��ѱ�ע��", 16, 17, RED);
				break;
			case 2:
				puthz(450, 110, "�˺Ŵ���", 16, 17, RED);
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
DESCRIPTION������û����Ƿ����6λ
INPUT:str,x,y
RETURN:1/0
***********************************************/
int checkright_user(char* str, int x, int y)
{
	if (strlen(str) < 6 /*С��6λ*/)
	{
		puthz(x, y, "����Ӧ", 16, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(x + 53, y - 5, ">6");
		return 1;
	}
	else if(strlen(str)>=6&&strlen(str)<=12)
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
DESCRIPTION����������Ƿ����8λ
INPUT:str,x,y
RETURN:1/0
***********************************************/
int checkright_password(char* str, int x, int y)
{
	if (strlen(str) < 8 )//С��8λ
	{
		puthz(x, y, "����Ӧ", 16, 17, RED);
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
DESCRIPTION�����ȷ�������Ƿ�һ��
INPUT:str1,str2,x,y
RETURN:1/0
***********************************************/
int checkright_confirmedpassword(char* str1, char* str2, int x, int y)
{
	if (strcmp(str1, str2) != 0)
	{
		puthz(x, y, "���β�һ��", 16, 17, RED);
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
DESCRIPTION��������֤λ�����ʽ
INPUT:str,x,y,flag
RETURN:1/0
***********************************************/
int checkright_ID(char* str, int x, int y,int flag)
{
	int i;
	int state = 1;
	if (strlen(str) != 18)
	{
		puthz(x, y, "֤��Ϊ", 16, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(x+50, y-5, "18");
		puthz(x + 73, y, "λ", 16, 17, RED);//���Ȳ�����
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
				puthz(x, y, "��ʽ����ȷ", 16, 17, RED);
				return 0;
			}
			
		}
		if (str[17] == 'X' || (str[17]>='0' && str[17]<='9'))
		{
			state = 0;//�ж����һλ�Ƿ�Ϊ���ֺ�X
		}
		else
		{
			puthz(x, y, "��ʽ����ȷ", 16, 17, RED);
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
DESCRIPTION�������֤���Ƿ�һ��
INPUT:str1,str2,x,y
RETURN:1/0
***********************************************/
int checkright_verificationcode(char* str1, char* str2,int x,int y)
{
/*	char* cstr1 = NULL,*cstr2 = NULL;
	cstr1 = str1;
	cstr2 = str2;
	while(*cstr1 != '\0')
	{
		if(*cstr1 >= 'a' && *cstr1 <= 'z' || *cstr1 >= 'A' && *cstr1 <= 'Z')
		{   //��Сд�ַ�
			if(*cstr2 >= 'a' && *cstr2 <= 'z')     //'A'<'a'
			{
				if(*cstr1 == *cstr2 || *cstr1 == *cstr2 - 32)
				{
					cstr1++;
					cstr2++;
				}  //���һ��
				else
				{
					puthz(x, y, "��֤�����", 16, 17, RED);
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
					puthz(x, y, "��֤�����", 16, 17, RED);
					return 1;
				}
			}
		}
		else //��֤�벻����ĸ
		{
			if(*cstr1 == *cstr2)
			{
				cstr1++;
				cstr2++;
			}
			else
			{
				puthz(x, y, "��֤�����", 16, 17, RED);
				return 1;
			}	
		}
	}
	if(*cstr2 != '\0')
	{
		puthz(x, y, "��֤�����", 16, 17, RED);
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
		puthz(x, y, "��֤�����", 16, 17, RED);
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
DESCRIPTION���ж�ע���״̬
INPUT:str,p,x,y
RETURN:��
***********************************************/
void judge(char* str, int* p, int x, int y)
{
	if (strlen(str) == 0)
	{
		*p = 1;
		puthz(x, y, "δ����", 16, 17, RED);
	}
	else
	{
		*p = 0;
	}
}

void recoverhz(int x, int y,int color)
{
	setfillstyle(SOLID_FILL,color);
	bar(x, y, x + 100, y + 30);
}

/*********************************************
FUNCTION:inputadmin
DESCRIPTION�������˺š�ѧ�ŵ��������ص���Ϣ
INPUT:id,x1,y1,charnum,color
RETURN:��
***********************************************/
void inputadmin(char* id, int x1, int y1, int charnum, int color)//������ַ����������xy��������ַ����ƣ���������ɫ
{
	int k = 0;
	int i = 0;
	char t;
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
	while(bioskey(1))
	{
		k = bioskey(0);//��
	}
	while (1)
	{
	
		t = bioskey(0); 
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //�ڸǹ��
					outtextxy(x1 + 8 + i * 18, y1-1, id + i);//���t�ַ�(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��
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
				if (t == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��  
				break;
			}
		}
	}
}

/*********************************************
FUNCTION:inputpassword
DESCRIPTION���������ܣ������������Ҫ���ص���Ϣ
INPUT:id,x1,y1,charnum,color
RETURN:��
***********************************************/
void inputpassword(char* id, int x1, int y1, int charnum, int color)
{
	int k = 0;
	int i = 0;
	char t;
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
	while(bioskey(1))
	{
		k = bioskey(0);//��
	}
	while (1)
	{
		t = bioskey(0);//��ȡ��ֵ
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//033��ʾEsc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��
					outtextxy(x1 + 8 + i * 18, y1 + 4, "*");//���*�ַ�
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 22);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��
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
				if (t == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 22);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��
				break;
			}
		}
	}
}

/*********************************************
FUNCTION:input_uinfo
DESCRIPTION���������ܣ������û���Ϣ
INPUT:us
RETURN:��
***********************************************/
int input_uinfo(USER* us)
{
	int i;
	int len;
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen("database\\UserData.dat", "rb+" )) == NULL)
	{
		printf("cannot open file UserDat.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);//�ļ�ָ�붨λ�����һλ
	len = ftell(fp) / sizeof(USER);//�����û�����
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);//ÿ��������һ���û�
		fread(u, sizeof(USER), 1, fp);		  //����Ϣ����u
		if (strcmp(us->user, u->user) == 0)
		{
			memset(us,'\0',sizeof(USER));              //������
			strcpy(us->user,u->user); 
			strcpy(us->password,u->password); 
			strcpy(us->ID,u->ID); 
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
