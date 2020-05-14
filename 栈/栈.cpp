#pragma warning(disable:4996)
#include <iostream>
using namespace std;
const int StackSize = 10;

template<class DataType>
class SeqStack
{
public:
	DataType GetTop()
	{
		if (top != -1)
		{

			return data[top];
		}
		else
		{
			throw"����";
		}
	}
	int Empty()
	{
		if (top==-1)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
public:
	SeqStack() { top = -1; }
	~SeqStack() {}
	void Push(DataType x);
	DataType Pop();
private:
	DataType data[StackSize];
	int top;
};

template<class DataType>
void SeqStack<DataType>::Push(DataType x)
{
	if (top==StackSize-1)
	{
		throw"����";
	}
	data[++top] = x;
}

template<class DataType>
DataType SeqStack<DataType>::Pop()
{
	if (top==-1)
	{
		throw"����";
	}
	DataType x = data[top--];
	return x;
}

void main()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	SeqStack<int> stack;
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	{
		stack.Push(a[i]);
	}
	cout << "ջ��Ԫ��Ϊ��" << stack.GetTop()<<endl;
	cout << "��ջ��Ԫ��Ϊ��" << stack.Pop() << endl;
	cout << "��ջһ���Ժ�ջ��Ԫ��Ϊ��"<< stack.GetTop()<<endl;
	cout << "ջ�Ƿ�Ϊ�գ�";
	int i = stack.Empty();
	if (i==1)
	{
		cout << "ջ��Ϊ��"<<endl;
	}
	else
	{
		cout << "ջΪ��"<<endl;
	}
	system("pause");
}