#pragma warning(disable:4996)
#include <iostream>
using namespace std;

void swap(int &x, int&y)
{
	int temp = x;
	x = y;
	y = temp;
}

void disp(int a[], int n)								//���a�е�����Ԫ��
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i]<<" ";
	}
}

void SelectSort(int a[], int n, int i)					//�ݹ�ļ�ѡ������	
{
	int j,k;
	if (i==n-1)
	{
		return;											//����ݹ��������
	}
	else
	{
		k = i;
		for (j=i+1;j<n; j++)
		{
			if (a[j]<a[k])
			{
				k = j;
			}
		}
		if (k!=i)
		{
			swap(a[i], a[k]);
		}
		SelectSort(a, n, i + 1);
	}
}

void main()
{
	int n = 10;
	int a[] = { 2,5,1,7,10,6,9,4,3,8 };
	printf("����ǰ��");
	disp(a, n);
	cout << endl;
	SelectSort(a, n, 0);
	printf("�����");
	disp(a, n);
	system("pause");
}