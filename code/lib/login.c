#include"./include/public.h"
#include"./include/login.h"
#include"./include/lgfunc.h"


void user_login(int *func,USER *u)
{
	int num;
	//char U[15] = {'\0'};6-12λ���û���
	//char P[20] = {'\0'};8-16λ������
	//int state1=0;	//���������Ƿ������state
	int state1 = 0;
	int state2 = 0;
	memset(u,'\0',sizeof(USER));   //���𴦴�������u����
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawlogin();

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 260 && MouseX < 260 + 315 && MouseY>190 && MouseY < 220)
		{
			if (mouse_press(260, 190, 260 + 315, 220) == 2)//�û�����δ���
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)//��ֹ���ظ�����
				{
					lightbutton_login(260, 190, 260 + 315, 220, LIGHTRED, LIGHTGRAY, 1);//color1Ϊ�߿�ɫ��color2Ϊ���ɫ
					num = 1;
				}
				continue;

				//��������
			}
			else if (mouse_press(260, 190, 260 + 315, 220) == 1)//�û�������
			{
				MouseS = 0;
				lightbutton_login(260, 190, 260 + 315, 220, LIGHTRED, LIGHTGRAY, 1);
				u->user[0] = '\0';
				inputadmin(u->user, 260, 190, 12, LIGHTGRAY);
				//���뺯��
				if(strlen(u->user) != 0)
					state1 = 1;
				else 
					state1 = 0;
				continue;
			}
			
		}
		if (MouseX > 260 && MouseX < 260 + 315 && MouseY>250 && MouseY < 280)
		{
			if (mouse_press(260, 250, 260 + 315, 280) == 2)//�����δ���
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightbutton_login(260, 250, 260 + 315, 280, LIGHTRED, LIGHTGRAY, 1);//��������
					num = 2;
				}
				continue;
			}
			else if (mouse_press(260, 250, 260 + 315, 280) == 1)//�������
			{
				MouseS = 0;
				lightbutton_login(260, 250, 260 + 315, 280, LIGHTRED, LIGHTGRAY, 1);
				u->password[0] = '\0';
				inputpassword(u->password, 260, 250, 16, LIGHTGRAY);
				//���뺯��
				if(strlen(u->password) != 0)
					state2 = 1;
				else 
					state2 = 0;
				continue;
			}
		}
		if (MouseX > 260 && MouseX < 380 && MouseY>310 && MouseY < 345)
		{
			if (mouse_press(260, 310, 380, 345) == 2)//��¼��δ���
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(260, 310, 380, 345, WHITE, LIGHTRED, 2);//��������
					num = 3;
				}
				continue;
			}
			else if (mouse_press(260, 310, 380, 345) == 1)//��¼����
			{
				MouseS = 0;
				if (login_complete(u->user, u->password))     //��Ϣ��ȷ
				{
					if (input_uinfo(u))  //����Ϣ����uָ��
					{
						*func = 6;
						return;
					}
					else
					{
						printf("something wrong");
						delay(3000);
						exit(1);
					}
				}
				else
				{
					continue;
				}
				//����¼״̬����
			}
		}
		if (MouseX > 100 && MouseX < 169 && MouseY>380 && MouseY < 405)
		{
			if (mouse_press(100, 380, 169, 405) == 2)//���ؿ�δ���
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(100, 380, 169, 405, BLUE, LIGHTGRAY, 3);//��������
					num = 4;
				}
				continue;
			}
			else if (mouse_press(100, 380, 169, 405) == 1)//���ؿ���
			{
				MouseS = 0;
				*func = 0;
				//����initmenu����
				return;
			}
		}
		if (MouseX > 290 && MouseX < 350 && MouseY>380 && MouseY < 405)
		{
			if (mouse_press(290, 380, 350, 405) == 2)//ע���δ���
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(290, 380, 350, 405, BLUE, LIGHTGRAY, 4);//��������
					num = 5;
				}
				continue;
			}
			else if (mouse_press(290, 380, 350, 405) == 1)//ע�����
			{
				MouseS = 0;
				*func = 3;
				return;
				//�л���ע�����
			}
		}
		if (MouseX > 480 && MouseX < 570 && MouseY> 380 && MouseY < 405)
		{
			if (mouse_press(480, 380, 570, 405) == 2)//��������δ���
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(480, 380, 570, 405, BLUE, LIGHTGRAY, 5);
					num = 6;
				}
				continue;
				//��������
			}
			else if (mouse_press(480, 380, 570, 405) == 1)//����������
			{
				MouseS = 0;
				*func = 4;
				//�л������������
				return;
			}
		}
		if (num != 0)
		{
			MouseS = 0;
			if (state1 == 0)
			{
				recoverbutton_login(1);//�ָ���ť��ɫ
			}
			if (state2 == 0)
			{
				recoverbutton_login(2);
			}
			if (num == 3 || num == 4 || num == 5 || num == 6)
			{
				recoverbutton_login(num);
			}
			num = 0;
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}


void lightbutton_login(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//���߿�
	switch (flag)
	{
	case 1:
		break;
	case 2:
		puthz(290, 315, "��¼", 24, 34, RED);
		break;
	case 3:
		puthz(114, 385, "����", 16, 24, BLUE);
		break;
	case 4:
		puthz(302, 385, "ע��", 16, 24, BLUE);
		break;
	case 5:
		puthz(492, 385, "��������", 16, 18, BLUE);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}


void recoverbutton_login(int status)
{
	clrmous(MouseX, MouseY);	
	if (status == 1 || status == 2)
	{
		setfillstyle(SOLID_FILL, WHITE);
		setcolor(RED);
		setlinestyle(SOLID_LINE, 0, 3);
	}
	else if (status == 3)
	{
		setfillstyle(SOLID_FILL, RED);
	}
	else
	{
		setfillstyle(SOLID_FILL, WHITE);
		setlinestyle(SOLID_LINE, 0, 1);
		setcolor(LIGHTRED);
	}
	switch (status)
	{
	case 1:
		bar(260, 190, 260 + 315, 220);
		rectangle(260, 190, 260 + 315, 220);
		puthz(153, 193, "�û���", 24, 34, LIGHTRED);
		break;
	case 2:
		bar(260, 250, 260 + 315, 280);
		rectangle(260, 250, 260 + 315, 280);
		puthz(163, 253, "����", 24, 50, LIGHTRED);
		break;
	case 3:
		setfillstyle(SOLID_FILL, RED);
		bar(260, 310, 380, 345);
		puthz(290, 315, "��¼", 24, 34, WHITE);
		break;
	case 4:
		bar(100, 380, 169, 405);
		rectangle(100, 380, 169, 405);
		puthz(114, 385, "����", 16, 24, LIGHTRED);
		break;
	case 5:
		bar(290, 380, 350, 405);
		rectangle(290, 380, 350, 405);
		puthz(302, 385, "ע��", 16, 24, LIGHTRED);
		break;
	case 6:
		bar(480, 380, 570, 405);
		rectangle(480, 380, 570, 405);
		puthz(492, 385, "��������", 16, 18, LIGHTRED);
		break;
	}
}

/*********************************************
DESCRIPTION�������û���¼����

***********************************************/
void drawlogin(void)
{
	setbkcolor(BLACK);
	setfillstyle(1, BLUE);
	bar(0, 0, 640, 50);
	puthz(20, 10, "��У����ϵͳ", 24, 34, LIGHTGRAY);
	setfillstyle(1, LIGHTBLUE);

	setcolor(LIGHTBLUE);
	setlinestyle(SOLID_LINE, 0, 2);
	line(0, 120, 640, 120);
	line(0, 0, 0, 120);
	line(639, 0, 639, 120);
	outtextxy(300, 100, "AIA");




	setfillstyle(SOLID_FILL, WHITE);
	bar(140, 190, 260, 220);
	bar(260, 190, 260 + 315, 220);	//�˺ſ�

	bar(140, 250, 260, 280);
	bar(260, 250, 260 + 315, 280);	//�����

	setfillstyle(1, WHITE);
	sector(102, 203, 230, 310, 15, 15);
	fillellipse(102, 203 - 2, 7, 7);
	setcolor(WHITE);
	circle(102, 203 - 2, 7);//����¼С��2

	setcolor(LIGHTGRAY);
	rectangle(89, 260, 115, 275);
	arc(102, 260, 0, 180, 7);
	circle(102, 267, 4);//����

	setcolor(RED);
	setlinestyle(SOLID_LINE, 0, 3);
	line(260, 190, 260, 220);
	line(260, 250, 260, 280);	
	rectangle(140, 190, 260 + 315, 220);
	rectangle(140, 250, 260 + 315, 280);	//���û���������ı߿�

	puthz(153, 193, "�û���", 24, 34, LIGHTRED);
	puthz(163, 253, "����", 24, 50, LIGHTRED);

	setfillstyle(SOLID_FILL, RED);
	bar(260, 310, 380, 345);
	puthz(290, 315, "��¼", 24, 34, WHITE);//��¼��

	setlinestyle(SOLID_LINE, 0, 1);
	setfillstyle(SOLID_FILL, WHITE);
	bar(290, 380, 350, 405);
	puthz(302, 385, "ע��", 16, 24, LIGHTRED);
	setlinestyle(SOLID_LINE, 0, 2);
	setcolor(LIGHTRED);
	rectangle(290, 380, 350, 405);//ע���

	bar(100, 380, 169, 405);
	puthz(114, 385, "����", 16, 24, LIGHTRED);//���ؿ�
	rectangle(100, 380, 169, 405);

	bar(480, 380, 570, 405);
	puthz(492, 385, "��������", 16, 18, LIGHTRED);//���������
	rectangle(480, 380, 570, 405);




}