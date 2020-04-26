#pragma warning(disable:4996)
#include <iostream>
#include<stack>
using namespace std;

void main()
{
	stack<int>st;
	st.push(1); st.push(2); st.push(3);
	printf("Õ»¶¥ÔªËØ£º%d\n", st.top());
	printf("³öÕ»Ë³Ðò£º");
	while (!st.empty())
	{
		printf("%d", st.top());
		st.pop();
	}
	system("pause");
}