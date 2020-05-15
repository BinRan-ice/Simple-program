#pragma warning(disable:4996)
#include <iostream>
#include<vector>
#include <iomanip>
#define MAX 4
using namespace std;
vector<double>::iterator it;
//����ֵ��w
double best_x,w=1.15;
//ͳ�Ƶ�������
int Jacobi_count = 0;
int Gauss_Seidel_count = 0;
int SOR_count = 0;
//������ά����
void disp(double a[MAX][MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cout << fixed << setprecision(9) << a[i][j] << "\t";
		}
		cout << endl;
	}

}
//��������;�ȷ���������ֵ
double max_compare(vector<double>V)
{
	double temp1, temp2;
	if ((V[0] - 1) > (V[1] + 2))
	{
		temp1 = abs(V[0] - 1);
	}
	else
	{
		temp1 = abs(V[1] + 2);
	}
	if ((V[2] + 1) > (V[3] - 3))
	{
		temp2 = abs(V[2] + 1);
	}
	else
	{
		temp2 = abs(V[3] - 3);
	}
	if (temp1 > temp2)
	{
		best_x = temp1;
		return best_x;
	}
	else
	{
		best_x = temp2;
		return best_x;
	}
}
//������Ľ���ش�����һ�εĽ����
void Jacobi_Swap(vector<double>&X1, vector<double>&X2)
{
	int i = 0;
	for ( it = X2.begin(); it !=X2.end() ; it++)
	{
		X1[i] = *it;
		i++;
	}
}
//Jacobi������
void Jacobi(vector<double>X1, vector<double>X2)
{
	X2[0] = (double)1 / 5 * (double)(-X1[1] + X1[2] + 2 * X1[3] - 2);
	X2[1] = (double)1 / 8 * (double)(-2 * X1[0] - X1[2] - 3 * X1[3] - 6);
	X2[2] = (double)1 / 4 * (double)(X1[0] - 2 * X1[1] - X1[3] - 6);
	X2[3] = (double)1 / 7 * (double)(X1[0] - 3 * X1[1] - 2 * X1[2] + 12);
	Jacobi_Swap(X1,X2);
	Jacobi_count++;
	if (0.000125 > max_compare(X2))
	{
		cout << "Jacobiһ��������" << Jacobi_count << "��" << endl << "��Ӧ�Ľ�x1,x2,x3,x4Ϊ��" << endl;
		for (it = X2.begin(); it != X2.end(); it++)
		{
			cout << fixed << setprecision(9) << *it << endl;
		}
		puts(" ");
		return;
	}
	Jacobi(X1, X2);
}
// Gauss_Seidel������
void Gauss_Seidel(vector<double>Y)
{
	Y[0] = (double)1 / 5 * (double)(-Y[1] + Y[2] + 2 *Y[3] - 2);
	Y[1] = (double)1 / 8 * (double)(-2 * Y[0] - Y[2] - 3 * Y[3] - 6);
	Y[2] = (double)1 / 4 * (double)(Y[0] - 2 * Y[1] - Y[3] - 6);
	Y[3] = (double)1 / 7 * (double)(Y[0] - 3 * Y[1] - 2 * Y[2] + 12);
	Gauss_Seidel_count++;
	if (0.000125 > max_compare(Y))
	{
		cout << "Gauss_Seidelһ��������" << Gauss_Seidel_count++ << "��" << endl << "��Ӧ�Ľ�x1,x2,x3,x4Ϊ��" << endl;
		for (it = Y.begin(); it != Y.end(); it++)
		{
			cout << fixed << setprecision(9) << *it << endl;
		}
		puts(" ");
		return;
	}
	Gauss_Seidel(Y);
}
//SOR������
void SOR(vector<double>Z)
{
	Z[0] = ((double)-0.15*Z[0]) + ((double)1.15 / 5) * (double)(-2 - Z[1] + Z[2] + 2 * Z[3]);
	Z[1] = ((double)-0.15*Z[1]) + ((double)1.15 / 8) * (double)(-6 - 2 * Z[0] - Z[2] - 3 * Z[3]);
	Z[2] = ((double)-0.15*Z[2]) + ((double)1.15 / -4)*(double)(6 - Z[0] + 2 * Z[1] + Z[3]);
	Z[3] = ((double)-0.15*Z[3]) + ((double)1.15 / 7)*(double)(12 + Z[0] - 3 * Z[1] - 2 * Z[2]);
	SOR_count++;
	if (0.000125 > max_compare(Z))
	{
		cout << "SORһ��������" << Gauss_Seidel_count++ << "��" << endl << "��Ӧ�Ľ�x1,x2,x3,x4Ϊ��" << endl;
		for (it = Z.begin(); it != Z.end(); it++)
		{
			cout << fixed << setprecision(9) << *it << endl;
		}
		puts(" ");
		return;
	}
	SOR(Z);
}

void main()
{
	double A[MAX][MAX] = { {5,1,-1,2},{2,8,1,3},{1,-2,-4,-1},{-1,3,2,7} };
	vector<double>X1(4, 0),X2(4, 0), Y(4, 0), Z(4, 0);
	cout << "���о������£�" << endl;
	disp(A);
	puts(" ");
	cout << "ʹ��Jacobi��������" << endl;
	Jacobi(X1,X2);
	cout << "ʹ��Gauss-Seidel��������" << endl;
	Gauss_Seidel(Y);
	cout << "ʹ��SOR��������" << endl;
	SOR(Z);
	system("pause");
}