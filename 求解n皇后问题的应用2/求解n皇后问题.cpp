#pragma warning(disable:4996)
#include <iostream>
using namespace std;

//���ʺ����
#define MAXN 20
//��Ÿ��ʺ����ڵ��кţ�Ϊȫ�ֱ���
int q[MAXN];

//���һ����
void dispasolution(int n)
{
	//�ۼƽ����
	static int count = 0;
	printf("��%d���⣺", ++count);
	for (int i = 1; i <= n; i++)
	{
		printf("(%d,%d)", i, q[i]);
	}
	cout << endl;
}

//���Ե�i�е�q[i]�����ܷ�ڷŻʺ�
bool place(int i)
{
	int j = 1;
	if (i==1)
	{
		return true;
	}
	while (j < i)
	{
		if ((q[j]==q[i])||(abs(q[j]-q[i])==abs(j-i)))
		{
			return false;
		}
		j++;
	}
	return true;
}

//���n�ʺ�����
void Queens(int n)
{
	int i = 1;
	q[i] = 0;
	while (i>=1)
	{
		q[i]++;
		while (q[i]<=n&&!place(i))
		{
			q[i]++;
		}
		if (q[i]<=n)
		{
			if (i==n)
			{
				dispasolution(n);
			}
			else
			{
				i++;
				q[i] = 0;
			}
		}
		else
		{
			i--;
		}
	}
}

void main()
{
	int n;
	scanf("%d", &n);
	printf("%d�ʺ������������:\n", n);
	Queens(n);
	system("pause");
}