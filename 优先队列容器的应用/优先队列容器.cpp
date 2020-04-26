#pragma warning(disable:4996)
#include <iostream>
#include<queue>
using namespace std;

void main()
{
	priority_queue<int>qu;
	qu.push(1); qu.push(2); qu.push(3);
	printf("队头元素：%d\n", qu.top());
	printf("出队顺序： ");
	while (!qu.empty())						//出队所有元素
	{
		printf("%d", qu.top());
		qu.pop();
	}
	cout << endl;
	system("pause");
}