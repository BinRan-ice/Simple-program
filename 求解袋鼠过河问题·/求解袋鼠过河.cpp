#include<iostream >
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))
#define MAXN 10001
#define INF 0x3f3f3f3f
//问题表示
int n;
int a[MAXN];
//求解结果表示
int dp[MAXN];
int solve()//求解算法、
{
	int i, j;
	for (i = 1; i <= n; i++)
		dp[i] = INF;
	dp[0] = 0;
	for (i = 1; i <= n; i++)
		for (j = 0; j < i; j++)
		{
			if (a[j] + j >= i)
				dp[i] = min(dp[i], dp[j] + 1);
		}
	return dp[n] == INF ? -1 : dp[n];
}
int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << solve() << endl;
	}
	return 0;
}