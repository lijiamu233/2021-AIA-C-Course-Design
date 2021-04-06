#include"./include/header.h"


extern int mousex, mousey, mousepress;


void control_drawuser(int* func,int* ber)
{
	int num = 0;	//button的序号
	delay(100);
	cleardevice();
	drawmenuandmap();
	while (1)
	{
		mousemove();
		if (mousex > 10 && mousex < 110 && mousey > 280 && mousey < 320)
		{
			if (buttonpress(10, 280, 110, 320, mousex, mousey) && mousepress == 0)//用户框中未点击
			//（设置它为最先的if条件是因为如果点击在未点击之前，则点击为无效操作，函数会直接往下运行）
			{
				if (num == 0)
				{
					lightbutton_drawuser(10, 280, 110, 320, WHITE, LIGHTBLUE, 1);//color1为边框色，color2为填充色
					num = 1;
				}
				continue;//标亮函数
			}
			else if (buttonpress(10, 280, 110, 320,  mousex, mousey))//用户框中点击预约出校
			{
				*func = 10;
				break;
			
			}
		}
		if (mousex > 10 && mousex < 110 && mousey > 220 && mousey < 260)
		{
			if (buttonpress(10, 220, 110, 260, mousex, mousey) && mousepress == 0)//用户框中未点击
			//（设置它为最先的if条件是因为如果点击在未点击之前，则点击为无效操作，函数会直接往下运行）
			{
				if (num == 0)
				{
					lightbutton_drawuser(10, 220, 110, 260, WHITE, LIGHTGREEN, 5);//color1为边框色，color2为填充色
					num = 5;
				}
				continue;//标亮函数
			}
			else if (buttonpress(10, 220, 110, 260, mousex, mousey))//用户框中点击异常用户
			{
				*ber+= 1;
				return;

			}
		}
	
		if (mousex > 10 && mousex < 110 && mousey > 340 && mousey < 380)
		{
			if (buttonpress(10 , 340,110,380,  mousex, mousey) && mousepress == 0)//用户框中未点击
			{
				if (num == 0)
				{
					//MouseS = 1;
					lightbutton_drawuser(10, 340 ,110, 380, WHITE, LIGHTBLUE, 3);
					num = 3;
				}
				continue;//标亮函数
			}
			else if (buttonpress(10, 340 ,110, 380, mousex, mousey))//用户框中点击外来车辆
			{
				*func = 11;
				break;
			}
		}

		//行踪记录
		if (mousex > 10 && mousex < 110 && mousey > 400 && mousey < 440)
		{
			if (buttonpress(10, 400, 110, 440, mousex, mousey) && mousepress == 0)//用户框中未点击
			{
				if (num == 0)
				{
					//MouseS = 1;
					lightbutton_drawuser(10, 400, 110, 440, WHITE, LIGHTBLUE, 2);
					num = 2;
				}
				continue;//标亮函数
			}
			else if (buttonpress(10, 400, 110, 440, mousex, mousey))//用户框中点击行踪记录
			{

				*func = 12;
				break;
			}
		}


		if (mousex > 640 - 30 && mousex < 640 && mousey > 0 && mousey < 20)
		{
			if (buttonpress(640 - 30, 0, 640, 20, mousex, mousey) && mousepress == 0)//退出按钮
			{
				if (num == 0)
				{
					lightbutton_drawuser(640 - 30, 20, 640, 0, RED, RED, 4);
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
			recoverbutton_drawuser(num);
			num = 0;
		}
		if (*ber % 2 == 0)
		{
			setfillstyle(1, GREEN);
			bar(10, 220, 110, 260);
			drawtext(15, 235, "正常用户", 16, 17, 17, WHITE);
		}
		else
		{
			setfillstyle(1, RED);
			bar(10, 220, 110, 260);
			drawtext(15, 235, "异常用户", 16, 17, 17, WHITE);
		}
		drawmouse();
#ifdef _MSC_VER
		delay_ms(50);
#else
		delay(50);
#endif
	}
}





	
void lightbutton_drawuser(int x, int y, int x1, int y1, int color1, int color2, int flag)
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
		drawtext(15, 295, "预约出校", 16, 17, 17, LIGHTGRAY);
		break;
	case 2:
		drawtext(15, 415, "行踪记录", 16, 17, 17, LIGHTGRAY);
		break;
	case 3:
		drawtext(15, 355, "外来车辆", 16, 17, 17, LIGHTGRAY);
		break;
	case 5:
		drawtext(15, 235, "正常用户", 16, 17, 17, LIGHTGRAY);
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

void recoverbutton_drawuser(int num)
{
	setfillstyle(1, BLUE);
	setcolor(BLUE);
	setlinestyle(SOLID_LINE, 0, 3);
	switch (num)
	{
	case 1:
		rectangle(10, 280, 110, 320);
		bar(10, 280, 110, 320);
		drawtext(15, 295, "预约出校", 16, 17, 17, WHITE);
	case 2:
		rectangle(10, 400, 110, 440);
		bar(10, 400, 110, 440);
		drawtext(15, 415, "行踪记录", 16, 17, 17, WHITE);
	case 3:
		rectangle(10, 340 ,110, 380 );
		bar(10, 340 ,110, 380 );
		drawtext(15, 355, "外来车辆", 16, 17, 17, WHITE);
	case 5:
		setfillstyle(1, GREEN);
		setcolor(GREEN);
		setlinestyle(SOLID_LINE, 0, 3);
		bar(10, 220, 110, 260);
		drawtext(15, 235, "正常用户", 16, 17, 17, WHITE);
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






void drawmenuandmap(void) // 绘制主页面
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
	outtextxy(10, 150, "2021.5.6");

	setfillstyle(1, GREEN);
	bar(10, 220, 110, 260);
	drawtext(15, 235, "正常用户", 16, 17, 17, WHITE);

	setfillstyle(1, BLUE);
	bar(10, 280, 110, 320);
	drawtext(15, 295, "预约出校", 16, 17,17, WHITE);

	bar(10, 340, 110, 380);
	drawtext(15, 355, "外来车辆", 16, 17, 17, WHITE);

	bar(10, 400, 110, 440);
	drawtext(15, 415, "行踪记录", 16, 17, 17, WHITE);

	//地图
	setcolor(YELLOW);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(320, 5, "H U S T     M A P");

	setfillstyle(1, GREEN);
	bar(560, 35, 630, 85);//宿舍
	drawtext(575, 65, "宿舍", 16, 17, 17, LIGHTGRAY);

	bar(500, 125, 620, 185);//工程实训中心
	drawtext(515, 155, "工程实训中心", 16, 17, 17,  LIGHTGRAY);

	bar(460, 45, 500, 85);//食堂
	drawtext(465, 65, "食堂", 16, 17, 17, LIGHTGRAY);

	bar(460,220,560,300);//图书馆
	drawtext(485, 255, "图书馆", 16, 17, 17, LIGHTGRAY);

	bar(140,35,200,75);//校医院
	drawtext(150, 45, "校医院", 16, 17, 17, LIGHTGRAY);

	setfillstyle(1, YELLOW);
	bar(250,35,330,85);	//隔离点
	drawtext(260, 55, "隔离点", 16, 17, 17, LIGHTGRAY);

	setfillstyle(1, BROWN);
	bar(380, 420, 440, 450);
	drawtext(380, 425, "校大门", 16, 17, 17, LIGHTGRAY);

	drawtext(300, 440, "校外",24, 25, 25, LIGHTGRAY);


	setcolor(BLUE);
	setfillstyle(1, BLUE);//东九及湖
	fillellipse(320, 250, 50, 70);
	drawtext(320, 250, "湖", 16, 17, 17, LIGHTGRAY);
	setcolor(LIGHTGRAY);
	setfillstyle(1, LIGHTGRAY);
	int v[] = { 240,195,250,195,200,215,190 ,215,240,195};
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
	line(120,105,639,105);//横着的路
	line(120,115,400,115);
	line(410,115,639,115);
	
	//竖着的路
	line(400,115,400,420);

	line(410,115,410,195);//竖着的一截
	line(410,205,410,420);
	line(410,195,639,195);//横着的路
	line(410,205,639,205);
	drawtext(420, 195, "韵苑路", 16, 17, 17, LIGHTGRAY);

	setcolor(WHITE);//栅栏
	setlinestyle(SOLID_LINE, 0, 3);
	line(120,420,639,420);
	





	setfillstyle(1, WHITE);	//退出按钮
	bar(640 - 30, 20, 640, 0);
	setlinestyle(SOLID_LINE, 0, 1);
	setcolor(RED);
	line(640 - 25, 2, 640 - 5, 2 + 16);
	line(640 - 25, 2 + 16, 640 - 5, 2);

}
	
