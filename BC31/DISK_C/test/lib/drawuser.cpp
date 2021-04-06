#include"./include/header.h"


extern int mousex, mousey, mousepress;


void control_drawuser(int* func,int* ber)
{
	int num = 0;	//button�����
	delay(100);
	cleardevice();
	drawmenuandmap();
	while (1)
	{
		mousemove();
		if (mousex > 10 && mousex < 110 && mousey > 280 && mousey < 320)
		{
			if (buttonpress(10, 280, 110, 320, mousex, mousey) && mousepress == 0)//�û�����δ���
			//��������Ϊ���ȵ�if��������Ϊ��������δ���֮ǰ������Ϊ��Ч������������ֱ���������У�
			{
				if (num == 0)
				{
					lightbutton_drawuser(10, 280, 110, 320, WHITE, LIGHTBLUE, 1);//color1Ϊ�߿�ɫ��color2Ϊ���ɫ
					num = 1;
				}
				continue;//��������
			}
			else if (buttonpress(10, 280, 110, 320,  mousex, mousey))//�û����е��ԤԼ��У
			{
				*func = 10;
				break;
			
			}
		}
		if (mousex > 10 && mousex < 110 && mousey > 220 && mousey < 260)
		{
			if (buttonpress(10, 220, 110, 260, mousex, mousey) && mousepress == 0)//�û�����δ���
			//��������Ϊ���ȵ�if��������Ϊ��������δ���֮ǰ������Ϊ��Ч������������ֱ���������У�
			{
				if (num == 0)
				{
					lightbutton_drawuser(10, 220, 110, 260, WHITE, LIGHTGREEN, 5);//color1Ϊ�߿�ɫ��color2Ϊ���ɫ
					num = 5;
				}
				continue;//��������
			}
			else if (buttonpress(10, 220, 110, 260, mousex, mousey))//�û����е���쳣�û�
			{
				*ber+= 1;
				return;

			}
		}
	
		if (mousex > 10 && mousex < 110 && mousey > 340 && mousey < 380)
		{
			if (buttonpress(10 , 340,110,380,  mousex, mousey) && mousepress == 0)//�û�����δ���
			{
				if (num == 0)
				{
					//MouseS = 1;
					lightbutton_drawuser(10, 340 ,110, 380, WHITE, LIGHTBLUE, 3);
					num = 3;
				}
				continue;//��������
			}
			else if (buttonpress(10, 340 ,110, 380, mousex, mousey))//�û����е����������
			{
				*func = 11;
				break;
			}
		}

		//���ټ�¼
		if (mousex > 10 && mousex < 110 && mousey > 400 && mousey < 440)
		{
			if (buttonpress(10, 400, 110, 440, mousex, mousey) && mousepress == 0)//�û�����δ���
			{
				if (num == 0)
				{
					//MouseS = 1;
					lightbutton_drawuser(10, 400, 110, 440, WHITE, LIGHTBLUE, 2);
					num = 2;
				}
				continue;//��������
			}
			else if (buttonpress(10, 400, 110, 440, mousex, mousey))//�û����е�����ټ�¼
			{

				*func = 12;
				break;
			}
		}


		if (mousex > 640 - 30 && mousex < 640 && mousey > 0 && mousey < 20)
		{
			if (buttonpress(640 - 30, 0, 640, 20, mousex, mousey) && mousepress == 0)//�˳���ť
			{
				if (num == 0)
				{
					lightbutton_drawuser(640 - 30, 20, 640, 0, RED, RED, 4);
					num = 4;
				}
				continue;//��������
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
			drawtext(15, 235, "�����û�", 16, 17, 17, WHITE);
		}
		else
		{
			setfillstyle(1, RED);
			bar(10, 220, 110, 260);
			drawtext(15, 235, "�쳣�û�", 16, 17, 17, WHITE);
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
	rectangle(x, y, x1, y1);	//���߿�
	switch (flag)
	{
	case 1:
		drawtext(15, 295, "ԤԼ��У", 16, 17, 17, LIGHTGRAY);
		break;
	case 2:
		drawtext(15, 415, "���ټ�¼", 16, 17, 17, LIGHTGRAY);
		break;
	case 3:
		drawtext(15, 355, "��������", 16, 17, 17, LIGHTGRAY);
		break;
	case 5:
		drawtext(15, 235, "�����û�", 16, 17, 17, LIGHTGRAY);
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
		drawtext(15, 295, "ԤԼ��У", 16, 17, 17, WHITE);
	case 2:
		rectangle(10, 400, 110, 440);
		bar(10, 400, 110, 440);
		drawtext(15, 415, "���ټ�¼", 16, 17, 17, WHITE);
	case 3:
		rectangle(10, 340 ,110, 380 );
		bar(10, 340 ,110, 380 );
		drawtext(15, 355, "��������", 16, 17, 17, WHITE);
	case 5:
		setfillstyle(1, GREEN);
		setcolor(GREEN);
		setlinestyle(SOLID_LINE, 0, 3);
		bar(10, 220, 110, 260);
		drawtext(15, 235, "�����û�", 16, 17, 17, WHITE);
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






void drawmenuandmap(void) // ������ҳ��
{
	//����ҳ�漰��ť
	setbkcolor(BLACK);
	setcolor(BLUE);
	setlinestyle(SOLID_LINE, 0, 1);
	line(120, 0, 120, 480);
	line(120, 20, 639, 20);

	setfillstyle(1, DARKGRAY);
	bar(0, 0, 120, 480);

	drawtext(15, 65, "ʱ��", 16, 17, 17, WHITE);
	setcolor(YELLOW);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(10, 150, "2021.5.6");

	setfillstyle(1, GREEN);
	bar(10, 220, 110, 260);
	drawtext(15, 235, "�����û�", 16, 17, 17, WHITE);

	setfillstyle(1, BLUE);
	bar(10, 280, 110, 320);
	drawtext(15, 295, "ԤԼ��У", 16, 17,17, WHITE);

	bar(10, 340, 110, 380);
	drawtext(15, 355, "��������", 16, 17, 17, WHITE);

	bar(10, 400, 110, 440);
	drawtext(15, 415, "���ټ�¼", 16, 17, 17, WHITE);

	//��ͼ
	setcolor(YELLOW);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(320, 5, "H U S T     M A P");

	setfillstyle(1, GREEN);
	bar(560, 35, 630, 85);//����
	drawtext(575, 65, "����", 16, 17, 17, LIGHTGRAY);

	bar(500, 125, 620, 185);//����ʵѵ����
	drawtext(515, 155, "����ʵѵ����", 16, 17, 17,  LIGHTGRAY);

	bar(460, 45, 500, 85);//ʳ��
	drawtext(465, 65, "ʳ��", 16, 17, 17, LIGHTGRAY);

	bar(460,220,560,300);//ͼ���
	drawtext(485, 255, "ͼ���", 16, 17, 17, LIGHTGRAY);

	bar(140,35,200,75);//УҽԺ
	drawtext(150, 45, "УҽԺ", 16, 17, 17, LIGHTGRAY);

	setfillstyle(1, YELLOW);
	bar(250,35,330,85);	//�����
	drawtext(260, 55, "�����", 16, 17, 17, LIGHTGRAY);

	setfillstyle(1, BROWN);
	bar(380, 420, 440, 450);
	drawtext(380, 425, "У����", 16, 17, 17, LIGHTGRAY);

	drawtext(300, 440, "У��",24, 25, 25, LIGHTGRAY);


	setcolor(BLUE);
	setfillstyle(1, BLUE);//���ż���
	fillellipse(320, 250, 50, 70);
	drawtext(320, 250, "��", 16, 17, 17, LIGHTGRAY);
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
	drawtext(155, 165, "����", 16, 17, 17, WHITE);

	//·
	setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, 1);
	drawtext(210, 100, "����·", 16, 17, 17, LIGHTGRAY);
	line(120,105,639,105);//���ŵ�·
	line(120,115,400,115);
	line(410,115,639,115);
	
	//���ŵ�·
	line(400,115,400,420);

	line(410,115,410,195);//���ŵ�һ��
	line(410,205,410,420);
	line(410,195,639,195);//���ŵ�·
	line(410,205,639,205);
	drawtext(420, 195, "��Է·", 16, 17, 17, LIGHTGRAY);

	setcolor(WHITE);//դ��
	setlinestyle(SOLID_LINE, 0, 3);
	line(120,420,639,420);
	





	setfillstyle(1, WHITE);	//�˳���ť
	bar(640 - 30, 20, 640, 0);
	setlinestyle(SOLID_LINE, 0, 1);
	setcolor(RED);
	line(640 - 25, 2, 640 - 5, 2 + 16);
	line(640 - 25, 2 + 16, 640 - 5, 2);

}
	
