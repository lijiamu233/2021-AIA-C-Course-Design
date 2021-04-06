#include"./include/header.h"
extern int mousex, mousey, mousepress;

void yuyue(int* func,int* ber)
{
	int d;
	int num = 0;	//button的序号
	char s[100];
	delay(100);
	cleardevice();
	drawyuyue();
	while (1)
	{
		mousemove();
		hz_input(80, 150, 560, 300, s, 5, BLACK);
		if (mousex > 80 && mousex < 80 + 160 && mousey > 350 && mousey < 350 + 60)
		{
			if (buttonpress(80, 350, 80 + 160, 350 + 60, mousex, mousey) && mousepress == 0)//用户框中未点击
			//（设置它为最先的if条件是因为如果点击在未点击之前，则点击为无效操作，函数会直接往下运行）
			{
				if (num == 0)
				{
					//MouseS = 1;
					lightbutton_yuyue(80, 350, 80 + 160, 350 + 60, WHITE, LIGHTBLUE, 1);//color1为边框色，color2为填充色
					num = 1;
				}
				continue;//标亮函数
			}
			else if (buttonpress(80, 350, 80 + 160, 350 + 60, mousex, mousey))//点击提交
			{
				d = *ber % 2;
				switch (d)
				{
				case 0:
					drawsuccess();
					*func = 8;
					break;
				case 1:
					drawsuccesstwo();
					*func = 8;
					break;
				}
				return;
			}
		}
		if (mousex > 400 && mousex < 560 && mousey > 350 && mousey < 350 + 60)
		{
			if (buttonpress(400, 350, 560, 350 + 60, mousex, mousey) && mousepress == 0)//未点击
			{
				if (num == 0)
				{
					lightbutton_yuyue(400, 350, 560, 350 + 60, WHITE, LIGHTBLUE, 3);
					num = 3;
				}
				continue;//标亮函数
			}
			else if (buttonpress(400, 350, 560, 350 + 60, mousex, mousey))//击中返回
			{
				*func = 8;
				break;
			}
		}
		if (mousex > 640 - 30 && mousex < 640 && mousey > 0 && mousey < 20)
		{
			if (buttonpress(640 - 30, 0, 640, 20, mousex, mousey) && mousepress == 0)//退出按钮
			{
				if (num == 0)
				{
					lightbutton_yuyue(640 - 30, 20, 640, 0, RED, RED, 4);
					num = 4;
				}
				continue;//标亮函数
			}
			else if (buttonpress(640 - 30, 0, 640, 20, mousex, mousey))
			{
				*func = 1;
				return;
			}
		}
		if (num != 0)
		{
			recoverbutton_yuyue(num);
			num = 0;
		}
		drawmouse();
#ifdef _MSC_VER
		delay_ms(50);
#else
		delay(50);
#endif
	}
}

void lightbutton_yuyue(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, 3);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//画边框
	switch (flag)
	{
	case 1:
		drawtext(160 - 17 - 16, 380 - 16, "提交", 32, 34, 34, LIGHTGRAY);
		break;
	case 3:
		drawtext(480 - 17 - 16, 380 - 16, "返回", 32, 34, 34, LIGHTGRAY);
		break;
	case 4:
		setcolor(LIGHTRED);
		line(640 - 25, 2, 640 - 5, 2 + 16);
		line(640 - 25, 2 + 16, 640 - 5, 2);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}

void recoverbutton_yuyue(int num)
{
	setfillstyle(1, BLUE);
	setcolor(BLUE);
	setlinestyle(SOLID_LINE, 0, 3);
	switch (num)
	{
	case 1:
		rectangle(80, 350, 80 + 160, 350 + 60);
		bar(80, 350, 80 + 160, 350 + 60);
		drawtext(160 - 17 - 16, 380 - 16, "提交", 32, 34, 34, WHITE);
	case 3:
		rectangle(400, 350, 560, 350 + 60);
		bar(400, 350, 560, 350 + 60);
		drawtext(480 - 17 - 16, 380 - 16, "返回", 32, 34, 34, WHITE);
	case 4:
		setfillstyle(1, WHITE);	//退出按钮
		bar(640 - 30, 20, 640, 0);
		setlinestyle(SOLID_LINE, 0, 1);
		setcolor(RED);
		line(640 - 25, 2, 640 - 5, 2 + 16);
		line(640 - 25, 2 + 16, 640 - 5, 2);
		break;
	}
}

void drawsuccess()
{
	delay(100);
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	fillellipse(65, 45, 15, 15);
	fillellipse(235, 45, 15, 15);
	fillellipse(405, 45, 15, 15);
	fillellipse(575, 45, 15, 15);
	setcolor(LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, 3);
	line(80, 45, 220, 45);
	line(250, 45, 390, 45);
	line(420, 45, 560, 45);

	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, CENTER_TEXT);
	outtextxy(62, 42, "1");
	outtextxy(232, 42, "2");
	outtextxy(402, 42, "3");
	outtextxy(572, 42, "4");

	drawtext(20, 65, "数据上传", 16, 20, 20, LIGHTGRAY);
	drawtext(190, 65, "院系审批", 16, 20, 20, LIGHTGRAY);
	drawtext(360, 65, "学校审批", 16, 20, 20, LIGHTGRAY);
	drawtext(540, 65, "通过", 16, 20, 20, LIGHTGRAY);
	delay(1000);

	setfillstyle(SOLID_FILL, LIGHTGREEN);
	fillellipse(65, 45, 15, 15);
	drawtext(20, 65, "数据上传", 16, 20, 20, LIGHTGREEN);
	drawtext(100, 150, "数据上传成功", 32, 32, 34, WHITE);
	delay(1000);

	setfillstyle(SOLID_FILL, LIGHTGREEN);
	 fillellipse(235, 45, 15, 15);
	setcolor(LIGHTGREEN);
	setlinestyle(SOLID_LINE, 0, 3);
	line(80, 45, 220, 45);
	drawtext(190, 65, "院系审批", 16, 20, 20, LIGHTGREEN);
	drawtext(100, 190, "院系审批成功", 32, 32, 34, WHITE);
	delay(1000);

	setfillstyle(SOLID_FILL, LIGHTGREEN);
	fillellipse(405, 45, 15, 15);
	setcolor(LIGHTGREEN);
	setlinestyle(SOLID_LINE, 0, 3);
	line(250, 45, 390, 45);
	drawtext(360, 65, "学校审批", 16, 20, 20, LIGHTGREEN);
	drawtext(100, 230, "学校审批成功", 32, 32, 34, WHITE);
	delay(1000);

	setfillstyle(SOLID_FILL, LIGHTGREEN);
	line(420, 45, 560, 45);
	fillellipse(575, 45, 15, 15);
	drawtext(540, 65, "通过", 16, 20, 20, LIGHTGREEN);
	drawtext(100, 300, "预约成功！", 32, 32, 34, LIGHTGREEN);
	delay(1000);
}

void drawsuccesstwo()
{
	delay(100);
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	fillellipse(65, 45, 15, 15);
	fillellipse(235, 45, 15, 15);
	fillellipse(405, 45, 15, 15);
	fillellipse(575, 45, 15, 15);
	setcolor(LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, 3);
	line(80, 45, 220, 45);
	line(250, 45, 390, 45);
	line(420, 45, 560, 45);

	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, CENTER_TEXT);
	outtextxy(62, 42, "1");
	outtextxy(232, 42, "2");
	outtextxy(402, 42, "3");
	outtextxy(572, 42, "4");

	drawtext(20, 65, "数据上传", 16, 20, 20, LIGHTGRAY);
	drawtext(190, 65, "院系审批", 16, 20, 20, LIGHTGRAY);
	drawtext(360, 65, "学校审批", 16, 20, 20, LIGHTGRAY);
	drawtext(540, 65, "通过", 16, 20, 20, LIGHTGRAY);
	delay(1000);

	setfillstyle(SOLID_FILL, LIGHTGREEN);
	fillellipse(65, 45, 15, 15);
	drawtext(20, 65, "数据上传", 16, 20, 20, LIGHTGREEN);
	drawtext(100, 150, "数据上传成功", 32, 32, 34, WHITE);
	delay(1000);

	setfillstyle(SOLID_FILL, LIGHTRED);
	fillellipse(235, 45, 15, 15);
	setcolor(LIGHTRED);
	setlinestyle(SOLID_LINE, 0, 3);
	line(80, 45, 220, 45);
	drawtext(190, 65, "院系审批", 16, 20, 20, LIGHTRED);
	drawtext(100, 190, "院系审批失败", 32, 32, 34, WHITE);
	drawtext(100, 300, "预约失败！", 32, 32, 34, LIGHTRED);
	delay(1500);

}
void drawyuyue()//绘制预约界面
{
	FILE* fp;
	USER* u;
	if ((fp = fopen("database\\UserData.dat", "rb")) == NULL)
	{
		printf("cannot open file UserData.dat");
		delay(3000);
		exit(1);
	}
	fread(u, sizeof(USER), 1, fp);
	setcolor(BLUE);
	settextstyle(3, HORIZ_DIR, 4);
	outtextxy(150, 28, u->user);
	outtextxy(150, 68, u->ID);
	fclose(fp);
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}

	setbkcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(DARKGRAY);
	line(0, 320, 640, 320);	//分界线

	setfillstyle(1, BLUE);
	bar(80, 350, 80 + 160, 350 + 60);	//用户
	drawtext(160 - 17 - 16, 380 - 16, "提交", 32, 34, 36, WHITE);

	drawtext(70, 30, "姓名:", 32, 34, 36, BLUE);
	drawtext(70, 70, "学号:", 32, 34, 36, BLUE);
	drawtext(70, 110, "外出理由:", 32, 34, 36, BLUE);
	setcolor(BLUE);
	rectangle(70, 150, 560, 300);

	bar(400, 350, 560, 350 + 60);	
	drawtext(480 - 17 - 16, 380 - 16, "返回", 32, 34, 36, WHITE);

	setfillstyle(1, WHITE);	//退出按钮
	bar(640 - 30, 20, 640, 0);
	setlinestyle(SOLID_LINE, 0, 1);
	setcolor(RED);
	line(640 - 25, 2, 640 - 5, 2 + 16);
	line(640 - 25, 2 + 16, 640 - 5, 2);
}





//外来车辆
void yuyuecar(int* func,int* ber)
{
	int d;
	int num = 0;	//button的序号
	char s[100];
	delay(100);
	cleardevice();
	drawyuyuecar();
	while (1)
	{
		mousemove();
		hz_input(210, 110, 400, 140, s, 5, BLACK);
		if (mousex > 80 && mousex < 80 + 160 && mousey > 350 && mousey < 350 + 60)
		{
			if (buttonpress(80, 350, 80 + 160, 350 + 60, mousex, mousey) && mousepress == 0)//用户框中未点击
			{
				if (num == 0)
				{
					lightbutton_yuyuecar(80, 350, 80 + 160, 350 + 60, WHITE, LIGHTRED, 1);//color1为边框色，color2为填充色
					num = 1;
				}
				continue;//标亮函数
			}
			else if (buttonpress(80, 350, 80 + 160, 350 + 60, mousex, mousey))//点击提交
			{
				d = *ber % 2;
				switch (d)
				{
				case 0:
					drawsuccess();
					*func = 8;
					break;
				case 1:
					drawsuccesstwo();
					*func = 8;
					break;
				}
				return;
			}
		}
		if (mousex > 400 && mousex < 560 && mousey > 350 && mousey < 350 + 60)
		{
			if (buttonpress(400, 350, 560, 350 + 60, mousex, mousey) && mousepress == 0)//未点击
			{
				if (num == 0)
				{
					lightbutton_yuyuecar(400, 350, 560, 350 + 60, WHITE, LIGHTRED, 3);
					num = 3;
				}
				continue;//标亮函数
			}
			else if (buttonpress(400, 350, 560, 350 + 60, mousex, mousey))//击中返回
			{
				*func = 8;
				break;
			}
		}
		if (mousex > 640 - 30 && mousex < 640 && mousey > 0 && mousey < 20)
		{
			if (buttonpress(640 - 30, 0, 640, 20, mousex, mousey) && mousepress == 0)//退出按钮
			{
				if (num == 0)
				{
					lightbutton_yuyuecar(640 - 30, 20, 640, 0, RED, RED, 4);
					num = 4;
				}
				continue;//标亮函数
			}
			else if (buttonpress(640 - 30, 0, 640, 20, mousex, mousey))
			{
				*func = 1;
				return;
			}
		}
		if (num != 0)
		{
			recoverbutton_yuyuecar(num);
			num = 0;
		}
		drawmouse();
#ifdef _MSC_VER
		delay_ms(50);
#else
		delay(50);
#endif
	}
}

void lightbutton_yuyuecar(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, 3);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//画边框
	switch (flag)
	{
	case 1:
		drawtext(160 - 17 - 16, 380 - 16, "提交", 32, 34, 34, LIGHTGRAY);
		break;
	case 3:
		drawtext(480 - 17 - 16, 380 - 16, "返回", 32, 34, 34, LIGHTGRAY);
		break;
	case 4:
		setcolor(LIGHTRED);
		line(640 - 25, 2, 640 - 5, 2 + 16);
		line(640 - 25, 2 + 16, 640 - 5, 2);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}

void recoverbutton_yuyuecar(int num)
{
	setfillstyle(1, RED);
	setcolor(RED);
	setlinestyle(SOLID_LINE, 0, 3);
	switch (num)
	{
	case 1:
		rectangle(80, 350, 80 + 160, 350 + 60);
		bar(80, 350, 80 + 160, 350 + 60);
		drawtext(160 - 17 - 16, 380 - 16, "提交", 32, 34, 34, WHITE);
	case 3:
		rectangle(400, 350, 560, 350 + 60);
		bar(400, 350, 560, 350 + 60);
		drawtext(480 - 17 - 16, 380 - 16, "返回", 32, 34, 34, WHITE);
	case 4:
		setfillstyle(1, WHITE);	//退出按钮
		bar(640 - 30, 20, 640, 0);
		setlinestyle(SOLID_LINE, 0, 1);
		setcolor(RED);
		line(640 - 25, 2, 640 - 5, 2 + 16);
		line(640 - 25, 2 + 16, 640 - 5, 2);
		break;
	}
}

void drawyuyuecar()//绘制预约界面
{
	FILE* fp;
	USER* u;
	if ((fp = fopen("database\\UserData.dat", "rb")) == NULL)
	{
		printf("cannot open file UserData.dat");
		delay(3000);
		exit(1);
	}
	fread(u, sizeof(USER), 1, fp);
	setcolor(RED);
	settextstyle(3, HORIZ_DIR, 3);
	outtextxy(150, 30, u->user);
	outtextxy(150, 70, u->ID);
	fclose(fp);
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	setbkcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(DARKGRAY);
	line(0, 320, 640, 320);	//分界线

	setfillstyle(1, RED);
	bar(80, 350, 80 + 160, 350 + 60);	//用户
	drawtext(160 - 17 - 16, 380 - 16, "提交", 32, 34, 36, WHITE);

	drawtext(70, 30, "姓名:", 32, 34, 36, RED);
	drawtext(70, 70, "学号:", 32, 34, 36, RED);
	drawtext(70, 110, "车牌号码", 32, 34, 36, RED);
	setcolor(RED);
	rectangle(210, 110, 400, 140);

	bar(400, 350, 560, 350 + 60);	//
	drawtext(480 - 17 - 16, 380 - 16, "返回", 32, 34, 36, WHITE);

	setfillstyle(1, WHITE);	//退出按钮
	bar(640 - 30, 20, 640, 0);
	setlinestyle(SOLID_LINE, 0, 1);
	setcolor(RED);
	line(640 - 25, 2, 640 - 5, 2 + 16);
	line(640 - 25, 2 + 16, 640 - 5, 2);
}



//行踪记录


void jilu(int* func,int*ber)
{
	int d;
	int num = 0;	//button的序号
	delay(100);
	cleardevice();
	drawamap();
	while (1)
	{
		mousemove();
		if (mousex > 10 && mousex < 110 && mousey > 340 && mousey < 380)
		{
			if (buttonpress(10, 340, 110, 380, mousex, mousey) && mousepress == 0)//用户框中未点击
			//（设置它为最先的if条件是因为如果点击在未点击之前，则点击为无效操作，函数会直接往下运行）
			{
				if (num == 0)
				{
					//MouseS = 1;
					lightbutton_jilu(10, 340, 110, 380, WHITE, LIGHTBLUE, 1);//color1为边框色，color2为填充色
					num = 1;
				}
				continue;//标亮函数
			}
			else if (buttonpress(10, 340, 110, 380, mousex, mousey))//用户框中点击返回
			{
				*func = 8;
				return;

			}
		}
		if (mousex > 10 && mousex < 110 && mousey > 400 && mousey < 440)
		{
			if (buttonpress(10, 400, 110, 440, mousex, mousey) && mousepress == 0)//用户框中未点击
			{
				if (num == 0)
				{
					lightbutton_jilu(10, 400, 110, 440, WHITE, LIGHTBLUE, 2);//color1为边框色，color2为填充色
					num = 2;
				}
				continue;//标亮函数
			}
			else if (buttonpress(10, 400, 110, 440, mousex, mousey))//用户框中点击
			{
				d = *ber % 2;
				switch (d)
				{
				case 0:
					movement();
					*func = 8;
					break;
				case 1:
					movementtwo();
					*func = 8;
					break;
				}
				return;
			}
		}

		if (mousex > 640 - 30 && mousex < 640 && mousey > 0 && mousey < 20)
		{
			if (buttonpress(640 - 30, 0, 640, 20, mousex, mousey) && mousepress == 0)//退出按钮
			{
				if (num == 0)
				{
					lightbutton_jilu(640 - 30, 20, 640, 0, RED, RED, 4);
					num = 4;
				}
				continue;//标亮函数
			}
			else if (buttonpress(640 - 30, 0, 640, 20, mousex, mousey))
			{
				*func = 1;
				return;
			}
		}
		if (num != 0)
		{
			recoverbutton_jilu(num);
			num = 0;
		}
		drawmouse();
#ifdef _MSC_VER
		delay_ms(50);
#else
		delay(50);
#endif
	}
}

void lightbutton_jilu(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, 3);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//画边框
	switch (flag)
	{
	case 1:
		drawtext(25, 355, "返回", 16, 17, 17, LIGHTGRAY);
		break;
	case 2:
		drawtext(25, 415, "查看", 16, 17, 17, LIGHTGRAY);
		break;
	case 4:
		setcolor(LIGHTRED);
		line(640 - 25, 2, 640 - 5, 2 + 16);
		line(640 - 25, 2 + 16, 640 - 5, 2);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}

void recoverbutton_jilu(int num)
{
	setfillstyle(1, BLUE);
	setcolor(BLUE);
	setlinestyle(SOLID_LINE, 0, 3);
	switch (num)
	{
	case 1:
		rectangle(10, 340, 110, 380);
		bar(10, 340, 110, 380);
		drawtext(25, 355, "返回", 16, 17, 17, WHITE);
	case 2:
		rectangle(10, 400, 110, 440);
		bar(10, 400, 110, 440);
		drawtext(25, 415, "查看", 16, 17, 17, WHITE);
	case 4:
		setfillstyle(1, WHITE);	//退出按钮
		bar(640 - 30, 20, 640, 0);
		setlinestyle(SOLID_LINE, 0, 1);
		setcolor(RED);
		line(640 - 25, 2, 640 - 5, 2 + 16);
		line(640 - 25, 2 + 16, 640 - 5, 2);
		break;
	}
}

void movement(void)
{
	char a[10], b[10], c[10], d[10], e[10], f[10],g[10];
	sprintf(a, "%.2lf", CreateTemperature(0));
	sprintf(b, "%.2lf", CreateTemperature(0));
	sprintf(c, "%.2lf", CreateTemperature(0));
	sprintf(d, "%.2lf", CreateTemperature(0));
	sprintf(e, "%.2lf", CreateTemperature(0));
	sprintf(f, "%.2lf", CreateTemperature(0));
	sprintf(g, "%.2lf", CreateTemperature(0));
	drawtext(70, 120, "体温：", 16, 17, 17, WHITE);
	drawtext(10, 120, "时间：", 16, 17, 17, WHITE);

	setcolor(GREEN);
	setfillstyle(1, GREEN);
	int v[] = { 240,195,250,195,200,215,190 ,215,240,195 };
	fillpoly(5, v);
	bar(140, 155, 250, 195);
	bar(140, 215, 200, 255);
	bar(190, 255, 195, 265);
	bar(140, 265, 200, 305);
	bar(140, 325, 250, 365);
	int l[] = { 190,305,200,305,250,325,240,325 ,190,305 };
	fillpoly(5, l);
	drawtext(155, 165, "东九", 16, 17, 17, WHITE);
	setcolor(GREEN);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(75, 140, a);
	setcolor(WHITE);
	outtextxy(20, 140, "9:00");
	delay(800);

	setcolor(GREEN);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(75, 160, b);
	setcolor(WHITE);
	outtextxy(20, 160, "12:00");
	setfillstyle(1, GREEN);
	bar(460, 45, 500, 85);
	drawtext(465, 65, "食堂", 16, 17, 17, WHITE);
	delay(800);

	setcolor(GREEN);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(75, 180, c);
	setcolor(WHITE);
	outtextxy(20, 180, "14:00");
	setfillstyle(1, GREEN);
	bar(460, 220, 560, 300);//图书馆
	drawtext(485, 255, "图书馆", 16, 17, 17, WHITE);
	delay(800);

	setcolor(GREEN);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(75, 200, d);
	setcolor(WHITE);
	outtextxy(20, 200, "16:00");
	setfillstyle(1, GREEN);
	bar(500, 125, 620, 185);//工程实训中心
	drawtext(515, 155, "工程实训中心", 16, 17, 17, WHITE);
	delay(800);

	setcolor(GREEN);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(75, 220, e);
	setcolor(WHITE);
	outtextxy(20, 220, "19:00");
	setfillstyle(1, GREEN);
	bar(380, 420, 440, 450);
	drawtext(380, 425, "校大门", 16, 17, 17, WHITE);
	delay(800);

	setcolor(GREEN);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(75, 240, f);
	setcolor(WHITE);
	outtextxy(20, 240, "20:00");
	setcolor(GREEN);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(75, 260, g);
	setcolor(WHITE);
	outtextxy(20, 260, "21:00");
	delay(500);
	setfillstyle(1, GREEN);
	bar(560, 35, 630, 85);//宿舍
	drawtext(575, 65, "宿舍", 16, 17, 17, WHITE);
	delay(1000);
}

void movementtwo(void)
{
	char a[10], b[10], c[10], d[10], e[10], f[10], g[10];
	sprintf(a, "%.2lf", CreateTemperature(0));
	sprintf(b, "%.2lf", CreateTemperature(0));
	sprintf(c, "%.2lf", CreateTemperature(0));
	sprintf(d, "%.2lf", CreateTemperature(0));
	sprintf(e, "%.2lf", CreateTemperature(1));
	sprintf(f, "%.2lf", CreateTemperature(1));
	sprintf(g, "%.2lf", CreateTemperature(1));
	drawtext(70, 120, "体温：", 16, 17, 17, WHITE);
	drawtext(10, 120, "时间：", 16, 17, 17, WHITE);


	setcolor(GREEN);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(75, 140, a);
	setcolor(WHITE);
	outtextxy(20, 140, "9:00");
	setfillstyle(1, GREEN);
	bar(460, 220, 560, 300);//图书馆
	drawtext(485, 255, "图书馆", 16, 17, 17, WHITE);
	delay(800);

	setcolor(RED);
	setfillstyle(1, RED);
	int v[] = { 240,195,250,195,200,215,190 ,215,240,195 };
	fillpoly(5, v);
	bar(140, 155, 250, 195);
	bar(140, 215, 200, 255);
	bar(190, 255, 195, 265);
	bar(140, 265, 200, 305);
	bar(140, 325, 250, 365);
	int l[] = { 190,305,200,305,250,325,240,325 ,190,305 };
	fillpoly(5, l);
	drawtext(155, 165, "东九", 16, 17, 17, WHITE);
	setcolor(RED);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(75, 160, g);
	setcolor(WHITE);
	outtextxy(20, 160, "12:00");
	delay(800);

	setfillstyle(1, RED);
	bar(250, 35, 330, 85);	//隔离点
	drawtext(260, 55, "隔离点", 16, 17, 17, LIGHTGRAY);
	bar(460, 220, 560, 300);//图书馆
	drawtext(485, 255, "图书馆", 16, 17, 17, WHITE);
	setcolor(RED);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(75, 180, f);
	setcolor(WHITE);
	outtextxy(20, 180, "13:00");
	delay(800);

	setfillstyle(1, RED);
	bar(140, 35, 200, 75);//校医院
	drawtext(150, 45, "校医院", 16, 17, 17, WHITE);
	setcolor(RED);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(75, 200, e);
	setcolor(WHITE);
	outtextxy(20, 200, "14:00");
	delay(1000);
}
void drawamap(void) // 绘制主页面
{
	//绘制页面及按钮
	setbkcolor(BLACK);
	setcolor(BLUE);
	setlinestyle(SOLID_LINE, 0, 1);
	line(120, 0, 120, 480);
	line(120, 20, 639, 20);

	setfillstyle(1, DARKGRAY);
	bar(0, 0, 120, 480);

	drawtext(15, 65, "时间", 16, 17, 17, WHITE);
	setcolor(YELLOW);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(10, 100, "2021.5.6");

	setfillstyle(1, BLUE);
	bar(10, 340, 110, 380);
	drawtext(25, 355, "返回", 16, 17, 17, WHITE);

	setfillstyle(1, BLUE);
	bar(10, 400, 110, 440);
	drawtext(25, 415, "查看", 16, 17, 17, WHITE);

		//地图
	setcolor(YELLOW);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(320, 5, "H U S T     M A P");

	setfillstyle(1, DARKGRAY);
	bar(560, 35, 630, 85);//宿舍
	drawtext(575, 65, "宿舍", 16, 17, 17, WHITE);

	bar(500, 125, 620, 185);//工程实训中心
	drawtext(515, 155, "工程实训中心", 16, 17, 17, WHITE);

	bar(460, 45, 500, 85);//食堂
	drawtext(465, 65, "食堂", 16, 17, 17, WHITE);

	bar(460, 220, 560, 300);//图书馆
	drawtext(485, 255, "图书馆", 16, 17, 17, WHITE);

	bar(140, 35, 200, 75);//校医院
	drawtext(150, 45, "校医院", 16, 17, 17, WHITE);

	setfillstyle(1, DARKGRAY);
	bar(250, 35, 330, 85);	//隔离点
	drawtext(260, 55, "隔离点", 16, 17, 17, LIGHTGRAY);

	setfillstyle(1, DARKGRAY);
	bar(380, 420, 440, 450);
	drawtext(380, 425, "校大门", 16, 17, 17, WHITE);

	drawtext(300, 440, "校外", 24, 25, 25, WHITE);

	setcolor(BLUE);
	setfillstyle(1, BLUE);//东九及湖
	fillellipse(320, 250, 50, 70);
	drawtext(320, 250, "湖", 16, 17, 17, WHITE);
	setcolor(DARKGRAY);
	setfillstyle(1, DARKGRAY);
	int v[] = { 240,195,250,195,200,215,190 ,215,240,195 };
	fillpoly(5, v);
	bar(140, 155, 250, 195);
	bar(140, 215, 200, 255);
	bar(190, 255, 195, 265);
	bar(140, 265, 200, 305);
	bar(140, 325, 250, 365);
	int l[] = { 190,305,200,305,250,325,240,325 ,190,305 };
	fillpoly(5, l);
	drawtext(155, 165, "东九", 16, 17, 17, WHITE);

	//路
	setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, 1);
	drawtext(210, 100, "喻家路", 16, 17, 17, LIGHTGRAY);
	line(120, 105, 639, 105);//横着的路
	line(120, 115, 400, 115);
	line(410, 115, 639, 115);

	//竖着的路
	line(400, 115, 400, 420);

	line(410, 115, 410, 195);//竖着的一截
	line(410, 205, 410, 420);
	line(410, 205, 639, 205);
	drawtext(420, 195, "韵苑路", 16, 17, 17, LIGHTGRAY);

	setcolor(WHITE);//栅栏
	setlinestyle(SOLID_LINE, 0, 3);
	line(120, 420, 639, 420);

	setfillstyle(1, WHITE);	//退出按钮
	bar(640 - 30, 20, 640, 0);
	setlinestyle(SOLID_LINE, 0, 1);
	setcolor(RED);
	line(640 - 25, 2, 640 - 5, 2 + 16);
	line(640 - 25, 2 + 16, 640 - 5, 2);

}
