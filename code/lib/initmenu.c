#include"./include/public.h"
#include"./include/initmenu.h"
void initmenu_set(int *func)	//��ʼ��ѡ�����
{
	unsigned char h, m;
	int num=0;	//button�����
	struct time t[1];
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	gettime(t);
	h = t[0].ti_hour;
	m = t[0].ti_min;
	drawmenu();

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(mouse_press(80, 350, 80 + 160, 350 + 60) == 2)//�û�����δ���
		//��������Ϊ���ȵ�if��������Ϊ��������δ���֮ǰ������Ϊ��Ч������������ֱ���������У�
		{
			if (num == 0)
			{
				MouseS = 1;
				lightbutton_initmenu(80, 350, 80 + 160, 350 + 60, WHITE, LIGHTRED, 1);//color1Ϊ�߿�ɫ��color2Ϊ���ɫ
				num = 1;
			}
			continue;//��������
		}
		else if (mouse_press(80, 350, 80 + 160, 350 + 60) == 1)//�û����е��
		{
			MouseS = 0;
			*func = 2;
			return;
		}

		else if (mouse_press(400, 350, 560, 350 + 60) == 2)//�οͿ���δ���
		{
			if (num == 0)
			{
				MouseS = 1;
				lightbutton_initmenu(400, 350, 560, 350 + 60, WHITE, LIGHTRED, 3);
				num = 3;
			}
			continue;//��������
		}
		else if (mouse_press(400, 350, 560, 350 + 60) == 1)//�οͿ��е��
		{
			MouseS = 0;
			*func = 5;
			break;
		}

		if(mouse_press(640 - 30, 0, 640, 20) == 2)//�˳���ť
		{
			if (num == 0)
			{
				lightbutton_initmenu(640 - 30, 20, 640, 0, RED, RED, 4);
				num = 4;
			}
			continue;//��������
		}
		else if(mouse_press(640 - 30, 0, 640, 20) == 1)
		{
			*func = 1;
			return;
		}
		else
		{
			if (num != 0)
			{
				MouseS = 0;
				recoverbutton_initmenu(num);
				num = 0;
			}
			continue;
		}
		
	}
}

void lightbutton_initmenu(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//���߿�
	switch (flag)
	{
	case 1:
		puthz(160 - 17 - 16, 380 - 16, "�û�", 32, 34, LIGHTGRAY);
		break;
	case 3:
		puthz(480 - 17 - 16, 380 - 16, "����Ա", 32, 34, LIGHTGRAY);
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
	clrmous(MouseX, MouseY);
	setcolor(RED);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	switch (num)
	{
	case 1:
		rectangle(80, 350, 80 + 160, 350 + 60);
		bar(80, 350, 80 + 160, 350 + 60);
		puthz(160 - 17 - 16, 380 - 16, "�û�", 32, 34, WHITE);
	case 3:
		rectangle(400, 350, 560, 350 + 60);
		bar(400, 350, 560, 350 + 60);
		puthz(480 - 17 - 16, 380 - 16, "����Ա", 32, 34, WHITE);
	case 4:
		setfillstyle(1, WHITE);	//�˳���ť
		bar(640 - 30, 20, 640, 0);
		setlinestyle(SOLID_LINE, 0, 1);
		setcolor(RED);
		line(640 - 25, 2, 640 - 5, 2 + 16);
		line(640 - 25, 2 + 16, 640 - 5, 2);
		break;
	}
}

void drawmenu(void)
{
	puthz(106, 40, "��ӭ�����У����ϵͳ", 32, 36, WHITE);
	puthz(106 - 1, 40 - 1, "��ӭ�����У����ϵͳ", 32, 36, LIGHTGRAY);
	setcolor(WHITE);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	outtextxy(200, 40 + 16 + 36, "Made by Lijiamu and Jiyan");
	setbkcolor(BLACK);
	setlinestyle(SOLID_LINE,0,3);
	setcolor(DARKGRAY);
	line(0,320,640,320);	//�ֽ���

	setfillstyle(1,RED);
	bar(80,350,80+160,350+60);	//�û�
	puthz(160-17-16,380-16, "�û�", 32, 34, WHITE);

	bar(400,350,560,350+60);	//
	puthz(480-17-16,380-16,"����Ա", 32, 34, WHITE);

	setfillstyle(1,WHITE);	//�˳���ť
	bar(640-30,20,640,0);
	setlinestyle(SOLID_LINE, 0, 1);
	setcolor(RED);
	line(640-25,2,640-5,2+16);
	line(640 - 25, 2 + 16, 640 - 5, 2);


}