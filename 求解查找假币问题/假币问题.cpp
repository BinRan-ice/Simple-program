#pragma warning(disable:4996)
#include <iostream>
#include<string>
using namespace std;
int w[12];
string a[3] = { "ABCD","ABCI","ABIJ" };
string b[3] = { "EFGH","EFGK","EFGH" };
string c[] = { "even","up","even" };

bool Balanced()
{
	for (int i = 0; i < 3; i++)
	{
		int leftw = 0;
		int rightw = 0;
		for (int j = 0; j < a[i].size(); j++)
		{
			leftw += w[a[i][j] - 'A'];
			rightw += w[b[i][j] - 'A'];
		}
		if (leftw<rightw&&c[i]!="down")
		{
			return false;
		}
		if (leftw == rightw&&c[i] != "even")
		{
			return false;
		}
		if (leftw > rightw&&c[i] != "up")
		{
			return false;
		}
	}
	return true;
}
void solve(int& x, int& y)
{
	for (int i = 0; i < 12; i++)
	{
		w[i] = 1;
		if (Balanced())
		{
			x = i, y = 1;
			return;
		}
		w[i] = -1;
		if (Balanced())
		{
			x = i, y = -1;
			return;
		}
		w[i] = 0;
	}
}

void main()
{
	memset(w, 0, sizeof(w));
	int x, y;
	solve(x, y);
	cout << "求解结果" << endl;
	printf("假币是%c\n", x + 'A');
	if (y==1)
	{
		cout << "该硬币较真币重量重" << endl;
	}
	else
	{
		cout << "该硬币较真币重量轻" << endl;
	}
	system("pause");
}