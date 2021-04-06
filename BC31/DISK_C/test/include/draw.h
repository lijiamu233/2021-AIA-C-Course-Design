#ifndef _DRAW_H_
#define _DRAW_H_

void DrawBar(int x1, int y1, int x2, int y2, int color);
void drawletter(int x1, int y1, char c);
void DrawAlert(char s[][50], int line);
void DrawLine(int x1, int y1, int x2, int y2, int color);
void DrawHint(char* s);
void mydelay(int x);
void DrawPosition(int x, int y, int colortype);
#endif

