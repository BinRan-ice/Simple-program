#pragma warning(disable:4996)
#include <iostream>
using namespace std;
//��༯װ�����
#define MAXN 20
//�����ʾ
//����װ�������������±�0��Ԫ��
int w[] = { 0,10,40,40 };
int n = 3;
int c1 = 50, c2 = 50;
//��ŵ�һ���ִ����Ž������
int maxw = 0;
//��ŵ�һ���ִ����Ž�����
int x[MAXN];

//���һ���ִ������Ž�
void dfs(int i, int tw, int rw, int op[])
{
	if (i>n)
	{
		if (tw>maxw)
		{
			maxw = tw;
			for (int j = 1; j < n; j++)
			{
				x[j] = op[j];
			}
		}
	}
	else
	{
		if (tw+w[i]<=c1)
		{
			op[i] = 1;
			dfs(i + 1, tw + w[i], rw - w[i], op);
		}
		if (tw+rw-w[i]>maxw)
		{
			op[i] = 0;
			dfs(i + 1, tw, rw - w[i], op);
		}
	}
}

//���һ����
void dispasolution(int n)
{
	for (int j = 1; j <= n; j++)
	{
		if (x[j]==1)
		{
			printf("\t����%d����װ��װ�ϵ�һ�һ���\n", j);
		}
		else
		{
			printf("\t����%d����װ��װ�ϵڶ��һ���\n", j);
		}
	}
}

//��⸴��װ������
bool solve()
{
	int sum = 0;
	for (int j = 1; j < n; j++)
	{
		if (x[j]==0)
		{
			sum += w[j];
		}
	}
	if (sum<=c2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void main()
{
	int op[MAXN];
	memset(op, 0, sizeof(op));
	int rw = 0;
	for (int i = 0; i < n; i++)
	{
		rw += w[i];
	}
	dfs(1, 0, rw, op);
	cout << "�����" << endl;
	if (solve())
	{
		cout << "���ŷ���" << endl;
		dispasolution(n);
	}
	else
	{
		cout << "û�к��ʵ�װ�ط���" << endl;
	}

	system("pause");
}