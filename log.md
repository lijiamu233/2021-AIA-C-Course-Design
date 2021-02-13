#### create_people.c
- **ljm：**
	double CreateTemperature(); //运用Box Muller算法生成随机体温  
	void CreateTrace(int\* p);  //生成随机路径
	int CheckTemperature(double temperature);  //检测温度，合格返回0，不合格返回1
	void InitBuildings(BUILDING building[]);  //初始化建筑物信息
	void VisitBuilding(BUILDING\* building, PEOPLE\* people, BUILDING buildings[], PEOPLE peoples[], int nowTime);  //人物单位到访建筑物的一系列操作
	display.h  //演示功能开工。