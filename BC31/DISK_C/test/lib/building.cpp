#include "./include/header.h"

void VisitBuilding(int buildingID, int peopleID, BUILDING buildings[], PEOPLE peoples[], int NowTime)
{
	int i, cnt, flag = 0;
	char s[9][50];
	if (buildings[buildingID].canIn > 0)
	{
		return;
	}
	if (peoples[peopleID].temperature >= 37.3)
	{
		sprintf(s[0], "ѧ��Ϊ%s���û�", peoples[peopleID].stuNumber);
		sprintf(s[1], "��%s���������쳣", buildings[buildingID].name);
		sprintf(s[2], "����ֵΪ%.1lf", peoples[peopleID].temperature);
		sprintf(s[3], "������УҽԺ");
		DrawAlert(s, 4);
		DrawAdminMap();
		mydelay(500);

		peoples[peopleID].healthStatus = 2;
		peoples[peopleID].actionStatus = 42;
		peoples[peopleID].ifSick = 0;
		peoples[peopleID].nowPosition = 1;
		buildings[buildingID].canIn = 18;

		if (buildings[buildingID].numVisitor >= 1 && buildingID != 1)
		{
			sprintf(s[0], "���µ��ù�%s����Ա", buildings[buildingID].name);
			sprintf(s[1], "�����Ϊ���нӴ���");
			cnt = 2;
			for (i = 1; i <= buildings[buildingID].numVisitor; i++)
			{
				if (peoples[buildings[buildingID].visitor[i]].healthStatus == 0)
				{
					peoples[buildings[buildingID].visitor[i]].healthStatus = 1;
					peoples[buildings[buildingID].visitor[i]].actionStatus = 18;
					peoples[buildings[buildingID].visitor[i]].nowPosition = 3;
					sprintf(s[cnt++], "%s", peoples[peopleID].stuNumber);
				}
			}
			sprintf(s[cnt++], "�����������");
			DrawAlert(s, cnt);
			DrawDisplayMap();
			mydelay(500);
		}
	}
	else
	{
		for (i = 1; i <= buildings[buildingID].numVisitor; i++)
		{
			if (buildings[buildingID].visitor[i] == peopleID)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			buildings[buildingID].numVisitor++;
			buildings[buildingID].visitor[buildings[buildingID].numVisitor] = peopleID;
		}
		peoples[peopleID].nowPosition = buildingID;
	}
}