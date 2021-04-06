#include "./include/header.h"
extern int mousex, mousey, mousepress;

void admin_login(int* func)	//管理员登录界面
{
	int state = 0;
	char A[15] = { '\0' };	//管理员账号
	char P[10] = { '\0' };	//管理员密码
	int state1 = 0;
	int state2 = 0;
	//clrmous(mousex, mousey);
	delay(100);
	cleardevice();

	drawadmin();
	while (1)
	{
		//newmouse(&mousex, &mousey, &press);
		mousemove();
		if (mousex > 230 && mousex < 230 + 380 && mousey > 120 + 30 && 120 + 60)
		{
			if (buttonpress(230, 120 + 30, 230 + 380, 120 + 60, mousex, mousey) && mousepress == 0)//管理员框未点击
			{
				//MouseS = 2;
				if (state == 0 && state1 == 0)//防止被重复标亮
				{
					lightbutton_admin(230, 120 + 30, 230 + 380, 120 + 60, WHITE, DARKGRAY, 1);//color1为边框色，color2为填充色
					state = 1;
				}
				continue;

				//标亮函数
			}
			else if (buttonpress(230, 120 + 30, 230 + 380, 120 + 60, mousex, mousey))//管理员框点击
			{
				//MouseS = 0;
				lightbutton_admin(230, 120 + 30, 230 + 380, 120 + 60, WHITE, DARKGRAY, 1);
				A[0] = '\0';
				inputadmin(A, 230, 120 + 30, 12, DARKGRAY);
				//输入函数
				if (strlen(A) != 0)
					state1 = 1;
				else
					state1 = 0;
				continue;
			}
		}
		if (mousex > 230 && mousex < 230 + 380 && mousey>240 + 30 && 240 + 60)
		{
			if (buttonpress(230, 240 + 30, 230 + 380, 240 + 60, mousex, mousey) && mousepress == 0)//密码框未点击
			{
				//MouseS = 2;
				if (state == 0 && state2 == 0)
				{
					lightbutton_admin(230, 240 + 30, 230 + 380, 240 + 60, WHITE, DARKGRAY, 2);//标亮函数
					state = 2;
				}
				continue;
			}
			else if (buttonpress(230, 240 + 30, 230 + 380, 240 + 60, mousex, mousey))//密码框点击
			{
				//MouseS = 0;
				lightbutton_admin(230, 240 + 30, 230 + 380, 240 + 60, WHITE, DARKGRAY, 2);
				P[0] = '\0';
				inputpassword(P, 230, 240 + 30, 8, DARKGRAY);
				if (strlen(P) != 0)
					state2 = 1;
				else
					state2 = 0;
				continue;
				//输入函数
			}
		}
		if (mousex > 200 + 220 - 120 && mousex < 200 + 220 - 50 && mousey>360 + 30 && 360 + 30 + 35)
		{
			if (buttonpress(200 + 220 - 120, 360 + 30, 200 + 220 - 50, 360 + 30 + 35, mousex, mousey) && mousepress == 0)//登录框未点击
			{
				//MouseS = 1;
				if (state == 0)
				{
					lightbutton_admin(200 + 220 - 120, 360 + 30, 200 + 220 - 50, 360 + 30 + 35, WHITE, RED, 3);//标亮函数
					state = 3;
				}
				continue;
			}
			else if (buttonpress(200 + 220 - 120, 360 + 30, 200 + 220 - 50, 360 + 30 + 35, mousex, mousey))//登录框点击
			{
				//MouseS = 0;
				if (admin_judge(A, P))
				{
					*func = 6;
					return;
				}
				else
				{
					continue;
				}
				continue;
				//检查是否与录入数据库的管理员身份相符

			}
		}
		if (mousex > 200 + 220 + 50 && mousex < 200 + 220 + 120 && mousey>360 + 30 && 360 + 30 + 35)
		{
			if (buttonpress(200 + 220 + 50, 360 + 30, 200 + 220 + 120, 360 + 30 + 35, mousex, mousey) && mousepress == 0)//返回框未点击
			{
				//MouseS = 1;
				if (state == 0)
				{
					lightbutton_admin(200 + 220 + 50, 360 + 30, 200 + 220 + 120, 360 + 30 + 35, WHITE, BLUE, 4);//标亮函数
					state = 4;
				}
				continue;
			}
			else if (buttonpress(200 + 220 + 50, 360 + 30, 200 + 220 + 120, 360 + 30 + 35, mousex, mousey))//返回框点击
			{
				//MouseS = 0;
				*func = 0;
				return;
				//切换至初始化界面
			}
		}
		if (state != 0)
		{
			//MouseS = 0;
			if (state1 == 0)
			{
				recoverbutton_admin(1);//恢复按钮颜色
			}
			if (state2 == 0)
			{
				recoverbutton_admin(2);
			}
			if (state == 3 || state == 4 || state == 5)
			{
				recoverbutton_admin(state);
			}
			state = 0;
		}
		//if (MouseS != 0)
		//{
		//	MouseS = 0;
		//}
		drawmouse();
#ifdef _MSC_VER
		delay_ms(50);
#else
		delay(50);
#endif
	}
}


void lightbutton_admin(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	//clrmous(mousex, mousey);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//画边框
	switch (flag)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		drawtext(420 - 110, 360 + 35, "登录", 24, 28, 28, LIGHTRED);
		break;
	case 4:
		drawtext(420 + 60, 360 + 35, "返回", 24, 28, 28, LIGHTBLUE);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}


void recoverbutton_admin(int status)
{
	//clrmous(mousex, mousey);
	if (status == 1 || status && mousepress == 0)
	{
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		setlinestyle(SOLID_LINE, 0, 1);
	}
	else if (status == 3)
	{
		setfillstyle(SOLID_FILL, RED);
	}
	else if (status == 4)
	{
		setfillstyle(SOLID_FILL, BLUE);
	}
	switch (status)
	{
	case 1:
		bar(230, 120 + 30, 230 + 380, 120 + 60);
		drawtext(230 + 15, 120 + 38, "请输入管理员账号", 16, 20, 20, WHITE);
		break;
	case 2:
		bar(230, 240 + 30, 230 + 380, 240 + 60);
		drawtext(230 + 15, 240 + 38, "请输入密码", 16, 20, 20, WHITE);
		break;
	case 3:
		bar(200 + 220 - 120, 360 + 30, 200 + 220 - 50, 360 + 30 + 35);
		drawtext(420 - 110, 360 + 35, "登录", 24, 28, 28, WHITE);
		break;
	case 4:
		bar(200 + 220 + 50, 360 + 30, 200 + 220 + 120, 360 + 30 + 35);
		drawtext(420 + 60, 360 + 35, "返回", 24, 28, 28, WHITE);
		break;
	}
}

void drawadmin(void)
{
	setbkcolor(BLACK);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, CENTER_TEXT);

	bar(230, 120 + 30, 230 + 380, 120 + 60);
	drawtext(230, 120 + 15, "管理员", 16, 20, 20, WHITE);
	drawtext(230 + 15, 120 + 38, "请输入管理员账号", 16, 20, 20, WHITE);

	bar(230, 240 + 30, 230 + 380, 240 + 60);
	drawtext(230, 240 + 15, "密码", 16, 20, 20, WHITE);
	drawtext(230 + 15, 240 + 38, "请输入密码", 16, 20, 20, WHITE);

	setfillstyle(SOLID_FILL, RED);
	bar(200 + 220 - 120, 360 + 30, 200 + 220 - 50, 360 + 30 + 35);
	drawtext(420 - 110, 360 + 35, "登录", 24, 28, 28, WHITE);

	setfillstyle(SOLID_FILL, BLUE);
	bar(200 + 220 + 50, 360 + 30, 200 + 220 + 120, 360 + 30 + 35);
	drawtext(420 + 60, 360 + 35, "返回", 24, 28, 28, WHITE);

	setlinestyle(SOLID_LINE, 1, 3);
	line(70, 10, 20, 100);
	line(70, 10, 120, 100);
	line(45, 55, 95, 55);//A
	line(40, 120, 100, 120);
	line(70, 120, 70, 210);
	line(40, 210, 100, 210);//I
	line(70, 230, 20, 320);
	line(70, 230, 120, 320);
	line(45, 275, 95, 275);//A




	setlinestyle(SOLID_LINE, 0, 1);
	setcolor(RED);
	setfillstyle(1, RED);
	fillellipse(420, 45, 25, 25);
	setfillstyle(1, WHITE);
	pieslice(420, 45, 230, 310, 25);
	fillellipse(420, 45 - 5, 12, 12);
	setcolor(WHITE);
	circle(420, 45 - 5, 12);		//画登录小人
}
