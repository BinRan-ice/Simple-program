#pragma warning(disable:4996)
#include <iostream>
#include<algorithm>
using namespace std;
#define MAX 51

struct Action
{
	int b;
	int e;
	bool operator<(const Action&s)const
	{
		return e <= s.e;
	}
};
int n = 11;
Action A[] = { {0},{1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6,10},{8,11},{8,12},{2,13},{12,15} };
bool flag[MAX];
int Count = 0;

void solve()
{
	memset(flag, 0, sizeof(flag));
	sort(A + 1, A + n + 1);
	int preend = 0;
	for (int i = 1; i <=n ; i++)
	{
		if (A[i].b>=preend)
		{
			flag[i] = true;
			preend = A[i].e;
		}
	}
}

void main()
{
	solve();
	printf("求解结果\n");
	printf("选取的活动：");
	for (int i = 1; i <= n; i++)
	{
		if (flag[i])
		{
			printf("[%d,%d]", A[i].b, A[i].e);
			Count++;
		}
	}
	printf("\n共%d个活动\n", Count);
	system("pause");
}