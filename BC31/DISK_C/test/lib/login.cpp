#include "./include/header.h"

extern int mousex, mousey, mousepress, prev_mx, prev_my;
void user_login(int* func, USER* u)
{
	int num = 0;
	//char U[15] = {'\0'};6-12位，用户名
	//char P[20] = {'\0'};8-16位，密码
	//int state1=0;	//三项内容是否都输入的state
	int state1 = 0;
	int state2 = 0;
	memset(u, '\0', sizeof(USER));   //将别处传过来的u清零
	//clrmous(mousex, mousey);
	delay(100);
	cleardevice();
	drawlogin();
	while (1)
	{
		//newmouse(&mousex, &mousey, &press);
		mousemove();
		if (mousex > 260 && mousex < 260 + 315 && mousey>190 && mousey < 220)
		//if(buttonpress(260, 190, 575, 220, mousex, mousey))
		{
			if (buttonpress(260, 190, 260 + 315, 220, mousex, mousey) && mousepress == 0)//用户名框未点击
			{
				//MouseS = 2;
				if (num == 0 && state1 == 0)//防止被重复标亮
				{
					lightbutton_login(260, 190, 260 + 315, 220, LIGHTRED, LIGHTGRAY, 1);//color1为边框色，color2为填充色
					num = 1;
				}
				continue;

				//标亮函数
			}
			else if (buttonpress(260, 190, 260 + 315, 220, mousex, mousey))//用户名框点击
			{
				//MouseS = 0;
				lightbutton_login(260, 190, 260 + 315, 220, LIGHTRED, LIGHTGRAY, 1);
				u->user[0] = '\0';
				inputadmin(u->user, 260, 190, 12, LIGHTGRAY);
				//输入函数
				if (strlen(u->user) != 0)
					state1 = 1;
				else
					state1 = 0;
				continue;
			}

		}
		if (mousex > 260 && mousex < 260 + 315 && mousey>250 && mousey < 280)
		{
			if (buttonpress(260, 250, 260 + 315, 280, mousex, mousey) && mousepress == 0)//密码框未点击
			{
				//MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightbutton_login(260, 250, 260 + 315, 280, LIGHTRED, LIGHTGRAY, 1);//标亮函数
					num = 2;
				}
				continue;
			}
			else if (buttonpress(260, 250, 260 + 315, 280, mousex, mousey))//密码框点击
			{
				//MouseS = 0;
				lightbutton_login(260, 250, 260 + 315, 280, LIGHTRED, LIGHTGRAY, 1);
				u->password[0] = '\0';
				inputpassword(u->password, 260, 250, 16, LIGHTGRAY);
				//输入函数
				if (strlen(u->password) != 0)
					state2 = 1;
				else
					state2 = 0;
				continue;
			}
		}
		if (mousex > 260 && mousex < 380 && mousey>310 && mousey < 345)
		{
			if (buttonpress(260, 310, 380, 345, mousex, mousey) && mousepress == 0)//登录框未点击
			{
				if (num == 0)
				{
					//MouseS = 1;
					lightbutton_login(260, 310, 380, 345, WHITE, LIGHTRED, 2);//标亮函数
					num = 3;
				}
				continue;
			}
			else if (buttonpress(260, 310, 380, 345, mousex, mousey))//登录框点击
			{
				//MouseS = 0;
				if (login_complete(u->user, u->password))     //信息正确
				{
					if (input_uinfo(u))  //将信息传给u指针
					{
						*func = 8;
						return;
					}
					else
					{
						printf("something wrong");
						delay(3000);
						exit(1);
					}
				}
				else
				{
					continue;
				}
				//检测登录状态函数
			}
		}
		if (mousex > 100 && mousex < 169 && mousey>380 && mousey < 405)
		{
			if (buttonpress(100, 380, 169, 405, mousex, mousey) && mousepress == 0)//返回框未点击
			{
				if (num == 0)
				{
					//MouseS = 1;
					lightbutton_login(100, 380, 169, 405, BLUE, LIGHTGRAY, 3);//标亮函数
					num = 4;
				}
				continue;
			}
			else if (buttonpress(100, 380, 169, 405, mousex, mousey))//返回框点击
			{
				//MouseS = 0;
				*func = 0;
				//进入initmenu界面
				return;
			}
		}
		if (mousex > 290 && mousex < 350 && mousey>380 && mousey < 405)
		{
			if (buttonpress(290, 380, 350, 405, mousex, mousey) && mousepress == 0)//注册框未点击
			{
				if (num == 0)
				{
					//MouseS = 1;
					lightbutton_login(290, 380, 350, 405, BLUE, LIGHTGRAY, 4);//标亮函数
					num = 5;
				}
				continue;
			}
			else if (buttonpress(290, 380, 350, 405, mousex, mousey))//注册框点击
			{
				//MouseS = 0;
				*func = 3;
				return;
				//切换至注册界面
			}
		}
		if (mousex > 480 && mousex < 570 && mousey> 380 && mousey < 405)
		{
			if (buttonpress(480, 380, 570, 405, mousex, mousey)  && mousepress == 0)//忘记密码未点击
			{
				if (num == 0)
				{
					//MouseS = 1;
					lightbutton_login(480, 380, 570, 405, BLUE, LIGHTGRAY, 5);
					num = 6;
				}
				continue;
				//标亮函数
			}
			else if (buttonpress(480, 380, 570, 405, mousex, mousey))//忘记密码点击
			{
				//MouseS = 0;
				*func = 4;
				//切换忘记密码界面
				return;
			}
		}
		if (num != 0)
		{
			//MouseS = 0;
			if (state1 == 0)
			{
				recoverbutton_login(1);//恢复按钮颜色
			}
			if (state2 == 0)
			{
				recoverbutton_login(2);
			}
			if (num == 3 || num == 4 || num == 5 || num == 6)
			{
				recoverbutton_login(num);
			}
			num = 0;
		}
//		if (MouseS != 0)
//		{
//			MouseS = 0;
//		}
		drawmouse();
#ifdef _MSC_VER
		delay_ms(50);
#else
		delay(50);
#endif
	}
}


void lightbutton_login(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	//clrmous(mousex, mousey);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, 3);
	DrawBar(x, y, x1, y1, color2);
	//setfillstyle(1, color2);
	//bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//画边框
	switch (flag)
	{
	case 1:
		break;
	case 2:
		drawtext(290, 315, "登录", 24, 34, 34, RED);
		break;
	case 3:
		drawtext(114, 385, "返回", 16, 24, 24, BLUE);
		break;
	case 4:
		drawtext(302, 385, "注册", 16, 24, 24, BLUE);
		break;
	case 5:
		drawtext(492, 385, "忘记密码", 16, 18, 18, BLUE);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}


void recoverbutton_login(int status)
{
	//clrmous(mousex, mousey);
	if (status == 1 || status == 2)
	{
		setfillstyle(SOLID_FILL, WHITE);
		setcolor(RED);
		setlinestyle(SOLID_LINE, 0, 3);
	}
	else if (status == 3)
	{
		setfillstyle(SOLID_FILL, RED);
	}
	else
	{
		setfillstyle(SOLID_FILL, WHITE);
		setlinestyle(SOLID_LINE, 0, 1);
		setcolor(LIGHTRED);
	}
	switch (status)
	{
	case 1:
		bar(260, 190, 260 + 315, 220);
		rectangle(260, 190, 260 + 315, 220);
		drawtext(153, 193, "用户名", 24, 34, 34, LIGHTRED);
		break;
	case 2:
		bar(260, 250, 260 + 315, 280);
		rectangle(260, 250, 260 + 315, 280);
		drawtext(163, 253, "密码", 24, 50, 50, LIGHTRED);
		break;
	case 3:
		setfillstyle(SOLID_FILL, RED);
		bar(260, 310, 380, 345);
		drawtext(290, 315, "登录", 24, 34, 34, WHITE);
		break;
	case 4:
		bar(100, 380, 169, 405);
		rectangle(100, 380, 169, 405);
		drawtext(114, 385, "返回", 16, 24, 24, LIGHTRED);
		break;
	case 5:
		bar(290, 380, 350, 405);
		rectangle(290, 380, 350, 405);
		drawtext(302, 385, "注册", 16, 24, 24, LIGHTRED);
		break;
	case 6:
		bar(480, 380, 570, 405);
		rectangle(480, 380, 570, 405);
		drawtext(492, 385, "忘记密码", 16, 18, 18, LIGHTRED);
		break;
	}
}

/*********************************************
DESCRIPTION：绘制用户登录界面

***********************************************/
void drawlogin(void)
{
	setbkcolor(BLACK);
	setfillstyle(1, BLUE);
	bar(0, 0, 640, 50);
	drawtext(20, 10, "高校防疫系统", 24, 34, 34, LIGHTGRAY);
	setfillstyle(1, LIGHTBLUE);

	setcolor(LIGHTBLUE);
	setlinestyle(SOLID_LINE, 0, 2);
	line(0, 120, 640, 120);
	line(0, 0, 0, 120);
	line(639, 0, 639, 120);
	outtextxy(300, 100, "AIA");




	setfillstyle(SOLID_FILL, WHITE);
	bar(140, 190, 260, 220);
	bar(260, 190, 260 + 315, 220);	//账号框

	bar(140, 250, 260, 280);
	bar(260, 250, 260 + 315, 280);	//密码框

	setfillstyle(1, WHITE);
	sector(102, 203, 230, 310, 15, 15);
	fillellipse(102, 203 - 2, 7, 7);
	setcolor(WHITE);
	circle(102, 203 - 2, 7);//画登录小人2

	setcolor(LIGHTGRAY);
	rectangle(89, 260, 115, 275);
	arc(102, 260, 0, 180, 7);
	circle(102, 267, 4);//画锁

	setcolor(RED);
	setlinestyle(SOLID_LINE, 0, 3);
	line(260, 190, 260, 220);
	line(260, 250, 260, 280);
	rectangle(140, 190, 260 + 315, 220);
	rectangle(140, 250, 260 + 315, 280);	//画用户名和密码的边框

	drawtext(153, 193, "用户名", 24, 34, 34, LIGHTRED);
	drawtext(163, 253, "密码", 24, 50, 50, LIGHTRED);

	setfillstyle(SOLID_FILL, RED);
	bar(260, 310, 380, 345);
	drawtext(290, 315, "登录", 24, 34, 34, WHITE);//登录框

	setlinestyle(SOLID_LINE, 0, 1);
	setfillstyle(SOLID_FILL, WHITE);
	bar(290, 380, 350, 405);
	drawtext(302, 385, "注册", 16, 24, 24, LIGHTRED);
	setlinestyle(SOLID_LINE, 0, 2);
	setcolor(LIGHTRED);
	rectangle(290, 380, 350, 405);//注册框

	bar(100, 380, 169, 405);
	drawtext(114, 385, "返回", 16, 24, 24, LIGHTRED);//返回框
	rectangle(100, 380, 169, 405);

	bar(480, 380, 570, 405);
	drawtext(492, 385, "忘记密码", 16, 18, 18, LIGHTRED);//忘记密码框
	rectangle(480, 380, 570, 405);
}