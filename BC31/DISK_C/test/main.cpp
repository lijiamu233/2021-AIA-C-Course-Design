#include "./include/header.h"

extern int mousex, mousey, mousepress;
int main()
{
	int gd = VGA, gm = VGAHI;
	int func = 0;//lingshishiyong
	int ber = 0;
	int peoplenumber = 0;
	USER u;
	PEOPLE people[7];
	BUILDING building[10];
	int i;
	strcpy(building[1].name, "УҽԺ");
	strcpy(building[2].name, "У����");
	strcpy(building[3].name, "�����");
	strcpy(building[4].name, "ʳ��");
	strcpy(building[5].name, "ͼ���");
	strcpy(building[6].name, "����¥");
	strcpy(building[7].name, "����");
	strcpy(building[8].name, "У��");
	strcpy(building[9].name, "����ʵѵ����");
	for (i = 1; i <= 9; i++)
	{
		building[i].canIn = 0;
		building[i].numVisitor = 0;
	}
	initgraph(&gd, &gm, "C:\\BORLANDC\\BGI");
	mouseinit();
	while (1)
	{
		mousemove();
		switch (func)
		{
		case 0:		//��ʼ��ѡ�����
		{
			initmenu_set(&func);    //��ı�func��ֵ����
			//while (1);
			memset(&u, '\0', sizeof(USER));
			for (i = 1; i <= 9; i++)
			{
				building[i].canIn = 0;
				building[i].numVisitor = 0;
			}
			peoplenumber = 0;
			break;                  //Ҳ���ص�����ͳ�Ϊ�޵�¼״̬
		}
		case 1:		//�˳���ť
			delay(1000);
			closegraph();
			exit(1);
		case 2:		//�û���¼����
			user_login(&func, &u);
			break;
		case 3:		//�û�ע�����
			user_register(&func);
			break;
		case 4:		//�����������
			user_forgetpass(&func);
			break;
		case 5:		//����Ա��¼����
			admin_login(&func);
			break;
		case 6:
			AdminInitPage(&func, people, &peoplenumber); //����Ա��ʼ����
			break;
		case 7:
			AdminDisplayPage(&func, people, building, peoplenumber); //����Ա��ʾ����
			break;
		case 8:
			control_drawuser(&func,&ber);//�û��������
			break;
		case 10:
			yuyue(&func,&ber);//ԤԼ��У����
			break;
		case 11:

			yuyuecar(&func,&ber);//��������ԤԼ����
			break;
		case 12:

			jilu(&func,&ber);//���ټ�¼����
			break;
		}
		drawmouse();
#ifdef _MSC_VER
		delay_ms(50);
#else
		delay(50);
#endif
	}
	return 0;
}