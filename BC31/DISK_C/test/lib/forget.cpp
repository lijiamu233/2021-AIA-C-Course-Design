#include "./include/header.h"

extern int mousex, mousey, mousepress;
void user_forgetpass(int* func)
{
	int num = 0;
	char U[15] = { '\0' };//6-12λ���û���
	char I[20] = { '\0' };//10λ��ѧ��
	char NP[20] = { '\0' };//8-16λ��������
	char CP[20] = { '\0' };//8-16λ��ȷ������
	int state1 = 0;
	int state2 = 0;
	int state3 = 0;
	int state4 = 0;
	//clrmous(mousex, mousey);
	delay(100);
	cleardevice();
	draw_forgetpass();

	while (1)
	{
		//newmouse(&mousex, &mousey, &press);
		mousemove();
		if (mousex > 95 && mousex < 95 + 450 && mousey>130 && mousey < 130 + 30)
		{
			if (buttonpress(95, 130, 95 + 450, 130 + 30, mousex, mousey) && mousepress == 0)//�û�����δ���
			{
				//MouseS = 2;
				if (num == 0 && state1 == 0)//��ֹ���ظ�����
				{
					lightbutton_forget(95, 130, 95 + 450, 130 + 30, LIGHTBLUE, DARKGRAY, 1);//color1Ϊ�߿�ɫ��color2Ϊ���ɫ
					num = 1;
				}
				continue;

				//��������
			}
			else if (buttonpress(95, 130, 95 + 450, 130 + 30, mousex, mousey))//�û�������
			{
				//MouseS = 0;
				lightbutton_forget(95, 130, 95 + 450, 130 + 30, LIGHTBLUE, DARKGRAY, 1);
				U[0] = '\0';
				inputadmin(U, 95, 130, 12, DARKGRAY);
				if (strlen(U) != 0)
					state1 = 1;
				else
					state1 = 0;
				continue;
				//���뺯��
			}
		}
		if (mousex > 95 && mousex < 95 + 450 && mousey>180 + 30 && mousey < 180 + 60)
		{
			if (buttonpress(95, 180 + 30, 95 + 450, 180 + 60, mousex, mousey) && mousepress == 0)//���֤δ���
			{
				//MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightbutton_forget(95, 180 + 30, 95 + 450, 180 + 60, LIGHTBLUE, DARKGRAY, 1);//��������
					num = 2;
				}
				continue;
			}
			else if (buttonpress(95, 180 + 30, 95 + 450, 180 + 60, mousex, mousey))//���֤���
			{
				//MouseS = 0;
				lightbutton_forget(95, 180 + 30, 95 + 450, 180 + 60, LIGHTBLUE, DARKGRAY, 1);
				I[0] = '\0';
				inputadmin(I, 95, 180 + 30, 18, DARKGRAY);
				if (strlen(I) != 0)
					state2 = 1;
				else
					state2 = 0;
				continue;
				//���뺯��
			}
		}
		if (mousex > 95 && mousex < 95 + 450 && mousey>260 + 30 && mousey < 260 + 60)
		{
			if (buttonpress(95, 260 + 30, 95 + 450, 260 + 60, mousex, mousey) && mousepress == 0)//�������δ���
			{
				//MouseS = 2;
				if (num == 0 && state3 == 0)
				{
					lightbutton_forget(95, 260 + 30, 95 + 450, 260 + 60, LIGHTBLUE, DARKGRAY, 1);//��������
					num = 3;
				}
				continue;
			}
			else if (buttonpress(95, 260 + 30, 95 + 450, 260 + 60, mousex, mousey))//���������
			{
				//MouseS = 0;
				lightbutton_forget(95, 260 + 30, 95 + 450, 260 + 60, LIGHTBLUE, DARKGRAY, 1);
				NP[0] = '\0';
				inputpassword(NP, 95, 260 + 30, 16, DARKGRAY);
				if (strlen(NP) != 0)
					state3 = 1;
				else
					state3 = 0;
				continue;
				//���뺯��
			}
		}
		if (mousex > 95 && mousex < 95 + 450 && mousey>340 + 30 && mousey < 340 + 60)
		{
			if (buttonpress(95, 340 + 30, 95 + 450, 340 + 60, mousex, mousey) && mousepress == 0)//ȷ�������δ���
			{
				//MouseS = 2;
				if (num == 0 && state4 == 0)
				{
					lightbutton_forget(95, 340 + 30, 95 + 450, 340 + 60, LIGHTBLUE, DARKGRAY, 1);//��������
					num = 4;
				}
				continue;
			}
			else if (buttonpress(95, 340 + 30, 95 + 450, 340 + 60, mousex, mousey))//ȷ���������
			{
				//MouseS = 0;
				lightbutton_forget(95, 340 + 30, 95 + 450, 340 + 60, LIGHTBLUE, DARKGRAY, 1);
				CP[0] = '\0';
				inputpassword(CP, 95, 340 + 30, 16, DARKGRAY);
				if (strlen(CP) != 0)
					state4 = 1;
				else
					state4 = 0;
				continue;
				//���뺯��

			}
		}
		if (mousex > 150 && mousex < 150 + 80 && mousey>480 - 10 - 40 && mousey < 480 - 10)
		{
			if (buttonpress(150, 480 - 10 - 40, 150 + 80, 480 - 10, mousex, mousey) && mousepress == 0)//��ɿ�δ���
			{
				if (num == 0)
				{
					//MouseS = 1;
					lightbutton_forget(150, 480 - 10 - 40, 150 + 80, 480 - 10, RED, LIGHTRED, 2);//��������
					num = 5;
				}
				continue;
			}
			else if (buttonpress(150, 480 - 10 - 40, 150 + 80, 480 - 10, mousex, mousey))//��ɿ���
			{
				//MouseS = 0;
				if (forgetpass_complete(U, I, NP, CP))
				{
					*func = 2;
					return;
				}
				else
				{
					continue;
				}
				//����Ƿ�����޸����벢¼�����ݿ�
				//�л�����¼����
			}
		}
		if (mousex > 640 - 100 - 130 && mousex < 640 - 150 && mousey>480 - 50 && mousey < 480 - 10)
		{
			if (buttonpress(640 - 100 - 130, 480 - 50, 640 - 150, 480 - 10, mousex, mousey) && mousepress == 0)//���ؿ�δ���
			{
				if (num == 0)
				{
					//MouseS = 1;
					lightbutton_forget(640 - 100 - 130, 480 - 50, 640 - 150, 480 - 10, BLUE, LIGHTBLUE, 3);
					num = 6;
				}
				continue;
				//��������
			}
			else if (buttonpress(640 - 100 - 130, 480 - 50, 640 - 150, 480 - 10, mousex, mousey))//���ؿ���
			{
				//MouseS = 0;
				*func = 2;
				//�л���¼����
				return;
			}
		}
		if (mousex > 320 - 40 && mousex < 320 + 40 && mousey>480 - 50 && mousey < 480 - 10)
		{
			if (buttonpress(320 - 40, 480 - 50, 320 + 40, 480 - 10, mousex, mousey) && mousepress == 0)//���ÿ�δ���
			{
				if (num == 0)
				{
					//MouseS = 1;
					lightbutton_forget(320 - 40, 480 - 50, 320 + 40, 480 - 10, CYAN, LIGHTCYAN, 4);
					num = 7;
				}
				continue;
				//��������
			}
			else if (buttonpress(320 - 40, 480 - 50, 320 + 40, 480 - 10, mousex, mousey))//���ؿ���
			{
				//MouseS = 0;
				cleardevice();
				draw_forgetpass();
				num = 0;
				state1 = 0;
				state2 = 0;
				state3 = 0;
				state4 = 0;
				U[0] = '\0';
				I[0] = '\0';
				NP[0] = '\0';
				CP[0] = '\0';
				//����
				continue;
			}
		}
		if (num != 0)
		{
			//MouseS = 0;
			if (state1 == 0)
			{
				recoverbutton_forget(1);
			}
			if (state2 == 0)
			{
				recoverbutton_forget(2);
			}
			if (state3 == 0)
			{
				recoverbutton_forget(3);
			}
			if (state4 == 0)
			{
				recoverbutton_forget(4);
			}
			if (num == 5 || num == 6 || num == 7)
			{
				recoverbutton_forget(num);//�ָ���ť��ɫ
			}
			num = 0;
		}
		//if (MouseS != 0)
		//{
			//MouseS = 0;
		//}
		drawmouse();
#ifdef _MSC_VER
		delay_ms(50);
#else
		delay(50);
#endif
	}
}

/*********************************************
FUNCTION:lightbutton_forget
DESCRIPTION������������水ť����
INPUT:x,y,x1,y1,color1,color2,flag
RETURN:��
***********************************************/
void lightbutton_forget(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	//clrmous(mousex, mousey);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//���߿�
	switch (flag)
	{
	case 1:
		break;
	case 2:
		drawtext(160, 440, "���", 24, 34, 34, RED);
		break;
	case 3:
		drawtext(420, 440, "����", 24, 34, 34, BLUE);
		break;
	case 4:
		drawtext(290, 440, "����", 24, 34, 34, CYAN);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}

/*********************************************
FUNCTION:recoverbutton_forget
DESCRIPTION������������水ť�ָ�
INPUT:status
RETURN:��
***********************************************/
void recoverbutton_forget(int status)
{
	//clrmous(mousex, mousey);
	setcolor(WHITE);
	if (status == 1 || status && mousepress == 0 || status == 3 || status == 4)
	{
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		setcolor(WHITE);
		setlinestyle(SOLID_LINE, 0, 1);
	}
	else if (status == 5)
	{
		setfillstyle(SOLID_FILL, RED);
	}
	else if (status == 6)
	{
		setfillstyle(SOLID_FILL, BLUE);
	}
	else if (status == 7)
	{
		setfillstyle(SOLID_FILL, CYAN);
	}
	switch (status)
	{
	case 1:
		bar(95, 130, 95 + 450, 130 + 30);
		rectangle(95, 130, 95 + 450, 130 + 30);
		break;
	case 2:
		bar(95, 180 + 30, 95 + 450, 180 + 60);
		rectangle(95, 180 + 30, 95 + 450, 180 + 60);
		break;
	case 3:
		bar(95, 260 + 30, 95 + 450, 260 + 60);
		rectangle(95, 260 + 30, 95 + 450, 260 + 60);
		break;
	case 4:
		bar(95, 340 + 30, 95 + 450, 340 + 60);
		rectangle(95, 340 + 30, 95 + 450, 340 + 60);
		break;
	case 5:
		bar(150, 480 - 10 - 40, 150 + 80, 480 - 10);
		rectangle(150, 480 - 10 - 40, 150 + 80, 480 - 10);
		drawtext(160, 440, "���", 24, 34, 34, WHITE);
		break;
	case 6:
		bar(640 - 100 - 130, 480 - 50, 640 - 150, 480 - 10);
		rectangle(640 - 100 - 130, 480 - 50, 640 - 150, 480 - 10);
		drawtext(420, 440, "����", 24, 34, 34, WHITE);
		break;
	case 7:
		bar(320 - 40, 480 - 50, 320 + 40, 480 - 10);
		rectangle(320 - 40, 480 - 50, 320 + 40, 480 - 10);
		drawtext(320 - 30, 440, "����", 24, 34, 34, WHITE);
		break;
	}
}

/*********************************************
FUNCTION:draw_forgetpass
DESCRIPTION���������������
INPUT:void
RETURN:��
***********************************************/
void draw_forgetpass(void)
{
	setbkcolor(WHITE);
	setfillstyle(SOLID_FILL, BLUE);
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

	drawtext(20, 65, "�����û���", 16, 20, 20, BLUE);
	drawtext(190, 65, "����ѧ��", 16, 20, 20, BLUE);
	drawtext(360, 65, "����������", 16, 20, 20, BLUE);
	drawtext(540, 65, "ȷ������", 16, 20, 20, BLUE);

	setfillstyle(SOLID_FILL, LIGHTGRAY);

	drawtext(95, 115, "�û���", 16, 20, 20, BLUE);
	bar(95, 130, 95 + 450, 130 + 30);

	drawtext(95, 180 + 15, "ѧ��", 16, 20, 20, BLUE);
	bar(95, 180 + 30, 95 + 450, 180 + 60);

	drawtext(95, 260 + 15, "����������", 16, 20, 20, BLUE);
	bar(95, 260 + 30, 95 + 450, 260 + 60);

	drawtext(95, 340 + 15, "ȷ��������", 16, 20, 20, BLUE);
	bar(95, 340 + 30, 95 + 450, 340 + 60);

	setfillstyle(SOLID_FILL, RED);
	bar(150, 480 - 10 - 40, 150 + 80, 480 - 10);
	drawtext(160, 440, "���", 24, 34, 34, WHITE);

	setfillstyle(SOLID_FILL, BLUE);
	bar(640 - 100 - 130, 480 - 50, 640 - 150, 480 - 10);
	drawtext(420, 440, "����", 24, 34, 34, WHITE);

	setfillstyle(SOLID_FILL, CYAN);
	bar(320 - 40, 480 - 50, 320 + 40, 480 - 10);
	drawtext(320 - 30, 440, "����", 24, 34, 34, WHITE);
}