#include "./include/header.h"

extern int mousex, mousey, mousepress;
void DrawBar(int x1, int y1, int x2, int y2, int color)
{
	setfillstyle(1, color);
	bar(x1, y1, x2, y2);
}

void drawletter(int x1, int y1, char c)
{
	char str[2];
	str[0] = c;
	str[1] = '\0';
	settextstyle(2, 0, 7);
	outtextxy(x1, y1, str);
	settextstyle(2, 0, 5);
}

void DrawLine(int x1, int y1, int x2, int y2, int color)
{
	setcolor(color);
	line(x1, y1, x2, y2);
}

void DrawAlert(char s[][50], int line)
{
	int i, y = 105;
	int x1 = 163, y1 = 87;
	int x2 = 290, y2 = 350;
	DrawBar(x1, y1, x1 + 300, y1 + 300, DARKGRAY);
	DrawBar(x2, y2, x2 + 50, y2 + 30, RED);
	drawtext(x2 + 10, y2 + 6, "¹Ø±Õ", 16, 16, 16, WHITE);
	for (i = 0; i < line; i++)
	{
		drawtext(180, y, s[i], 16, 16, 16, WHITE);
		y += 20;
	}
	while (1)
	{
		mousemove();
		if (mousex > x2 && mousex < x2 + 50 && mousey > y2 && mousey < y2 + 30)
		{
			if (mousepress)
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

void DrawHint(char* s)
{
	DrawBar(213, 160, 426, 320, WHITE);
	drawtext(213 + 42, 160 + 64, s, 32, 32, 32, BLACK);
	mydelay(1000);
}
void mydelay(int x)
{
#ifdef __BORLANDC__
	sleep(x / 1000);
#else
	Sleep(x);
#endif
}

void DrawPosition(int x, int y, int colortype)
{
	if (colortype == 0)
		DrawBar(x, y, x + 6, y + 6, GREEN);
	else if (colortype == 1)
		DrawBar(x, y, x + 6, y + 6, YELLOW);
	else if (colortype == 2)
		DrawBar(x, y, x + 6, y + 6, RED);
}