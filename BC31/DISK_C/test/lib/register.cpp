#include"./include/header.h"

extern int mousex, mousey, mousepress;
/***********************************
DESCRIPTION: 用户注册界面控制

***********************************/
void user_register(int* func)
{
	int num = 0;
	char str[6] = { '\0' };
	char U[15] = { '\0' };//6-12位，用户名
	char I[20] = { '\0' };//10位，学号
	char P[20] = { '\0' };//8-16位，密码
	char CP[20] = { '\0' };//8-16位，确认密码
	char VC[6] = { '\0' };//5位，验证码

	int state1 = 0;       //内容输入判断参数
	int state2 = 0;
	int state3 = 0;
	int state4 = 0;
	int state5 = 0;
	////clrmous(mousex, mousey);
	delay(100);
	cleardevice();
	draw_signin(str);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);

	while (1)
	{
		//newmouse(&mousex, &mousey, &press);
		mousemove();
		if (mousex > 95 && mousex < 545 && mousey>85 && mousey < 110)
		{
			if (buttonpress(95, 85, 545, 110, mousex, mousey) && mousepress == 0)           //未点击账号框
			{
				//MouseS = 2;
				if (num == 0 && state1 == 0)                  //num = 0防止重复标亮
				{
					lightbutton_register(95, 85, 545, 110, RED, LIGHTGRAY, 1);
					num = 1;
				}
				continue;
			}

			else if (buttonpress(95, 85, 545, 110, mousex, mousey))      //点击账号框
			{
				//MouseS = 0;
				lightbutton_register(95, 85, 545, 110, RED, LIGHTGRAY, 1);
				U[0] = '\0';
				inputadmin(U, 95, 85, 12, LIGHTGRAY);//后期输入函数
				if (strlen(U) != 0)
					state1 = 1;
				else
					state1 = 0;
				continue;
			}
		}
		if (mousex > 95 && mousex < 545 && mousey>145 && mousey < 170)
		{
			if (buttonpress(95, 145, 545, 170, mousex, mousey) && mousepress == 0)     //未点击密码框
			{
				//MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightbutton_register(95, 145, 545, 170, RED, LIGHTGRAY, 2);
					num = 2;
				}
				continue;
			}

			else if (buttonpress(95, 145, 545, 170, mousex, mousey))     //点击密码框
			{
				lightbutton_register(95, 145, 545, 170, RED, LIGHTGRAY, 2);
				//MouseS = 0;
				P[0] = '\0';
				inputpassword(P, 95, 145, 16, LIGHTGRAY);//输入函数
				if (strlen(P) != 0)
					state2 = 1;
				else
					state2 = 0;
				continue;
			}
		}

		if (mousex > 95 && mousex < 545 && mousey>205 && mousey < 230)
		{
			if (buttonpress(95, 205, 545, 230, mousex, mousey) && mousepress == 0)     //未点击确认密码框
			{
				//MouseS = 2;
				if (num == 0 && state3 == 0)
				{
					lightbutton_register(95, 205, 545, 230, RED, LIGHTGRAY, 3);
					num = 3;
				}
				continue;
			}

			else if (buttonpress(95, 205, 545, 230, mousex, mousey))      //点击确认密码框
			{
				lightbutton_register(95, 205, 545, 230, RED, LIGHTGRAY, 3);
				//MouseS = 0;
				CP[0] = '\0';
				inputpassword(CP, 95, 205, 16, LIGHTGRAY);
				//输入函数
				if (strlen(CP) != 0)
					state3 = 1;
				else
					state3 = 0;
				continue;
			}
		}

		if (mousex > 95 && mousex < 545 && mousey>260 && mousey < 290)
		{
			if (buttonpress(95, 265, 545, 290, mousex, mousey) && mousepress == 0)      //未点击学号框
			{
				//MouseS = 2;
				if (num == 0 && state4 == 0)
				{
					lightbutton_register(95, 265, 545, 290, RED, LIGHTGRAY, 4);
					num = 4;
				}
				continue;
			}

			else if (buttonpress(95, 265, 545, 290, mousex, mousey))
			{
				lightbutton_register(95, 265, 545, 290, RED, LIGHTGRAY, 4);
				//MouseS = 0;
				I[0] = '\0';
				inputadmin(I, 95, 265, 18, LIGHTGRAY);
				//输入函数
				if (strlen(I) != 0)
					state4 = 1;
				else
					state4 = 0;
				continue;
			}
		}

		if (buttonpress(95, 325, 175, 350, mousex, mousey))
		{
			//clrmous(mousex, mousey);
			delay(10);
			setfillstyle(1, WHITE);
			bar(95, 325, 173, 350);
			random_str(str);
			setcolor(BLUE);
			settextjustify(LEFT_TEXT, TOP_TEXT);
			settextstyle(1, HORIZ_DIR, 3);
			outtextxy(97, 322, str);
			continue;
		}

		if (mousex > 175 && mousex < 545 && mousey>325 && mousey < 350)
		{
			//MouseS = 2;
			if (buttonpress(175, 325, 545, 350, mousex, mousey) && mousepress == 0)            //未点击验证码输入框
			{
				if (num == 0 && state5 == 0)
				{
					lightbutton_register(175, 325, 545, 350, RED, LIGHTGRAY, 5);
					num = 5;
				}
				continue;
			}

			else if (buttonpress(175, 325, 545, 350, mousex, mousey))
			{
				lightbutton_register(175, 325, 545, 350, RED, LIGHTGRAY, 5);
				//MouseS = 0;
				VC[0] = '\0';
				inputadmin(VC, 175, 325, 5, LIGHTGRAY);
				//输入函数
				if (strlen(VC) != 0)
					state5 = 1;
				else
					state5 = 0;
				continue;
			}
		}

		if (mousex > 143 && mousex < 237 && mousey>370 && mousey < 400)
		{
			if (buttonpress(143, 370, 237, 400, mousex, mousey) && mousepress == 0)                //未点击重置框
			{
				if (num == 0)
				{
					//MouseS = 1;
					lightbutton_register(143, 370, 237, 400, WHITE, CYAN, 6);
					num = 6;
				}
				continue;
			}

			else if (buttonpress(143, 370, 237, 400, mousex, mousey))
			{
				//MouseS = 0;
				cleardevice();
				draw_signin(str);
				num = 0;
				state1 = 0;
				state2 = 0;
				state3 = 0;
				state4 = 0;
				state5 = 0;
				U[0] = '\0';
				I[0] = '\0';
				P[0] = '\0';
				CP[0] = '\0';
				VC[0] = '\0';
				//重置
				continue;
			}
		}

		if (mousex > 273 && mousex < 367 && mousey>370 && mousey < 400)
		{
			if (buttonpress(273, 370, 367, 400, mousex, mousey) && mousepress == 0)					//未点击注册框
			{
				if (num == 0)
				{
					//MouseS = 1;
					lightbutton_register(273, 370, 367, 400, WHITE, RED, 7);
					num = 7;
				}
				continue;
			}

			else if (buttonpress(273, 370, 367, 400, mousex, mousey))
			{
				//MouseS = 0;
				if (register_complete(U, P, CP, I, VC, str))
				{
					*func = 2;
					return;
				}
				else
				{
					continue;
				}
				//注册判断
			}
		}

		if (mousex > 403 && mousex < 497 && mousey>370 && mousey < 400)
		{
			if (buttonpress(403, 370, 497, 400, mousex, mousey) && mousepress == 0)				//未点击返回框
			{
				if (num == 0)
				{
					//MouseS = 1;
					lightbutton_register(403, 370, 497, 400, WHITE, BLUE, 8);
					num = 8;
				}
				continue;
			}

			else if (buttonpress(403, 370, 497, 400, mousex, mousey))
			{
				//MouseS = 0;
				*func = 2;
				return; //返回
			}
		}

		if (num != 0)
		{
			//MouseS = 0;
			if (state1 == 0)
			{
				recoverbutton_register(1);
			}
			if (state2 == 0)
			{
				recoverbutton_register(2);
			}
			if (state3 == 0)
			{
				recoverbutton_register(3);
			}
			if (state4 == 0)
			{
				recoverbutton_register(4);
			}
			if (state5 == 0)
			{
				recoverbutton_register(5);
			}
			if (num == 6 || num == 7 || num == 8)
			{
				recoverbutton_register(num);
			}
			num = 0;
		}
		drawmouse();
#ifdef _MSC_VER
		delay_ms(50);
#else
		delay(50);
#endif
		//if (MouseS != 0)
		//{
			//MouseS = 0;
		//}
	}

}

/****************************************
FUNCTION: draw_signin
DESCRIPTION: 注册界面绘制
INPUT: 随机验证码str
RETURN: 无
*****************************************/
void draw_signin(char* str)
{

	setbkcolor(BLACK);
	setlinestyle(SOLID_LINE, 0, 4);
	setcolor(RED);
	setfillstyle(1, RED);

	setcolor(LIGHTBLUE);
	setfillstyle(1, LIGHTBLUE);
	fillellipse(320, 40, 25, 25);
	setfillstyle(1, WHITE);
	pieslice(320, 40, 230, 310, 25);
	fillellipse(320, 40 - 5, 12, 12);
	setcolor(WHITE);
	circle(320, 40 - 5, 12);		//画登陆小人

	setfillstyle(1, WHITE);
	drawtext(95, 60, "账号", 16, 17, 17, WHITE);
	bar(95, 85, 545, 110);
	//rectangle(95,85,545,110);

	drawtext(95, 120, "密码", 16, 17, 17, WHITE);
	bar(95, 145, 545, 170);
	//rectangle(95,145,545,170);

	drawtext(95, 180, "确认密码", 16, 17, 17, WHITE);
	bar(95, 205, 545, 230);
	//rectangle(95,205,545,230);

	drawtext(95, 240, "学号", 16, 17, 17, WHITE);
	bar(95, 265, 545, 290);
	//rectangle(95,265,545,290);

	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(BLACK);
	setfillstyle(1, WHITE);
	drawtext(95, 300, "验证码", 16, 17, 17, WHITE);
	bar(95, 325, 545, 350);
	rectangle(95, 325, 175, 350);

	random_str(str);
	setcolor(BLUE);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	settextstyle(1, HORIZ_DIR, 3);
	outtextxy(100, 322, str);                      //验证码输出

	setfillstyle(1, CYAN);
	bar(143, 370, 237, 400);
	drawtext(161, 373, "重置", 24, 34, 34, WHITE);

	setfillstyle(1, RED);
	bar(273, 370, 367, 400);
	drawtext(291, 373, "注册", 24, 34, 34, WHITE);

	setfillstyle(1, BLUE);
	bar(403, 370, 497, 400);
	drawtext(421, 373, "返回", 24, 34, 34, WHITE);

	/*	if()
		{
			drawtext("两次输入的密码不一致");
		}

		if()
		{
			drawtext(,,"请输入正确的身份证号");
		}  */

}

/****************************************
FUNCTION: random_str
DESCRIPTION: 随机验证码
INPUT: str
RETURN: 无
****************************************/
void random_str(char* str)
{
	char a, j, i;
	srand(time(NULL));
	for (i = 0; i < 5; i++)
	{
		j = rand() % 3;
		if (j == 0)
		{
			a = rand() % 26 + 65;
			str[i] = a;
		}
		else if (j == 1)
		{
			a = rand() % 26 + 97;
			str[i] = a;
		}
		else
		{
			a = rand() % 10 + 48;
			str[i] = a;
		}
	}
	str[5] = '\0';
}

/******************************************
FUNCTION: lightbutton_register
DESCRIPTION: 注册界面标亮
INPUT: x,y,x1,y1,color1,color2,flag
RETURN: 无
******************************************/
void lightbutton_register(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	//clrmous(mousex, mousey);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, 3);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//画边框

	if (flag == 6)
	{
		drawtext(161, 373, "重置", 24, 34, 34, LIGHTCYAN);
	}
	else if (flag == 7)
	{
		drawtext(291, 373, "注册", 24, 34, 34, LIGHTRED);
	}
	else if (flag == 8)
	{
		drawtext(421, 373, "返回", 24, 34, 34, LIGHTBLUE);
	}
}

/**********************************************
FUNCTION: recoverbutton_register
DESCRIPTION: 注册界面恢复标亮
INPUT:	status
RETURN: 无
**********************************************/
void recoverbutton_register(int status)
{
	//clrmous(mousex, mousey);
	setfillstyle(1, WHITE);
	switch (status)
	{
	case 1:
		bar(95, 85, 545, 110);
		break;
	case 2:
		bar(95, 145, 545, 170);
		break;
	case 3:
		bar(95, 205, 545, 230);
		break;
	case 4:
		bar(95, 265, 545, 290);
		break;
	case 5:
		bar(175, 325, 545, 350);
		break;
	case 6:
		setfillstyle(1, CYAN);
		bar(143, 370, 237, 400);
		drawtext(161, 373, "重置", 24, 34, 34, WHITE);
		break;
	case 7:
		setfillstyle(1, RED);
		bar(273, 370, 367, 400);
		drawtext(291, 373, "注册", 24, 34, 34, WHITE);
		break;
	case 8:
		setfillstyle(1, BLUE);
		bar(403, 370, 497, 400);
		drawtext(421, 373, "返回", 24, 34, 34, WHITE);
		break;
	}
}