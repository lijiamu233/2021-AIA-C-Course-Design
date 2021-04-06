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
	strcpy(building[1].name, "校医院");
	strcpy(building[2].name, "校大门");
	strcpy(building[3].name, "隔离点");
	strcpy(building[4].name, "食堂");
	strcpy(building[5].name, "图书馆");
	strcpy(building[6].name, "东九楼");
	strcpy(building[7].name, "宿舍");
	strcpy(building[8].name, "校外");
	strcpy(building[9].name, "工程实训中心");
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
		case 0:		//初始化选择界面
		{
			initmenu_set(&func);    //会改变func的值进入
			//while (1);
			memset(&u, '\0', sizeof(USER));
			for (i = 1; i <= 9; i++)
			{
				building[i].canIn = 0;
				building[i].numVisitor = 0;
			}
			peoplenumber = 0;
			break;                  //也即回到界面就成为无登录状态
		}
		case 1:		//退出按钮
			delay(1000);
			closegraph();
			exit(1);
		case 2:		//用户登录界面
			user_login(&func, &u);
			break;
		case 3:		//用户注册界面
			user_register(&func);
			break;
		case 4:		//忘记密码界面
			user_forgetpass(&func);
			break;
		case 5:		//管理员登录界面
			admin_login(&func);
			break;
		case 6:
			AdminInitPage(&func, people, &peoplenumber); //管理员初始界面
			break;
		case 7:
			AdminDisplayPage(&func, people, building, peoplenumber); //管理员演示界面
			break;
		case 8:
			control_drawuser(&func,&ber);//用户管理界面
			break;
		case 10:
			yuyue(&func,&ber);//预约出校界面
			break;
		case 11:

			yuyuecar(&func,&ber);//外来车辆预约界面
			break;
		case 12:

			jilu(&func,&ber);//行踪记录界面
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