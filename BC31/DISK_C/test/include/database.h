#ifndef _DATABASE_H_
#define _DATABASE_H_

typedef struct userinfo
{
	char user[15];           //6-12λ���û���
	char ID[20];             //10λ��ѧ��
	char password[20];       //8-16λ������

}USER;	//��װ�û���Ϣ

typedef struct admininfo
{
	char user[15];//6-12λ������Ա�˺�
	char password[10];//8λ����
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
