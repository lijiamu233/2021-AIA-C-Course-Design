#ifndef _LGFUNC_H_
#define _LGFUNC_H_
#include "./include/database.h"

//����Ա����Ƿ�ƥ��
int admin_judge(char* admin, char* pass);

void inputadmin(char* id, int x1, int y1, int charnum, int color);
//x1,y1�ֱ����˺ţ���֤���������Ϣ����˵���϶˵�

void inputpassword(char* id, int x1, int y1, int charnum, int color);
//x1,y1�ֱ��������������Ϣ�������˵���϶˵�

int login_complete(char* u, char* p);
//�����жϵ�¼��Ϣ�Ƿ�������ȫ����ȷ

int forgetpass_complete(char* u, char* id, char* np, char* cp);
//����Ƿ���Ը���������

int judge_rightpassword(char* name, char* pass);
//�û����������Ƿ�ƥ��

int name_id(char* name, char* id, char* pass, char* againpass);
//�ж��˺������֤�Ƿ�ƥ�䣬���ж���������������Ƿ���ͬ����ƥ������ͬ��д�������롣

int register_complete(char* u, char* p, char* cp, char* id, char* vc, char* rdvc);
//�����ж�ע����Ϣ�Ƿ�������ȫ����ȷ

void judge(char* str, int* state, int x, int y);
//�ж�ע���״̬

void recoverhz(int x, int y, int color);
//����֮ǰ����ĺ���

int judge_sameuser(char* new_user, int flag);
//�ж��˻��Ƿ��������,�Լ��һ�����ʱ�ж��û����Ƿ����     1Ϊ

int checkright_user(char* str, int x, int y);
//����û����Ƿ����6λ

int checkright_password(char* str, int x, int y);
//����û����Ƿ����6λ

int checkright_confirmedpassword(char* str1, char* str2, int x, int y);
//���ȷ�������Ƿ�һ��

int checkright_ID(char* str, int x, int y, int flag);
//������֤λ�����ʽ

int checkright_verificationcode(char* str1, char* str2, int x, int y);
//�����֤���Ƿ�һ��

void input_database(char* name, char* id, char* code);
//���û�ע����Ϣд���ļ�

int input_uinfo(USER* us);
//��½����û���Ϣ����u

#endif