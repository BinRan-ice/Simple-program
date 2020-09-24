#pragma warning(disable:4996)
#include<iostream>
#include"Tourism.h"
#include<graphics.h>
#include<time.h>
#include<conio.h>
using namespace std;

void doChoose();
void output();

int main()
{

	doChoose();
	system("pause");
	return 0;
}

void doChoose()
{
	int nSection = -1;
	do {
		system("cls");
		output();//展示菜单
		nSection = -1;
		cin >> nSection;
		switch (nSection) {
		case 1: {
			CreateGraph();
			break;
		}
		case 2: {
			OutGraph();
			break;
		}
		case 3: {
			GetSpotInfo();
			break;
		}
		case 4: {
			TravelPath();
			break;
		}
		case 5: {
			TopoSort_matrix();
			break;
		}
		case 6: {
			FindShortPath();
			break;
		}
		case 7: {
			DesignPath();
			break;
		}
		default:
			break;
		}
	} while (nSection != 0);
}

void output()
{
	cout << "!!!!!!!!!!!!!请确保您的所有操作在建立图后进行!!!!!!!!!!!!!!!!" << endl;
	cout << "================欢迎来到景区管理系统=============" << endl;
	cout << "*************************************************" << endl;
	cout << "*                1.创建景点图                   *" << endl;
	cout << "*                2.输出景点分布图矩阵           *" << endl;
	cout << "*                3.查询景点信息                 *" << endl;
	cout << "*                4.旅游景点导航                 *" << endl;
	cout << "*                5.有无回路                     *" << endl;
	cout << "*                6.最短路径搜索                 *" << endl;
	cout << "*                7.铺设电路规划                 *" << endl;
	cout << "*                0.退出                         *" << endl;
	cout << "*************************************************" << endl;
	cout << "请输入您的选择:";
}
