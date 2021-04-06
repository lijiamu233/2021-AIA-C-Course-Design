#ifndef _DRAWUSER_H_
#define _DRAWUSER_H_

#include"./include/database.h"

void control_drawuser(int* func,int* ber);
void drawmenuandmap(void);
void recoverbutton_drawuser(int num);
void lightbutton_drawuser(int x, int y, int x1, int y1, int color1, int color2, int flag);

#endif

