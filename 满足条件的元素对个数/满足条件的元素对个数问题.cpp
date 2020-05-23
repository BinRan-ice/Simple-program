#pragma warning(disable:4996)
#include <iostream>
using namespace std;

int answer(int a[], int n, int c)								//求满足条件的个数count
{
	int i = 0;
	int count = 0;
	for ( i ; i < n; i++)										//遍历数组中的数依次互减，减数减被减数，被减数减减数同时进行
	{
		for (int j=0; j<n ; j++)
		{
			if ((a[i]-a[j])==c)
			{
				count++;
			}
		}
	}
	return count;
}

void main()
{
	int n, c;
	int a[1000];													//定义一个数组用于存放N个数
	cout << "请输入您要输入的整数个数N(<1000)和正整数C：";
	cin >> n >> c;
	for (int i = 0; i < n; i++)										//将N个数分别放入数组
	{
		cin >> a[i];
	}
	int sum=answer(a, n, c);										//统计符合条件的个数
	cout << "满足式子的答案个数为：" << sum << endl;
	system("pause");
}