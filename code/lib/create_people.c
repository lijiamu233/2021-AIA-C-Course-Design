/*
		create_people.c
		Initial version: 2021.2.5
		Lastest version: 2021.2.5
		Author: ljm
*/
#include "../include/header.h"

/*
	PEOPLE* New()
	args: none
	return: a struct pointer with type PEOPLE
	purpose: create a new people unit in demonstration.
*/
PEOPLE* New()
{
	PEOPLE* Character;
	const char s[20] = "School of AIA";
	Character = (PEOPLE*)malloc(sizeof(PEOPLE));
	if (Character == NULL) return Character;
	Character->actionStatus = 1;
	Character->healthStatus = 0;
	Character->deleteStatus = 0;
	Character->outStatus = 1;
	Character->temperature = CreateTemperature();
	CreateTrace(Character->trace);
	CreateString(Character->name, 1);
	CreateString(Character->stuNumber, 2);
	strcpy(Character->school, s);
	return Character;
}

/*
	double CreateTemperature()
	args: none
	return: a random number with type double.
	purpose: create a random data stands for temperature.
	algorithm: Box-Muller
*/
double CreateTemperature()
{
	static double V1, V2, S;
	double X, U1, U2;
	static int phase = 0;
	if (phase == 0)
	{
		do {
			U1 = (double)rand() / RAND_MAX;
			U2 = (double)rand() / RAND_MAX;
			V1 = 2 * U1 - 1;
			V2 = 2 * U2 - 1;
			S = V1 * V1 + V2 * V2;
		} while (S >= 1 || S == 0);
		X = V1 * sqrt(-2 * log(S) / S);
	}
	else {
		X = V2 * sqrt(-2 * log(S) / S);
	}
	phase = 1 - phase;
	X = X * 0.3 + 36.5;
	return X;
}
/*
	void CreateTrace(int* p)
	args: a int pointer, the trace[] of people unit
	return: none
	propose: create random trace list of each unit.
*/
void CreateTrace(int* p)
{
	int bucket[10] = {0,0,0,0,0,0,0,0,0,0};
	int cnt = 1, randomnumber;
	while (cnt <= 6)
	{
		randomnumber = (int)rand() % 9 + 1;
		if (!bucket[randomnumber])
		{
			bucket[randomnumber] = 1;
			*p = randomnumber;
			p++;
			cnt++;
		}
	}
}

/*
	void CreateString(char* p, int type)
	args: p: a string pointer, the string will be create.
		  type: 1 for name, 2 for stuNumber.
	return: none
	propose: create random string for people unit.
*/
void CreateString(char* p, int type)
{
	char s[25];
	int i;
	if (type == 1)
	{
		for (i = 0; i < 9; i++)
			s[i] = rand() % 26 + 'a';
		s[9] = '\0';
	}
	else
	{
		s[0] = 'U'; s[1] = '2'; s[2] = '0'; s[3] = '2'; s[4] = '0';
		for (i = 5; i <= 9; i++)
			s[i] = rand() % 10 + '0';
		s[10] = '\0';
	}
	strcpy(p, s);
}