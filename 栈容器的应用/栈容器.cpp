#pragma warning(disable:4996)
#include <iostream>
#include<stack>
using namespace std;

void main()
{
	stack<int>st;
	st.push(1); st.push(2); st.push(3);
	printf("ջ��Ԫ�أ�%d\n", st.top());
	printf("��ջ˳��");
	while (!st.empty())
	{
		printf("%d", st.top());
		st.pop();
	}
	system("pause");
}