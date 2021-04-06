#include "./include/header.h"

extern int mousex, mousey, mousepress;
void initmenu_set(int* func)	//初始化选择界面
{
	//unsigned char h, m;
	int num = 0;	//button的序号
	//struct time t[1];
	//clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	//gettime(t);
	//h = t[0].ti_hour;
	//m = t[0].ti_min;
	drawmenu();
	while (1)
	{
		
		//newmouse(&MouseX, &MouseY, &press);
		mousemove();
		if (mousex > 80 && mousex < 80 + 160 && mousey > 350 && mousey < 350 + 60)
		{
			if (buttonpress(80, 350, 80 + 160, 350 + 60, mousex, mousey) && mousepress == 0)//用户框中未点击
			//（设置它为最先的if条件是因为如果点击在未点击之前，则点击为无效操作，函数会直接往下运行）
			{
				if (num == 0)
				{
					//MouseS = 1;
					lightbutton_initmenu(80, 350, 80 + 160, 350 + 60, WHITE, LIGHTRED, 1);//color1为边框色，color2为填充色
					num = 1;
				}
				continue;//标亮函数
			}
			else if (buttonpress(80, 350, 80 + 160, 350 + 60, mousex, mousey))//用户框中点击
			{
				//MouseS = 0;
				*func = 2;
				return;
			}
		}
		if (mousex > 400 && mousex < 560 && mousey > 350 && mousey < 350 + 60)
		{
			if (buttonpress(400, 350, 560, 350 + 60, mousex, mousey) && mousepress == 0)//游客框中未点击
			{
				if (num == 0)
				{
					//MouseS = 1;
					lightbutton_initmenu(400, 350, 560, 350 + 60, WHITE, LIGHTRED, 3);
					num = 3;
				}
				continue;//标亮函数
			}
			else if (buttonpress(400, 350, 560, 350 + 60, mousex, mousey))//游客框中点击
			{
				//MouseS = 0;
				*func = 5;
				break;
			}
		}
		if (mousex > 640 - 30 && mousex < 640 && mousey > 0 && mousey < 20)
		{
			if (buttonpress(640 - 30, 0, 640, 20, mousex, mousey) && mousepress == 0)//退出按钮
			{
				if (num == 0)
				{
					lightbutton_initmenu(640 - 30, 20, 640, 0, RED, RED, 4);
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
			//MouseS = 0;
			recoverbutton_initmenu(num);
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

void lightbutton_initmenu(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	//clrmous(mousex, mousey);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, 3);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//画边框
	switch (flag)
	{
	case 1:
		drawtext(160 - 17 - 16, 380 - 16, "用户", 32, 34, 34, LIGHTGRAY);
		break;
	case 3:
		drawtext(480 - 17 - 16, 380 - 16, "管理员", 32, 34, 34, LIGHTGRAY);
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

void recoverbutton_initmenu(int num)
{
	setfillstyle(1, RED);
	//clrmous(mousex, mousey);
	setcolor(RED);
	setlinestyle(SOLID_LINE, 0, 3);
	switch (num)
	{
	case 1:
		rectangle(80, 350, 80 + 160, 350 + 60);
		bar(80, 350, 80 + 160, 350 + 60);
		drawtext(160 - 17 - 16, 380 - 16, "用户", 32, 34, 34, WHITE);
	case 3:
		rectangle(400, 350, 560, 350 + 60);
		bar(400, 350, 560, 350 + 60);
		drawtext(480 - 17 - 16, 380 - 16, "管理员", 32, 34, 34, WHITE);
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

void drawmenu()
{

	drawtext(106, 40, "欢迎进入高校防疫系统", 32, 36, 36, WHITE);//while (1);
	drawtext(106 - 1, 40 - 1, "欢迎进入高校防疫系统", 32, 36, 36, LIGHTGRAY);
	setcolor(WHITE);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	outtextxy(200, 40 + 16 + 36, "Made by Lijiamu and Jiyan");
	setbkcolor(BLACK);
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(DARKGRAY);
	line(0, 320, 640, 320);	//分界线

	setfillstyle(1, RED);
	bar(80, 350, 80 + 160, 350 + 60);	//用户
	drawtext(160 - 17 - 16, 380 - 16, "用户", 32, 34, 36, WHITE);

	bar(400, 350, 560, 350 + 60);	//
	drawtext(480 - 17 - 16, 380 - 16, "管理员", 32, 34, 36, WHITE);

	setfillstyle(1, WHITE);	//退出按钮
	bar(640 - 30, 20, 640, 0);
	setlinestyle(SOLID_LINE, 0, 1);
	setcolor(RED);
	line(640 - 25, 2, 640 - 5, 2 + 16);
	line(640 - 25, 2 + 16, 640 - 5, 2);


}