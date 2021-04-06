#include "./include/header.h"

extern int mousex, mousey, mousepress;

void CreatePeople(PEOPLE* people, int type, int id)
{
	people->actionStatus = 0;
	people->healthStatus = 0;
	people->id = id;
	people->ifSick = type;
	CreateString(people->name, 1);
	CreateString(people->stuNumber, 2);
	people->temperature = CreateTemperature(type);
	people->InSchool = 1;
	people->nowPosition = 7;
}

double CreateTemperature(int type)
{
	static double V1, V2, S;
	double X, U1, U2;
	static int phase = 0;
	if (phase == 0)
	{
		do {
			U1 = (double)rand() / RAND_MAX;
			U2 = (double)rand() / RAND_MAX;
			V1 = 2 * U1 - 1;
			V2 = 2 * U2 - 1;
			S = V1 * V1 + V2 * V2;
		} while (S >= 1 || S == 0);
		X = V1 * sqrt(-2 * log(S) / S);
	}
	else {
		X = V2 * sqrt(-2 * log(S) / S);
	}
	phase = 1 - phase;
	if (type == 0)
		X = X * 0.3 + 36.5;
	else
		X = X * 0.3 + 37.5;
	return X;
}

void CreateString(char* p, int type)
{
	char s[12];
	int i;
	if (type == 1)
	{
		for (i = 0; i < 9; i++)
			s[i] = rand() % 26 + 'a';
		s[9] = '\0';
	}
	else
	{
		s[0] = 'U'; s[1] = '2'; s[2] = '0'; s[3] = '2'; s[4] = '0';
		for (i = 5; i <= 9; i++)
			s[i] = rand() % 10 + '0';
		s[10] = '\0';
	}
	strcpy(p, s);
}

void CreateTrace(int p[])
{
	int bucket[10] = { 0,0,0,0,0,0,0,0,0,0};
	int cnt = 0, randomnumber;
	while (cnt <= 4)
	{
		randomnumber = (int)rand() % 9 + 1;
		if (!bucket[randomnumber] && randomnumber != 3 && randomnumber != 7)
		{
			bucket[randomnumber] = 1;
			p[cnt] = randomnumber;
			cnt++;
		}
	}
	p[5] = 7;
}

void DeletePeople(PEOPLE peoples[], int* peoplenumber, int id)
{
	int i;
	for (i = id + 1; i <= *peoplenumber; i++)
	{
		peoples[i - 1].actionStatus = peoples[i].actionStatus;
		peoples[i - 1].healthStatus = peoples[i].healthStatus;
		peoples[i - 1].ifSick = peoples[i].ifSick;
		strcpy(peoples[i - 1].name, peoples[i].name);
		strcpy(peoples[i - 1].stuNumber, peoples[i].stuNumber);
	}
	(*peoplenumber) --;
	for (i = 1; i < *peoplenumber; i++)
		peoples[i].id = i;
}
void EditPeople(int* peoplenumber, PEOPLE peoples[])
{
	while (1)
	{
		mousemove();
		if (mousex > 560 && mousex < 580 && mousey > 40 && mousey < 60) //关闭
		{
			if (buttonpress(560, 40, 580, 60, mousex, mousey) && mousepress == 0)
			{
				//lightbutton();
			}
			else if (buttonpress(560, 40, 580, 60, mousex, mousey))
			{
				return;
			}
		}
		if (mousex > 515 && mousex < 565 && mousey > 77 && mousey < 97 && *peoplenumber >= 1) //第1个删除
		{
			if (buttonpress(515, 77, 565, 97, mousex, mousey) && mousepress == 0)
			{
				//lightbutton();
			}
			else if (buttonpress(515, 77, 565, 97, mousex, mousey))
			{
				DeletePeople(peoples, peoplenumber, 1);
				DrawHint("删除成功");
				DrawDataPage(*peoplenumber, peoples);
				continue;
			}
		}
		if (mousex > 515 && mousex < 565 && mousey > 143 && mousey < 163 && *peoplenumber >= 2) //第2个删除
		{
			if (buttonpress(515, 143, 565, 163, mousex, mousey) && mousepress == 0)
			{
				//lightbutton();
			}
			else if (buttonpress(515, 143, 565, 163, mousex, mousey))
			{
				DeletePeople(peoples, peoplenumber, 2);
				DrawHint("删除成功");
				DrawDataPage(*peoplenumber, peoples);
				continue;
			}
		}
		if (mousex > 515 && mousex < 565 && mousey > 209 && mousey < 229 && *peoplenumber >= 3) //第3个删除
		{
			if (buttonpress(515, 209, 565, 229, mousex, mousey) && mousepress == 0)
			{
				//lightbutton();
			}
			else if (buttonpress(515, 209, 565, 229, mousex, mousey))
			{
				DeletePeople(peoples, peoplenumber, 3);
				DrawHint("删除成功");
				DrawDataPage(*peoplenumber, peoples);
				continue;
			}
		}
		if (mousex > 515 && mousex < 565 && mousey > 275 && mousey < 295 && *peoplenumber >= 4) //第4个删除
		{
			if (buttonpress(515, 275, 565, 295, mousex, mousey) && mousepress == 0)
			{
				//lightbutton();
			}
			else if (buttonpress(515, 275, 565, 295, mousex, mousey))
			{
				DeletePeople(peoples, peoplenumber, 4);
				DrawHint("删除成功");
				DrawDataPage(*peoplenumber, peoples);
				continue;
			}
		}
		if (mousex > 515 && mousex < 565 && mousey > 341 && mousey < 361 && *peoplenumber >= 5) //第5个删除
		{
			if (buttonpress(515, 341, 565, 361, mousex, mousey) && mousepress == 0)
			{
				//lightbutton();
			}
			else if (buttonpress(515, 341, 565, 361, mousex, mousey))
			{
				DeletePeople(peoples, peoplenumber, 5);
				DrawHint("删除成功");
				DrawDataPage(*peoplenumber, peoples);
				continue;
			}
		}
		if (mousex > 515 && mousex < 565 && mousey > 407 && mousey < 427 && *peoplenumber == 6) //第6个删除
		{
			if (buttonpress(515, 407, 565, 427, mousex, mousey) && mousepress == 0)
			{
				//lightbutton();
			}
			else if (buttonpress(515, 407, 565, 427, mousex, mousey))
			{
				DeletePeople(peoples, peoplenumber, 6);
				DrawHint("删除成功");
				DrawDataPage(*peoplenumber, peoples);
				continue;
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

void CloseWindows()
{
	while (1)
	{
		mousemove();
		if (mousex > 560 && mousex < 580 && mousey > 40 && mousey < 60) //关闭
		{
			if (buttonpress(560, 40, 580, 60, mousex, mousey) && mousepress == 0)
			{
				//lightbutton();
			}
			else if (buttonpress(560, 40, 580, 60, mousex, mousey))
			{
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
void InitOneDay(int peoplenumber, PEOPLE peoples[])
{
	int i;
	for (i = 1; i <= peoplenumber; i++)
	{
		CreateTrace(peoples[i].trace);
		peoples[i].temperature = CreateTemperature(peoples[i].ifSick);
	}
}

int DisplayButton(int x, int y)
{
	if (x > 152 && x < 188 && y > 10 && y < 30) return 1;
	if (x > 445 && x < 480 && y > 425 && y < 445) return 2;
	if (x > 340 && x < 375 && y > 50 && y < 70) return 3;
	if (x > 463 && x < 498 && y > 15 && y < 35) return 4;
	if (x > 492 && x < 528 && y > 310 && y < 330) return 5;
	if (x > 210 && x < 245 && y > 250 && y < 270) return 6;
	if (x > 580 && x < 615 && y > 10 && y < 30) return 7;
	if (x > 260 && x < 295 && y > 442 && y < 462) return 8;
	if (x > 455 && x < 490 && y > 145 && y < 165) return 9;
	return 0;
}

void InOutSchool(char* stuNumber, int Day, int NowTime, int In)
{
	char s[3][50], t[7];
	switch (NowTime)
	{
	case 0:
	{
		strcpy(t, "09:00");
		break;
	}
	case 1:
	{
		strcpy(t, "11:00");
		break;
	}
	case 2:
	{
		strcpy(t, "13:00");
		break;
	}
	case 3:
	{
		strcpy(t, "15:00");
		break;
	}
	case 4:
	{
		strcpy(t, "17:00");
		break;
	}
	case 5:
	{
		strcpy(t, "19:00");
		break;
	}
	case 6:
	{
		strcpy(t, "21:00");
		break;
	}
	}
	sprintf(s[0], "学号为%s的单位", stuNumber);
	sprintf(s[1], "于%d日%s", Day, t);
	if (!In)
		sprintf(s[2], "出校");
	else
		sprintf(s[2], "入校");
	DrawAlert(s, 3);
}