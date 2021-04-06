#ifndef _HZK_H_
#define _HZK_H_

#ifndef __BORLANDC__
#define settextstyle(x,y,z)   setfont(-z*2,0,"Arial")
#endif

void drawtext(int x, int y, char* s, int fontsize, int spaceChinese, int spaceEnglish, int color);
void DrawChar(int x, int y, char c);
#endif
