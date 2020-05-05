#pragma warning(disable:4996)
#include <iostream>
using namespace std;
//问题表示
int n = 4, W;
//存放所有整数，不用下标0的元素
int w[] = { 0,11,13,24,7 };

//求解子集和
bool dfs(int i, int tw, int rw)
{
	if (i > n)
	{
		if (tw == W)
		{
			return true;
		}
	}
	else
	{
		if (tw + w[i] <= W)
		{
			return dfs(i + 1, tw + w[i], rw - w[i]);
		}
		if (tw + rw - w[i] >= W)
		{
			return dfs(i + 1, tw, rw - w[i]);
		}
	}
	return false;
}


//判断子集和问题是否存在解
bool solve()
{
	int rw = 0;
	for (int j = 1; j <=n; j++)
	{
		rw += w[j];
	}
	return dfs(1, 0, rw);
}

void main()
{
	W = 7;
	printf("W=%d时%s\n", W, (solve() ? "存在解" : "没有解"));
	W = 15;
	printf("W=%d时%s\n", W, (solve() ? "存在解" : "没有解"));
	W = 21;
	printf("W=%d时%s\n", W, (solve() ? "存在解" : "没有解"));
	W = 24;
	printf("W=%d时%s\n", W, (solve() ? "存在解" : "没有解"));
	system("pause");
}