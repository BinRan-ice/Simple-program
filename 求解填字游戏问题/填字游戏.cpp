#pragma warning(disable:4996)
#include <iostream>
using namespace std;
#define N 10
bool used[N + 1];
int a[9];
int count = 0;
int Checkmatrix[][3] = { {-1},{0,-1},{1,-1},{0,-1},{1,3,-1},{2,4,-1},{3,-1},{4,6,-1},{5,7,-1} };

void dispasolution(int a[])
{
	int i, j;
	printf("½â%d\n", ++::count);
	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 3; j++)
		{
			printf("%3d", a[3 * i + j]);
		}
		cout << endl;
	}
}

int selectnum(int start)
{
	for (int j = start; j <=N ; j++)
	{
		if (used[j])
		{
			return j;
		}
	}
	return 0;
}

int change(int pos)
{
	int j;
	while (pos>=0&&(j=selectnum(a[pos]+1))==0)
	{
		used[a[pos--]] = true;
	}
	if (pos<0)
	{
		return -1;
	}
	used[a[pos]] = true;
	a[pos] = j;
	used[j] = false;
	return pos;
}

bool isPrime(int m)
{
	bool flag = true;
	for (int i = 2; i <=sqrt(m) ; i++)
	{
		if (m%i==0)
		{
			return false;
		}
	}
	return true;
}

int extend(int pos)
{
	a[++pos] = selectnum(1);
	used[a[pos]] = 0;
	return pos;
}

bool Check(int pos)
{
	int i, j;
	if (pos<0)
	{
		return 0;
	}
	for ( i = 0;(j=Checkmatrix[pos][i])>=0 ; i++)
	{
		if (!isPrime(a[pos]+a[j]))
		{
			return false;
		}
	}
	return true;
}

void slove()
{
	bool ok=true;
	int pos = 0;
	a[pos] = 1;
	used[a[pos]] = 0;
	do
	{
		if (ok)
		{
			if (pos==8)
			{
			dispasolution(a);
			pos = change(pos);
			}
		else
		{
			pos = extend(pos);
		}
		}
		else
		{
			pos = change(pos);
		}
		ok = Check(pos);
	} while (pos>=0);
}

void main()
{
	for (int i = 1; i <=N ; i++)
	{
		used[i] = true;
	}
	slove();
	printf("count=%d\n", ::count);
	system("pause");
}