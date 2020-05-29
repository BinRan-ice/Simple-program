#pragma warning(disable:4996)
#include <iostream>
#include<map>
#include<math.h>
#include<vector>
#include <graphics.h>
#include <conio.h>
using namespace std;
#define MAX 19
double h[MAX];
double u[MAX];
double v[MAX];
double d[MAX];
double Y[MAX];
double M[MAX];
double dif_quo1[MAX];
double dif_quo2[MAX];
double A[MAX][MAX] = { 0 };
double L[MAX][MAX] = { 0 };
double U[MAX][MAX] = { 0 };
double f0 = 1.86548, f18 = -0.046115;
map<double, double>::iterator it;

//打印采集的数据
void disp(map<double, double>&data)
{
	for (it=data.begin();it!=data.end();it++)
	{
		printf("[%f,%f]", it->first, it->second);
		cout << endl;
	}
	puts(" ");
}

//计算h的值
void cal_h(map<double, double>&data)
{
	int i = 0;
	double x, y;
	for (it = data.begin(); it != (--data.end());)
	{
		x = it->first;
		y = (++it)->first;
		h[i] = y - x;
		i++;
	}
	for (int j = 0; j < MAX-1; j++)
	{
		printf("h%d=%f\n", j, h[j]);
	}
	puts(" ");
}

//计算u和v
void cal_u_and_v(map<double, double>&data)
{
	for (int i = 1; i <= MAX-2; i++)
	{
		u[i] = (double)(h[i - 1] / (h[i - 1] + h[i]));
		v[i] = 1 - u[i];
		printf("u%d=%f v%d=%f\n", i,u[i],i,v[i]);
	}
	puts(" ");
}

//计算一阶差商和二阶差商
void cal_dif_quo(map<double, double>&data)
{
	int i = 0,j=0;
	double x1, x2, y1, y2;
	for ( it = data.begin(); it->first !=520;)
	{
		x1 = it->first;
		y1 = it->second;
		it++;
		x2 = it->first;
		y2 = it->second;
		dif_quo1[i] = (y2 - y1) / (x2 - x1);
		cout << dif_quo1[i] << endl;
		i++;
	}
	puts(" ");
	for (it = data.begin(); it->first!=507;it++)
	{
		x1 = it->first;
		it++;
		it++;
		x2 = it->first;
		dif_quo2[j] =(dif_quo1[j + 1] - dif_quo1[j]) / (x2 - x1);
		it--;
		it--;
		cout << dif_quo2[j] << endl;
		j++;
	}
	puts(" ");

}

//计算d
void cal_d()
{
	for (int i = 0; i < MAX; i++)
	{
		if (i==0)
		{
			d[i] = (6 / h[i]) * (dif_quo1[i] - f0);
			cout << d[i] << endl;
		}
		else if (i==MAX-1)
		{
			d[i] = (6 / h[i - 1]) * (f18 - dif_quo1[i-1]);
			cout << d[i] << endl;
		}
		else
		{
			d[i] = 6 * dif_quo2[i - 1];
			cout << d[i] << endl;
		}
	}
}

void init_A(double u[], double v[])
{
	A[0][0] = A[18][18] = 2;
	A[0][1] = A[18][17] = 1;
	for (int i = 1; i <MAX-1 ; i++)
	{
		
		A[i][i + 1] = v[i];
		A[i][i - 1] = u[i];
		A[i][i] = 2;
	}
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cout << A[i][j]<<"  ";
		}
		cout << endl;
	}
	puts(" ");
}


void cal_L_U(double A[MAX][MAX])
{
	U[0][0] = 2, U[0][1] = 1,L[0][0]=1;
	for (int i = 1; i < MAX; i++)
	{
		L[i][i - 1] = A[i][i-1]/U[i - 1][i - 1];
		L[i][i] = 1;
		U[i][i] = A[i][i] - (L[i][i - 1] * U[i - 1][i]);
		U[i][i + 1] = A[i][i + 1];
	}
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cout << L[i][j] << "  ";
		}
		cout << endl;
	}
	puts(" ");
	for (int m = 0; m < MAX; m++)
	{
		for (int n = 0; n < MAX; n++)
		{
			cout << U[m][n] << "  ";
		}
		cout << endl;
	}
	puts(" ");
}

void cal_Y(double L[MAX][MAX])
{
	Y[0] = d[0] / L[0][0];
	printf("Y0=%.9f\n", Y[0]);
	for (int i = 1; i < MAX; i++)
	{
		Y[i] = d[i]-(Y[i-1] * L[i][i - 1]);
		printf("Y%d=%.9f\n", i, Y[i]);
	}
	puts(" ");
}

void cal_M(double U[MAX][MAX], double Y[MAX])
{
	M[18] = Y[18] / U[18][18];
	printf("M18=%.9f\n", M[18]);
	for (int i = 17; i >=0 ; i--)
	{
		M[i] = (Y[i] - M[i + 1] * U[i][i + 1]) / U[i][i];
		printf("M%d=%.9f\n", i, M[i]);
	}
	puts(" ");
}

void Cubic_Spline(map<double, double>&data, map<double, double>&point, double M[MAX],double x)
{
	int i = 0;
	double solve,X1,X2,Y1,Y2;
	for ( it = data.begin(); it !=(--data.end());)
	{
		X1 = it->first;
		Y1 = it->second;
		it++;
		X2 = it->first;
		Y2 = it->second;
		if (x>=X1&&x<=X2)
		{
			printf("X在[%f，%f]范围内，用三次样条估计的值为：", X1, X2);
			solve = -((pow((x - X2), 3)*M[i]) / (6 * h[i])) + ((pow((x - X1), 3)*M[i + 1]) / (6 * h[i])) - ((Y1 - (pow(h[i], 2)*M[i] / 6))*((x - X2) / h[i])) + ((Y2 - (pow(h[i], 2)*M[i + 1] / 6))*((x - X1) / h[i]));
			cout << solve<<endl;
			point[x] = solve;
			return;
		}
		i++;
	}
}

void paint(map<double, double>&data, map<double, double>&point)
{
	// 创建绘图窗口
	initgraph(600, 600);
	setbkcolor(0xFFFFFF);
	for (it = data.begin(); it != data.end(); it++)
	{
		putpixel(it->first, it->second, BLACK);
	}
	// 按任意键退出
	_getch();
	closegraph();

}

void main()
{
	//double x;
	//map<double, double>data;
	//map<double, double>point;
	//cout << "采集到的数据为：" << endl;
	//data[0.520] = 5.288,data[3.1] = 9.4,data[8.0]=13.84,data[17.95]=20.20,data[28.65]=24.90,data[39.62]=28.44,data[50.65]=31.10,data[78]=35,data[104.6]=36.9,data[156.6]=36.6,data[208.6]=34.6,data[260.7]=31.0,data[312.5]=26.34,data[364.4]=20.9,data[416.3]=14.8,data[468]=7.8,data[494]=3.7,data[507]=1.5,data[520]=0.2;
	//disp(data);
	//cout << "计算h的值为：" << endl;
	//cal_h(data);
	//cout << "计算u和v的值为：" << endl;
	//cal_u_and_v(data);
	//cout << "一阶差商和二阶差商为：" << endl;
	//cal_dif_quo(data);
	//cout << "计算d的值为：" << endl;
	//cal_d();
	//cout << "得到的弯矩方程组为：" << endl;
	//init_A(u, v);
	//cout << "得到分解的L和U为：" << endl;
	//cal_L_U(A);
	//cout << "计算得到的Y为：" << endl;
	//cal_Y(L);
	//cout << "计算得到的M为：" << endl;
	//cal_M(U, Y);
	//while (true)
	//{
	//	cout << "请输入你要计算的X(输入999退出输入）：";
	//	cin >> x;
	//	if (x == 999)
	//	{
	//		break;
	//	}
	//	Cubic_Spline(data,point, M, x);

	//}
	cout << "所得到的图像和输入点的拟合位置为：" << endl;
	//paint(data,point);
	// 创建绘图窗口
	// 初始化绘图窗口
	initgraph(640, 480);

	// 设置背景色为蓝色
	setbkcolor(BLUE);
	// 用背景色清空屏幕
	cleardevice();

	// 设置绘图色为红色
	setcolor(RED);
	// 画矩形
	rectangle(100, 100, 300, 300);

	// 按任意键退出
	_getch();
	closegraph();
	system("pause");
}