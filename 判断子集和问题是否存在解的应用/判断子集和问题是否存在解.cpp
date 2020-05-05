#pragma warning(disable:4996)
#include <iostream>
using namespace std;
//�����ʾ
int n = 4, W;
//������������������±�0��Ԫ��
int w[] = { 0,11,13,24,7 };

//����Ӽ���
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


//�ж��Ӽ��������Ƿ���ڽ�
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
	printf("W=%dʱ%s\n", W, (solve() ? "���ڽ�" : "û�н�"));
	W = 15;
	printf("W=%dʱ%s\n", W, (solve() ? "���ڽ�" : "û�н�"));
	W = 21;
	printf("W=%dʱ%s\n", W, (solve() ? "���ڽ�" : "û�н�"));
	W = 24;
	printf("W=%dʱ%s\n", W, (solve() ? "���ڽ�" : "û�н�"));
	system("pause");
}