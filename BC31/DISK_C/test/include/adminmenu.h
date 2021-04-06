#ifndef _ADMINMENU_H
#define _ADMINMENU_H

void DrawAdminMap();
void DrawInitMenu();
void DrawDisplayMenu(int NowTime, int Day);
void AdminInitPage(int* func, PEOPLE peoples[], int* peoplenumber);
void AdminDisplayPage(int* func, PEOPLE peoples[], BUILDING buildings[], int peoplenumber);
void DrawDataPage(int peoplenumber, PEOPLE peoples[]);
void DrawDisplayMap();
void DrawDisplayDataPage(int peoplenumber, PEOPLE peoples[], BUILDING buildings[]);
void InitData(int peoplenumber, PEOPLE peoples[], BUILDING buildings[]);
#endif