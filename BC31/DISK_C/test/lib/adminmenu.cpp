#include "./include/header.h"

extern int mousex, mousey, mousepress;
void AdminInitPage(int* func, PEOPLE peoples[], int* peoplenumber)
{
	int num = 0;
	delay(100);
	cleardevice();
	DrawInitMenu();
	DrawAdminMap();
	while (1)
	{
		mousemove();
		if (mousex > 20 && mousex < 100 && mousey > 420 - 225 && mousey < 420 - 225 + 30) // �����Ա
		{
			if (buttonpress(20, 100, 195, 225, mousex, mousey) && mousepress == 0)
			{
				//lightbutton()
			}
			else if (buttonpress(20, 100, 195, 225, mousex, mousey))
			{
				if (*peoplenumber >= 6)
				{
					DrawBar(213, 160, 426, 320, WHITE);
					drawtext(213 + 50, 160 + 72, "�Ѵﵽ��������", 16, 16, 32, BLACK);
					mydelay(1000);
					DrawAdminMap();
				}
				else
				{
					(*peoplenumber) ++;
					PEOPLE unit;
					CreatePeople(&unit, 0, *peoplenumber);
					//peoples[*peoplenumber].actionStatus = unit.actionStatus;
					//peoples[*peoplenumber].healthStatus = unit.actionStatus;
					//peoples[*peoplenumber].id = unit.id;
					//peoples[*peoplenumber].ifSick = unit.ifSick;
					peoples[*peoplenumber] = unit;
					DrawHint("��ӳɹ�");
					DrawAdminMap();
				}
				//lightbutton()

			}
		}
		if (mousex > 4 && mousex < 116 && mousey > 420 - 180 && mousey < 420 - 180 + 30) // ����쳣��Ա
		{
			if (buttonpress(4, 116, 240, 270, mousex, mousey) && mousepress == 0)
			{
				//lightbutton()
			}
			else if (buttonpress(4, 116, 240, 270, mousex, mousey))
			{
				if (*peoplenumber >= 6)
				{
					DrawBar(213, 160, 426, 320, WHITE);
					drawtext(213 + 50, 160 + 72, "�Ѵﵽ��������", 16, 16, 32, BLACK);
					mydelay(1000);
					DrawAdminMap();
				}
				else
				{
					(*peoplenumber)++;
					PEOPLE unit;
					CreatePeople(&unit, 1, *peoplenumber);
					peoples[*peoplenumber] = unit;
					DrawHint("��ӳɹ�");
					DrawAdminMap();
				}
				//lightbutton()
			}
		}
		if (mousex > 20 && mousex < 100 && mousey > 420 - 135 && mousey < 420 - 135 + 30) // �༭��Ա
		{
			if (buttonpress(20, 100, 285, 315, mousex, mousey) && mousepress == 0)
			{
				//lightbutton()
			}
			else if (buttonpress(20, 100, 285, 315, mousex, mousey))
			{
				//lightbutton()
				DrawDataPage(*peoplenumber, peoples);
				EditPeople(peoplenumber, peoples);
				DrawAdminMap();
			}
		}
		if (mousex > 20 && mousex < 100 && mousey > 420 - 90 && mousey < 420 - 90 + 30) // ��ʼ��ʾ
		{
			if (buttonpress(20, 100, 330, 360, mousex, mousey) && mousepress == 0)
			{
				//lightbutton()
			}
			else if (buttonpress(20, 100, 330, 360, mousex, mousey))
			{
				//lightbutton()
				*func = 7;
				return;
			}
		}
		if (mousex > 20 && mousex < 100 && mousey > 420 && mousey < 450) // �˳�
		{
			if (buttonpress(20, 100, 420, 450, mousex, mousey) && mousepress == 0)
			{
				//lightbutton()
			}
			else if (buttonpress(20, 100, 420, 450, mousex, mousey))
			{
				//lightbutton()
				*func = 0;
				return;
			}
		}
		drawmouse();
#ifdef _MSC_VER
		delay_ms(50);
#else
		delay(50);
#endif
	}
}
void AdminDisplayPage(int* func, PEOPLE peoples[],BUILDING buildings[], int peoplenumber)
{
	int num = 0;
	int NowTime = 0;
	int Day = 1;
	int i;
	int buttonnumber;
	char s[15][50];
	int cnt = 0;
	int px[10][7] = { {0, 0, 0, 0, 0, 0, 0},
					  {0, 142, 152, 162, 172, 182, 192},
					  {0, 412, 422, 432, 412, 422, 432},
					  {0, 272, 282, 292, 302, 312, 322},
					  {0, 452, 462, 472, 482, 492, 502},
					  {0, 454, 454, 454, 454, 454, 454},
					  {0, 167, 177, 187, 197, 207, 217},
					  {0, 567, 577, 587, 597, 607, 617},
					  {0, 300, 310, 320, 330, 340, 350},
					  {0, 626, 626, 626, 626, 626, 626}
					  };
	int py[10][7] = { {0, 0, 0, 0, 0, 0, 0},
					  {0, 77, 77, 77, 77, 77, 77},
					  {0, 412, 412, 412, 402, 402, 402},
					  {0, 91, 91, 91, 91, 91, 91},
					  {0, 91, 91, 91, 91, 91, 91},
					  {0, 232, 242, 252, 262, 272, 282},
					  {0, 331, 331, 331, 331, 331, 331},
					  {0, 91, 91, 91, 91, 91, 91},
					  {0, 432, 432, 432, 432, 432},
					  {0, 127, 137, 147, 157, 167, 177} };
	delay(100);
	cleardevice();
	DrawDisplayMenu(NowTime, Day);
	InitData(peoplenumber, peoples, buildings);
	DrawDisplayMap();
	for (i = 1; i <= peoplenumber; i++)
	{
		DrawPosition(px[peoples[i].nowPosition][i], py[peoples[i].nowPosition][i], peoples[i].healthStatus);
	}
	while (1)
	{
		mousemove();
		buttonnumber = DisplayButton(mousex, mousey);

		if (NowTime == 0)
		{
			InitOneDay(peoplenumber, peoples);
		}
		if (buttonnumber != 0)
		{
			if (mousepress == 0)
			{
				//lightbutton();
			}
			else
			{
				//BuildingData();
				cnt = 0;
				sprintf(s[cnt++], "��ǰ����:%s", buildings[buttonnumber].name);
				if (buildings[buttonnumber].canIn == 0)
					sprintf(s[cnt++], "����״̬:����");
				else
					sprintf(s[cnt++], "����״̬:����");
				sprintf(s[cnt++], "�����Ƿÿ�����");
				for (i = 1; i <= buildings[buttonnumber].numVisitor; i++)
				{
					sprintf(s[cnt++], "%s", peoples[buildings[buttonnumber].visitor[i]].stuNumber);
				}
				DrawAlert(s, cnt);
				//CloseWindows();
				DrawDisplayMap();
				for (i = 1; i <= peoplenumber; i++)
				{
					DrawPosition(px[peoples[i].nowPosition][i], py[peoples[i].nowPosition][i], peoples[i].healthStatus);
				}
				mydelay(250);
			}
		}
		if (mousex > 20 && mousex < 100 && mousey > 420 - 225 && mousey < 420 - 225 + 30) // �鿴����
		{
			if (buttonpress(20, 100, 195, 225, mousex, mousey) && mousepress == 0)
			{
				//lightbutton()
			}
			else if (buttonpress(20, 100, 195, 225, mousex, mousey))
			{
				//lightbutton()
				DrawDisplayDataPage(peoplenumber, peoples, buildings);
				CloseWindows();
				DrawDisplayMap();
				for (i = 1; i <= peoplenumber; i++)
				{
					DrawPosition(px[peoples[i].nowPosition][i], py[peoples[i].nowPosition][i], peoples[i].healthStatus);
				}
				mydelay(250);
			}
		}
		if (mousex > 20 && mousex < 100 && mousey > 420 - 180 && mousey < 420 - 180 + 30) // ��һ��
		{
			if (buttonpress(20, 100, 240, 270, mousex, mousey) && mousepress == 0)
			{
				//lightbutton()
			}
			else if (buttonpress(20, 100, 240, 270, mousex, mousey))
			{
				//lightbutton()
				DrawDisplayMenu(NowTime, Day);
				NowTime++;
				if (NowTime == 6)
				{
					mydelay(100);
					continue;
				}
				if (NowTime == 7)
				{
					NowTime = 0;
					Day++;
				}
				for (i = 1; i <= peoplenumber; i++)
				{
					if (peoples[i].actionStatus == 0)
					{
						if (peoples[i].trace[NowTime] != 8)  //��У��
						{
							if (peoples[i].InSchool == 0)
							{
								peoples[i].InSchool = 1;
								InOutSchool(peoples[i].stuNumber, Day, NowTime, 1);
								DrawDisplayMap();
								DrawDisplayMenu(NowTime, Day);
								mydelay(100);
							}
						}
						else
						{
							InOutSchool(peoples[i].stuNumber, Day, NowTime, 0);
							peoples[i].InSchool = 0;
							DrawDisplayMap();
							DrawDisplayMenu(NowTime, Day);
							mydelay(100);
						}
						VisitBuilding(peoples[i].trace[NowTime], i, buildings, peoples, NowTime);
					}
					else
					{
						peoples[i].actionStatus--;
						if (peoples[i].actionStatus == 0)
						{
							peoples[i].healthStatus = 0;
						}
					}
				}
				for (i = 1; i <= 9; i++)
				{
					if (buildings[i].canIn != 0)
						buildings[i].canIn--;
				}
				DrawDisplayMap();
				for (i = 1; i <= peoplenumber; i++)
				{
					DrawPosition(px[peoples[i].nowPosition][i],py[peoples[i].nowPosition][i], peoples[i].healthStatus);
				}
				mydelay(100);
				continue;
			}
		}
		if (mousex > 20 && mousex < 100 && mousey > 420 - 135 && mousey < 420 - 135 + 30) // ������ʾ
		{
			if (buttonpress(20, 100, 285, 315, mousex, mousey) && mousepress == 0)
			{
				//lightbutton()
			}
			else if (buttonpress(20, 100, 285, 315, mousex, mousey))
			{
				//lightbutton()
				*func = 6;
				return;
			}
		}
		if (mousex > 20 && mousex < 100 && mousey > 420 && mousey < 450) // �˳�
		{
			if (buttonpress(20, 100, 420, 450, mousex, mousey) && mousepress == 0)
			{
				//lightbutton()
			}
			else if (buttonpress(20, 100, 420, 450, mousex, mousey))
			{
				//lightbutton()
				*func = 0;
				return;
			}
		}

		drawmouse();
#ifdef _MSC_VER
		delay_ms(50);
#else
		delay(50);
#endif
	}
}
void DrawInitMenu()
{
	int x1 = 20, y1 = 420 - 225, y2 = 420 - 180, y3 = 420 - 135, y4 = 420 - 90, y5 = 420;
	DrawBar(0, 0, 120, 480, LIGHTBLUE);
	drawtext(x1 + 8, 60, "��ǰʱ��", 16, 16, 16, WHITE);
	drawtext(x1, 100, "δ��ʼ��ʾ", 16, 16, 16, WHITE);
	DrawBar(x1, y1, x1 + 80, y1 + 30, LIGHTGRAY);
	drawtext(x1 + 8, y1 + 7, "�����Ա", 16, 16, 16, BLACK);
	DrawBar(x1 - 16, y2, x1 + 96, y2 + 30, RED);
	drawtext(x1 - 8, y2 + 7, "����쳣��Ա", 16, 16, 16, WHITE);
	DrawBar(x1, y3, x1 + 80, y3 + 30, LIGHTGRAY);
	drawtext(x1 + 8, y3 + 7, "�༭��Ա", 16, 16, 16, BLACK);
	DrawBar(x1, y4, x1 + 80, y4 + 30, LIGHTGRAY);
	drawtext(x1 + 8, y4 + 7, "��ʼ��ʾ", 16, 16, 16, BLACK);
	DrawBar(x1, y5, x1 + 80, y5 + 30, RED);
	drawtext(x1 + 23, y5 + 7, "�˳�", 16, 16, 16, WHITE);
}

void DrawDisplayMenu(int NowTime, int Day)
{
	int x1 = 20, y1 = 420 - 225, y2 = 420 - 180, y3 = 420 - 135, y4 = 420;
	char s[7];
	char d[30];
	switch (NowTime)
	{
	case 0:
	{
		strcpy(s, "09:00");
		break;
	}
	case 1:
	{
		strcpy(s, "11:00");
		break;
	}
	case 2:
	{
		strcpy(s, "13:00");
		break;
	}
	case 3:
	{
		strcpy(s, "15:00");
		break;
	}
	case 4:
	{
		strcpy(s, "17:00");
		break;
	}
	case 5:
	{
		strcpy(s, "19:00");
		break;
	}
	case 6:
	{
		strcpy(s, "21:00");
		break;
	}
	}
	DrawBar(0, 0, 120, 480, LIGHTBLUE);
	sprintf(d, "��ǰ��%d��", Day);
	drawtext(x1 + 8, 60, d, 16, 16, 8, WHITE);
	drawtext(x1 + 4, 100, s, 16, 16, 16, WHITE);
	DrawBar(x1, y1, x1 + 80, y1 + 30, LIGHTGRAY);
	drawtext(x1 + 8, y1 + 7, "�鿴����", 16, 16, 16, BLACK);
	DrawBar(x1, y2, x1 + 80, y2 + 30, LIGHTGRAY);
	drawtext(x1 + 16, y2 + 7, "��һ��", 16, 16, 16, BLACK);
	DrawBar(x1, y3, x1 + 80, y3 + 30, LIGHTGRAY);
	drawtext(x1 + 8, y3 + 7, "������ʾ", 16, 16, 16, BLACK);
	DrawBar(x1, y4, x1 + 80, y4 + 30, RED);
	drawtext(x1 + 23, y4 + 7, "�˳�", 16, 16, 16, WHITE);
}

void DrawDataPage(int peoplenumber, PEOPLE peoples[])
{
	int kx = 185, ky = 45, i, ly = 106;
	char s[30];
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	DrawBar(180, 40, 580, 440, DARKGRAY);
	DrawBar(560, 40, 580, 60, RED);
	DrawLine(560 + 2, 40 + 2, 580 - 2, 60 - 2, WHITE);
	DrawLine(560 + 2, 60 - 2, 580 - 2, 40 + 2, WHITE);
	for (i = 1; i <= peoplenumber; i++)
	{
		sprintf(s, "��ţ�%d", i);
		drawtext(kx, ky, s, 16,16, 8, WHITE);
		sprintf(s, "ѧ�ţ�%s", peoples[i].stuNumber);
		drawtext(kx + 16 * 5, ky, s, 16, 16, 8, WHITE);
		sprintf(s, "������%s", peoples[i].name);
		drawtext(kx + 16 * 4 + 8 * 20, ky, s, 16, 16, 8, WHITE);
		sprintf(s, "���£�%.1lf", peoples[i].temperature);
		drawtext(kx, ky + 16 * 2, s, 16, 16, 8, WHITE);
		if (peoples[i].ifSick == 0)
			strcpy(s, "�Ƿ��쳣����");
		else
			strcpy(s, "�Ƿ��쳣����");
		drawtext(kx + 16 * 3 + 8 * 6, ky + 16 * 2, s, 16, 16, 8, WHITE);
		DrawBar(580 - 65, ky + 16 * 2, 580 - 15, ky + 16 * 2 + 20, RED);
		drawtext(580 - 65 + 9, ky + 16 * 2 + 2, "ɾ��", 16, 16, 8, WHITE);
		if (i <= peoplenumber - 1)
			DrawLine(180, ly, 580, ly, BLUE);
		ky += 66;
		ly += 66;
	}
}

void DrawDisplayDataPage(int peoplenumber, PEOPLE peoples[], BUILDING buildings[])
{
	int kx = 185, ky = 45, i, ly = 106;
	char s[50];
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	DrawBar(180, 40, 580, 440, DARKGRAY);
	DrawBar(560, 40, 580, 60, RED);
	DrawLine(560 + 2, 40 + 2, 580 - 2, 60 - 2, WHITE);
	DrawLine(560 + 2, 60 - 2, 580 - 2, 40 + 2, WHITE);
	for (i = 1; i <= peoplenumber; i++)
	{
		sprintf(s, "��ţ�%d", i);
		drawtext(kx, ky, s, 16, 16, 8, WHITE);
		sprintf(s, "ѧ�ţ�%s", peoples[i].stuNumber);
		drawtext(kx + 16 * 5, ky, s, 16, 16, 8, WHITE);
		sprintf(s, "������%s", peoples[i].name);
		drawtext(kx + 16 * 4 + 8 * 20, ky, s, 16, 16, 8, WHITE);
		sprintf(s, "���£�%.1lf", peoples[i].temperature);
		drawtext(kx, ky + 16 * 2, s, 16, 16, 8, WHITE);
		sprintf(s, "��ǰλ��: %s", buildings[peoples[i].nowPosition].name);
		drawtext(kx + 16 * 3 + 8 * 6, ky + 16 * 2, s, 16, 16, 8, WHITE);
		if (i <= peoplenumber - 1)
			DrawLine(180, ly, 580, ly, BLUE);
		ky += 66;
		ly += 66;
	}
}

void DrawAdminMap()
{

	DrawBar(120, 0, 640, 480, LIGHTCYAN);
	//��ͼ
	setcolor(YELLOW);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(320, 5, "H U S T     M A P");

	setfillstyle(1, GREEN);
	bar(560, 35, 630, 85);//����
	drawtext(575, 65, "����", 16, 17, 17, BLACK);

	bar(500, 125, 620, 185);//����ʵѵ����
	drawtext(515, 155, "����ʵѵ����", 16, 17, 17, BLACK);

	bar(450, 45, 510, 85);//ʳ��
	drawtext(465, 65, "ʳ��", 16, 17, 17, BLACK);

	bar(460, 220, 560, 300);//ͼ���
	drawtext(485, 255, "ͼ���", 16, 17, 17, BLACK);

	bar(140, 35, 200, 75);//УҽԺ
	drawtext(150, 45, "УҽԺ", 16, 17, 17, BLACK);

	setfillstyle(1, YELLOW);
	bar(250, 35, 330, 85);	//�����
	drawtext(260, 55, "�����", 16, 17, 17, BLACK);

	setfillstyle(1, BROWN);
	bar(380, 420, 440, 450);
	drawtext(380, 425, "У����", 16, 17, 17, BLACK);

	drawtext(300, 440, "У��", 24, 25, 25, BLACK);


	setcolor(BLUE);
	setfillstyle(1, BLUE);//���ż���
	fillellipse(320, 250, 50, 70);
	drawtext(320, 250, "��", 16, 17, 17, WHITE);
	setcolor(LIGHTGRAY);
	setfillstyle(1, LIGHTGRAY);
	int v[] = { 240,195,250,195,200,215,190 ,215,240,195 };
	fillpoly(5, v);
	bar(140, 155, 250, 195);
	bar(140, 215, 200, 255);
	bar(190, 255, 195, 265);
	bar(140, 265, 200, 305);
	bar(140, 325, 250, 365);
	int l[] = { 190,305,200,305,250,325,240,325 ,190,305 };
	fillpoly(5, l);
	drawtext(155, 165, "����¥", 16, 17, 17, BLACK);

	//·
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, 0, 1);
	drawtext(210, 100, "����·", 16, 17, 17, BLACK);
	line(120, 105, 639, 105);//���ŵ�·
	line(120, 115, 400, 115);
	line(410, 115, 639, 115);

	//���ŵ�·
	line(400, 115, 400, 420);

	line(410, 115, 410, 195);//���ŵ�һ��
	line(410, 205, 410, 420);
	line(410, 195, 639, 195);//���ŵ�·
	line(410, 205, 639, 205);
	drawtext(420, 195, "��Է·", 16, 17, 17, BLACK);

	setcolor(BLACK);//դ��
	setlinestyle(SOLID_LINE, 0, 3);
	line(120, 420, 639, 420);

}

void DrawDisplayMap()
{
	DrawAdminMap();

	DrawBar(152, 10, 188, 30, MAGENTA);
	drawtext(154, 12, "�鿴", 16, 16, 16, WHITE); //УҽԺ��ť

	DrawBar(445, 425, 480, 445, MAGENTA);
	drawtext(447, 427, "�鿴", 16, 16, 16, WHITE); //У���Ű�ť

	DrawBar(340, 50, 375, 70, MAGENTA);
	drawtext(342, 52, "�鿴", 16, 16, 16, WHITE); //����㰴ť

	DrawBar(463, 15, 498, 35, MAGENTA);
	drawtext(465, 17, "�鿴", 16, 16, 16, WHITE);  //ʳ�ð�ť

	DrawBar(492, 310, 528, 330, MAGENTA);
	drawtext(494, 312, "�鿴", 16, 16, 16, WHITE); //ͼ��ݰ�ť

	DrawBar(210, 250, 245, 270, MAGENTA);
	drawtext(212, 252, "�鿴", 16, 16, 16, WHITE); //���Ű�ť

	DrawBar(580, 10, 615, 30, MAGENTA);
	drawtext(582, 12, "�鿴", 16, 16, 16, WHITE); //���ᰴť

	DrawBar(260, 442, 295, 462, MAGENTA);
	drawtext(262, 444, "�鿴", 16, 16, 16, WHITE); //У�ⰴť

	DrawBar(455, 145, 490, 165, MAGENTA);
	drawtext(457, 147, "�鿴", 16, 16, 16, WHITE); //����ʵѵ���İ�ť
}

void InitData(int peoplenumber, PEOPLE peoples[], BUILDING buildings[])
{
	int i;
	for (i = 1; i <= 9; i++)
	{
		buildings[i].canIn = 0;
		buildings[i].numVisitor = 0;
	}
	for (i = 1; i <= peoplenumber; i++)
	{
		peoples[i].actionStatus = 0;
		peoples[i].nowPosition = 7;
	}
}
void lightbutton_admin_init(int x1, int y1, int x2, int y2, int color1, int color2);
void recoverbutton_admin_init();