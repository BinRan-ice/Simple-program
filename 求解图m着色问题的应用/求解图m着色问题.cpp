#pragma warning(disable:4996)
#include <iostream>
using namespace std;
//图最多的顶点个数
#define MAXN 20
//问题表示
int n, k, m;
int a[MAXN][MAXN];
//求解结果表示
int x[MAXN];
int count = 0;

//判断顶点i是否与相邻顶点存在相同的着色
bool Same(int i)
{
	for (int j = 1; j <= n; j++)
	{
		if ((a[i][j] == 1) && (x[i] == x[j]))
		{
			return false;
		}
	}
	return true;
}

//输出一种着色方案
void dispasolution()
{
	printf("第%d个着色方案：", ::count);
	for (int i = 1; i <=n ; i++)
	{
		printf("%d", x[i]);
	}
	cout << endl;
}

//求解图的m着色问题
void dfs(int i)
{
	if (i > n)
	{
		::count++;
		dispasolution();
	}
	else
	{
		for (int  j = 1; j <=m; j++)
		{
			x[i] = j;
			if (Same(i))
			{
				dfs(i + 1);
			}
			x[i] = 0;
		}
	}
}

void main()
{
	memset(a, 0, sizeof(a));
	memset(x, 0, sizeof(x));
	int x, y;
	scanf("%d%d%d",&n, &k, &m);
	for (int j = 1; j <=k ; j++)
	{
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}
	dfs(1);
	if (::count>0)
	{
		printf("%d\n", ::count);
	}
	else
	{
		printf("-1\n");
	}
	system("pause");
}