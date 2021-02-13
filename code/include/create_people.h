#ifndef _CREATE_PEOPLE_H
#define _CREATE_PEOPLE_H

typedef struct people {
	double temperature;
	int trace[20];
	char stuNumber[15];
	char name[20];
	char school[60];
	int healthStatus;	//0: health; 1: close contact; 2: fever
	int actionStatus;	//0: can't act; 1: can act
	int deleteStatus;	//0: exist; 1: delete
	int outStatus;		//0: can't out; 1: can out
	int id;             //The ID of each people unit
}PEOPLE;

PEOPLE* New();
double CreateTemperature();
void CreateString(char* p, int type);
void CreateTrace(int* p);

#endif
