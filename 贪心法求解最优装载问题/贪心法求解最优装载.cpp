#pragma warning(disable:4996)
#include <iostream>
#include<algorithm>
using namespace std;
#define MAXN 20
int w[] = { 0,5,2,6,4,3 };
int n = 5, W = 10;
int maxw;
int x[MAXN];
void solve()
{
	memset(x, 0, sizeof(x));
	sort(w + 1, w + n + 1);
	maxw = 0;
	int restw = W;
	for (int i = 1; i <= n && w[i] <= restw; i++)
	{
		x[i] = 1;
		restw -= w[i];
		maxw += w[i];
	}
}
void main()
{
	solve();
	printf("���ŷ���\n");
	for (int i = 1; i <=n ; i++)
	{
		if (x[i]==1)
		{
			printf("ѡȡ����Ϊ%d�ļ�װ��\n", w[i]);
		}
	}
	printf("������=%d\n", maxw);
	system("pause");
}