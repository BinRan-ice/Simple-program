#include<iostream>
using namespace std;
#define INF 99999
#define MANX 21
//�����ʾ
int n = 4;
int c[MANX][MANX] = { {0},{0,9,2,7,8},{0,6,4,3,7},{0,5,8,1,8},{0,7,6,9,4} };
//�������ʾ
//��ʱ��
int x[MANX];
//��ʱ��ĳɱ�
int cost = 0;
//���Ž�
int bestx[MANX];
//���Ž�ĳɱ�
int mincost = INF;
//worker[j]��ʾ����j�Ƿ��Ѿ�������Ա
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
	cout << "���ŷ���" << endl;
	for (int k = 1; k <= n; k++)
		cout << "��" << k << "���˰�������" << bestx[k] << endl;
	cout << "�ܳɱ�=" << mincost << endl;
	system("pause");
}