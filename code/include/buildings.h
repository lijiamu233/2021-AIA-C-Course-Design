#ifndef _BUILDINGS_H_
#define _BUILDINGS_H_
typedef struct building {
	char name[20];
	int visitor[85];
	int canIn;
	int numVisitor;
}BUILDING;
int CheckTemperature(double Temperature);
void InitBuilding(BUILDING building[]);
void VisitBuilding(BUILDING* building, PEOPLE* people, BUILDING buildings[], PEOPLE peoples[], int nowTime);
#endif