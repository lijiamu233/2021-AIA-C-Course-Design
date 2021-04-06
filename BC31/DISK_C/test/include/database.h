#ifndef _DATABASE_H_
#define _DATABASE_H_

typedef struct userinfo
{
	char user[15];           //6-12位，用户名
	char ID[20];             //10位，学号
	char password[20];       //8-16位，密码

}USER;	//封装用户信息

typedef struct admininfo
{
	char user[15];//6-12位，管理员账号
	char password[10];//8位密码
}ADMIN;

typedef struct people {
	double temperature;
	int trace[7];
	char stuNumber[15];
	char name[20];
	int healthStatus;	//0: health; 1: close contact; 2: fever
	int actionStatus;	//0: can act; >0: number of actions to move
	int ifSick;	        //0: normol; 1: sick
	int id;             //The ID of each people unit
	int nowPosition;
	int InSchool;
}PEOPLE;

typedef struct building {
	char name[20];
	int visitor[85];
	int canIn;  //0: can visit; >0: number of actions to in
	int numVisitor;
}BUILDING;

#endif
