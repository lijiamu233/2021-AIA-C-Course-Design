#include "../include/header.h"

int CheckTemperature(double Temperature)
{
	if (Temperature >= 37.3)
		return 1;
	return 0;
}
void InitBuilding(BUILDING building[])
{
	int i;
	strcpy(building[1].name, "校医院");
	strcpy(building[2].name, "校大门");
	strcpy(building[3].name, "隔离点");
	strcpy(building[4].name, "食堂");
	strcpy(building[5].name, "图书馆");
	strcpy(building[6].name, "教学楼");
	strcpy(building[7].name, "宿舍");
	strcpy(building[8].name, "校外");
	strcpy(building[9].name, "工程实训中心");
	for (i = 1; i <= 9; i++)
	{
		building[i].canIn = 1;
		building[i].numVisitor = 0;
	}
}
void VisitBuilding(BUILDING* building, PEOPLE* people, BUILDING buildings[], PEOPLE peoples[], int nowTime)
{
	int i;

	if (building->canIn == 0) return;
	if (CheckTemperature(people->temperature) == 0)
	{
		for (i = 0; i < building->numVisitor; i++)
		{
			if(peoples[building->visitor[i]].healthStatus == 0)
				peoples[building->visitor[i]].healthStatus = 1;
		}
		for (i = 0; i < nowTime; i++)
		{
			buildings[people->trace[i]].canIn = 0;
		}
		building->canIn = 0;
		people->healthStatus = 2;
	}
	building->visitor[++building->numVisitor] = people->id;
	//movePeople();
}
