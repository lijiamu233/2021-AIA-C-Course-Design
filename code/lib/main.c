#include"./include/main.h"
#include"./include/public.h"

void main(void)
{
	int func = 0;
	int gd = VGA;
	int gm = VGAHI;
	USER u;
	memset(&u, '\0', sizeof(USER));
	initgraph(&gd, &gm, "BGI");

	mouseinit();
	//freopen("Database//Debug.txt", "w", stdout); //debug
	while (1)
	{
		switch (func)
		{
		case 0:		//初始化选择界面
		{
			initmenu_set(&func);    //会改变func的值进入
			memset(&u, '\0', sizeof(USER));
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

		}
	}
}