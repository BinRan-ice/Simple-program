#pragma warning(disable:4996)
#include <iostream>
using namespace std;

//最多皇后个数
#define MAXN 20
//存放各皇后所在的列号，为全局变量
int q[MAXN];

//输出一个解
void dispasolution(int n)
{
	//累计解个数
	static int count = 0;
	printf("第%d个解：", ++count);
	for (int i = 1; i <= n; i++)
	{
		printf("(%d,%d)", i, q[i]);
	}
	cout << endl;
}

//测试第i行的q[i]列上能否摆放皇后
bool place(int i)
{
	int j = 1;
	if (i==1)
	{
		return true;
	}
	while (j < i)
	{
		if ((q[j]==q[i])||(abs(q[j]-q[i])==abs(j-i)))
		{
			return false;
		}
		j++;
	}
	return true;
}

//求解n皇后问题
void Queens(int n)
{
	int i = 1;
	q[i] = 0;
	while (i>=1)
	{
		q[i]++;
		while (q[i]<=n&&!place(i))
		{
			q[i]++;
		}
		if (q[i]<=n)
		{
			if (i==n)
			{
				dispasolution(n);
			}
			else
			{
				i++;
				q[i] = 0;
			}
		}
		else
		{
			i--;
		}
	}
}

void main()
{
	int n;
	scanf("%d", &n);
	printf("%d皇后问题求解如下:\n", n);
	Queens(n);
	system("pause");
}