#pragma warning(disable:4996)
#include <iostream>
#include<algorithm>
using namespace std;
#define MAX 1001
int n;
int a[MAX];
int b[MAX];
int ans;

void solve()
{
	sort(a, a + n);
	sort(b, b + n);
	ans = 0;
	int lefta = 0, leftb = 0;
	int righta = n - 1, rightb = n - 1;
	while (lefta<=righta)
	{
		if (a[righta]>b[rightb])
		{
			ans += 200;
			righta--;
			rightb--;
		}
		else if (a[righta]<b[rightb])
		{
			ans -= 200;
			rightb--;
			lefta++;
		}
		else
		{
			if (a[lefta]>b[leftb])
			{
				ans += 200;
				lefta++;
				leftb++;
			}
			else
			{
				if (a[lefta]<b[rightb])
				{
					ans -= 200;
					lefta++;
					rightb--;
				}
			}
		}
	}
}
void main()
{
	while (true)
	{
		scanf("%d", &n);
		if (n==0)
		{
			break;
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &b[j]);
		}
		solve();
		printf("%d\n", ans);
	}
	system("pause");
}