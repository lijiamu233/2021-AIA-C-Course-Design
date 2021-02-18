#ifndef _DATA_H_
#define _DATA_H_
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






#endif