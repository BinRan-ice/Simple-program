#include<iostream>
using namespace std;
#define INF 99999
#define MANX 21
//问题表示
int n = 4;
int c[MANX][MANX] = { {0},{0,9,2,7,8},{0,6,4,3,7},{0,5,8,1,8},{0,7,6,9,4} };
//求解结果表示
//临时解
int x[MANX];
//临时解的成本
int cost = 0;
//最优解
int bestx[MANX];
//最优解的成本
int mincost = INF;
//worker[j]表示任务j是否已经分配人员
bool worker[MANX]; void dfs(int i)
{
	if (i > n)
	{
		if (cost < mincost)
		{
			mincost = cost;
			for (int j = 1; j <= n; j++)
				bestx[j] = x[j];
		}
	}
	else
	{
		for (int j = 1; j <= n; j++)
			if (!worker[j])
			{
				worker[j] = true;
				x[i] = j;
				cost += c[i][j];
				dfs(i + 1);
				worker[j] = false;
				x[j] = 0;
				cost -= c[i][j];
			}
	}
}
void main()
{
	memset(worker, 0, sizeof(worker));
	dfs(1);
	cout << "最优方案" << endl;
	for (int k = 1; k <= n; k++)
		cout << "第" << k << "个人安排任务" << bestx[k] << endl;
	cout << "总成本=" << mincost << endl;
	system("pause");
}