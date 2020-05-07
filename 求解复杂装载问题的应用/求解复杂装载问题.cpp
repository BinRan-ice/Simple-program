#pragma warning(disable:4996)
#include <iostream>
using namespace std;
//最多集装箱个数
#define MAXN 20
//问题表示
//各集装箱重量，不用下标0的元素
int w[] = { 0,10,40,40 };
int n = 3;
int c1 = 50, c2 = 50;
//存放第一艘轮船最优解的重量
int maxw = 0;
//存放第一艘轮船最优解向量
int x[MAXN];

//求第一艘轮船的最优解
void dfs(int i, int tw, int rw, int op[])
{
	if (i>n)
	{
		if (tw>maxw)
		{
			maxw = tw;
			for (int j = 1; j < n; j++)
			{
				x[j] = op[j];
			}
		}
	}
	else
	{
		if (tw+w[i]<=c1)
		{
			op[i] = 1;
			dfs(i + 1, tw + w[i], rw - w[i], op);
		}
		if (tw+rw-w[i]>maxw)
		{
			op[i] = 0;
			dfs(i + 1, tw, rw - w[i], op);
		}
	}
}

//输出一个解
void dispasolution(int n)
{
	for (int j = 1; j <= n; j++)
	{
		if (x[j]==1)
		{
			printf("\t将第%d个集装箱装上第一艘货轮\n", j);
		}
		else
		{
			printf("\t将第%d个集装箱装上第二艘货轮\n", j);
		}
	}
}

//求解复杂装载问题
bool solve()
{
	int sum = 0;
	for (int j = 1; j < n; j++)
	{
		if (x[j]==0)
		{
			sum += w[j];
		}
	}
	if (sum<=c2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void main()
{
	int op[MAXN];
	memset(op, 0, sizeof(op));
	int rw = 0;
	for (int i = 0; i < n; i++)
	{
		rw += w[i];
	}
	dfs(1, 0, rw, op);
	cout << "求解结果" << endl;
	if (solve())
	{
		cout << "最优方案" << endl;
		dispasolution(n);
	}
	else
	{
		cout << "没有合适的装载方案" << endl;
	}

	system("pause");
}