#ifndef _INPUT_H_
#define _INPUT_H_
#include"./include/database.h"

int hz_input(int x1,int y1,int x2,int y2,char *s,int len,int color);
int input_method(int x,int y,char *str,int value,char *py) ;
char *itostr(int a,char *s);
void pyFrm(int x1,int y1,int x2,int y2);
int xouttextxy(int x,int y,char *s,int color);
void hz_int(int x1,int y1,int x2,int y2,char *s,int color);

#endif

