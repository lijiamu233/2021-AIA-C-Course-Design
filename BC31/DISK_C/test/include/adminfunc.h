#ifndef _ADMINFUNC_H_
#define _ADMINFUNC_H_

void CreatePeople(PEOPLE* people, int type, int id);
double CreateTemperature(int Type);
void CreateString(char* s, int type);
void CreateTrace(int p[]);
void EditPeople(int* peoplenumber, PEOPLE peoples[]);
void InitOneDay(int peoplenumber, PEOPLE peoples[]);
int DisplayButton(int x, int y);
void InOutSchool(char* stuNumber, int Day, int NowTime,int In);
void CloseWindows();
#endif

