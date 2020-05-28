#pragma warning(disable:4996)
#include <iostream>
#include<string>
#include<map>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 21

int n;
int start;
int end;
int c[MAX][MAX];
int next[MAX];
map<int, string>vname;
int dp[MAX];
int Count = 1;

void Init()
{
	n = 10;
	start = 0;
	::end = 9;
	memset(c, INF, sizeof(c));
	for (int i = 0; i < n; i++)
	{
		dp[i] = -1;
	}
	for (int j = 0; j < n; j++)
	{
		c[j][j] = 0;
	}
	c[0][1] = 2;	c[0][2] = 4;	c[0][3] = 3;
	c[1][4] = 7;	c[1][5] = 4;
	c[2][4] = 3;	c[2][5] = 2;	c[2][6] = 4;
	c[3][4] = 6;	c[3][5] = 2;	c[3][6] = 5;
	c[4][7] = 3;	c[4][8] = 4;
	c[5][7] = 6;	c[5][8] = 3;
	c[6][7] = 3;	c[6][8] = 3;
	c[7][9] = 3;
	c[8][9] = 4;
	vname[0] = "A";
	vname[1] = "B1";	vname[2] = "B2";	vname[3] = "B3";
	vname[4] = "C1";	vname[5] = "C2";	vname[6] = "C3";
	vname[7] = "D1";	vname[8] = "D2";
	vname[9] = "E";
} 

int f(int s)
{
	if (dp[s]!=-1)
	{
		return dp[s];
	}
	if (s==::end)
	{
		dp[s] = 0;
		printf("(%d)f(%s)=0\n", Count++, vname[s]);
		return dp[s];
	}
	else
	{
		int cost, mincost = INF, minj;
		for (int j = 0; j < n; j++)
		{
			if (c[s][j]!=0&&c[s][j]!=INF)
			{
				cost = c[s][j] + f(j);
				if (mincost>cost)
				{
					mincost = cost;
					minj = j;
				}
			}
		}
	dp[s] = mincost;
	::next[s] = minj;
	printf("(%d)f(%s)=c(%s,%s)+f(%s)=%d,", Count++, vname[s], vname[s], vname[minj], vname[minj]);
	printf("next(%s)=%s\n", vname[s], vname[minj]);
	return dp[s];
	}
}

void main()
{
	Init();
	printf("%s->%s������\n", vname[::end], vname[start]);
	f(start);
	system("pause");
}