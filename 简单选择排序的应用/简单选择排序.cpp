#pragma warning(disable:4996)
#include <iostream>
using namespace std;

void swap(int &x, int&y)
{
	int temp = x;
	x = y;
	y = temp;
}

void disp(int a[], int n)								//输出a中的所有元素
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i]<<" ";
	}
}

void SelectSort(int a[], int n, int i)					//递归的简单选择排序	
{
	int j,k;
	if (i==n-1)
	{
		return;											//满足递归出口条件
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
	printf("排序前：");
	disp(a, n);
	cout << endl;
	SelectSort(a, n, 0);
	printf("排序后：");
	disp(a, n);
	system("pause");
}