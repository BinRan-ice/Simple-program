#pragma warning(disable:4996)
#include <iostream>
using namespace std;

void disp(int a[], int n)								//输出a中的所有元素
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	cout << endl;
}

int Partition(int a[], int s, int t)					//划分算法
{
	int i = s, j = t;
	int tmp = a[s];										//用序列的第一个记录作为基准
	while (i != j)										//从序列两端交替向中间扫描，直到i=j为止
	{
		while (j > i&&a[j] >= tmp)
		{
			j--;										//从右向左扫描，找第一个关键字小于tmp的a[j]
		}
		a[i] = a[j];									//将a[j]前移到a[i]的位置
		while (i < j&&a[i] <= tmp)
		{
			i++;										//从左向右扫描，找第一个关键字大于tmp的a[i]
		}
		a[j] = a[i];									//将a[i]后移到a[j]的位置
	}
		a[i] = tmp;
		return i;

}

void QuickSort(int a[], int s, int t)					//对[s..t]元素序列进行递增排序
{
	if (s<t)											//序列内至少存在两个元素的情况
	{
		int i = Partition(a, s, t);
		QuickSort(a, s, i - 1);
		QuickSort(a, i + 1, t);
	}
}

void main()
{
	int n = 10;
	int a[] = { 2,5,1,7,10,6,9,4,3,8 };
	printf("排序前：");
	disp(a, n);
	QuickSort(a, 0, n - 1);
	printf("排序后：");
	disp(a, n);
	system("pause");
}