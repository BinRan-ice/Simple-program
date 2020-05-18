#pragma warning(disable:4996)
#include <iostream>
#include<algorithm>
using namespace std;
#define MAX 51
struct Cow
{
	int no;
	int b;
	int e;
	bool operator<(const Cow&s)const
	{
		if (e==s.e)
		{
			return b < s.b;
		}
		else
		{
			return e <= s.e;
		}
	}
};
int n = 5;
Cow A[] = { {0},{1,1,0},{2,2,4},{3,3,6},{4,5,8},{5,4,7} };
int ans[MAX];
void solve()
{
	sort(A + 1, A + 1 + n);
	memset(ans, 0, sizeof(ans));
	int num = 1;
	for (int i = 1; i <=n; i++)
	{
		if (ans[i]==0)
		{
			ans[i] = num;
			int preend=A[i].e;
			for (int j = i+1; j <=n ; j++)
			{
				if (A[j].b>preend&&ans[j]==0)
				{
					ans[j] = num;
					preend = A[j].e;
				}
			}
			num++;
		}
	}
}
void main()
{
	solve();
	printf("求解结果\n");
	for (int i = 1; i <=n; i++)
	{
		printf("牛%d安排的畜栏:%d\n", A[i].no, ans[i]);
	}
	system("pause");
}