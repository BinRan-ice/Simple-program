#pragma warning(disable:4996)
#include <iostream>
using namespace std;
//ͼ���Ķ������
#define MAXN 20
//�����ʾ
int n, k, m;
int a[MAXN][MAXN];
//�������ʾ
int x[MAXN];
int count = 0;

//�ж϶���i�Ƿ������ڶ��������ͬ����ɫ
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

//���һ����ɫ����
void dispasolution()
{
	printf("��%d����ɫ������", ::count);
	for (int i = 1; i <=n ; i++)
	{
		printf("%d", x[i]);
	}
	cout << endl;
}

//���ͼ��m��ɫ����
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