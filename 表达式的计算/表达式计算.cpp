#pragma warning(disable:4996)
#include <iostream>
using namespace std;
const int StackSize = 20;

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
		if (top == -1)
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
	int icp(char cc);
	int isp(char sc);
	int postfix(DataType a[],int num);
	void value(int ans[],int number);
private:
	DataType data[StackSize];
	DataType Profix[StackSize];
	int top;
};

template<class DataType>
void SeqStack<DataType>::Push(DataType x)
{
	if (top == StackSize - 1)
	{
		throw"����";
	}
	data[++top] = x;
}

template<class DataType>
DataType SeqStack<DataType>::Pop()
{
	if (top == -1)
	{
		throw"����";
	}
	DataType x = data[top--];
	return x;
}

template<class DataType>
int SeqStack<DataType>::icp(char cc)
{
	int level;
	switch (cc)
	{
	case'#':level = 0; break;
	case'(':level = 8; break;
	case'*':level = 4; break;
	case'/':level = 4; break;
	case'+':level = 2; break;
	case'-':level = 2; break;
	case')':level = 1; break;
	}
	return level;
}

template<class DataType>
int SeqStack<DataType>::isp(char sc)
{
	int level;
	switch (sc)
	{
	case'#':level = 0; break;
	case'(':level = 1; break;
	case'*':level = 5; break;
	case'/':level = 5; break;
	case'+':level = 3; break;
	case'-':level = 3; break;
	case')':level = 8; break;
	}
	return level;
}

template<class DataType>
int SeqStack<DataType>::postfix(DataType expre[],int num)
{
	int i = num;
	int n = 0;
    char post[StackSize];
	SeqStack <char> c;
	c.Push('#');
	for (int j = 0; j < i; j++)
	{
		if (expre[j] >= 65 && expre[j] <= 90)
		{
			post[n] = expre[j];
			n++;
		}
		else if (c.icp(expre[j]) > c.isp(c.GetTop()))
		{
			c.Push(expre[j]);
		}
		else if (c.icp(expre[j]) == c.isp(c.GetTop()))
		{
			c.Pop();
		}
		else
		{
			post[n] = c.GetTop();
			n++;
			c.Pop();
			while (c.GetTop() != '#')
			{
				if (c.icp(expre[j]) > c.isp(c.GetTop()))
				{
					c.Push(expre[j]);
				}
				else if (c.icp(expre[j]) == c.isp(c.GetTop()))
				{
					c.Pop();
					break;
				}
				else
				{
					post[n] = c.GetTop();
					n++;
					c.Pop();
				}
			}
			if (c.GetTop() == '#')
			{
				c.Push(expre[j]);
			}
		}

	}
	cout << "��׺���ʽ��";
	for (int j = 0; j < n; j++)
	{
		this->Profix[j] = post[j];
		cout << post[j];
	}
	cout << endl;
	return n;
}

template<class DataType>
void SeqStack<DataType>::value(int ans[],int number)
{
	int j = 0;
	int cal_ans;
	SeqStack<int>num;
	for (int i = 0; i < number; i++)
	{
		if (this->Profix[i]>=65&&this->Profix[i]<=90)
		{
			num.Push(ans[j]);
			j++;
		}
		else
		{
			int n = num.GetTop();
			num.Pop();
			int m = num.GetTop();
			num.Pop();
			switch (this->Profix[i])
			{
			case'*':cal_ans = m * n; break;
			case'/':cal_ans = m / n; break;
			case'+':cal_ans = m + n; break;
			case'-':cal_ans = m - n; break;
			}
			num.Push(cal_ans);
		}
	}
	cout << num.GetTop();
}

void main()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	SeqStack<int> stack;
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		stack.Push(a[i]);
	}
	cout << "ջ��Ԫ��Ϊ��" << stack.GetTop() << endl;
	cout << "��ջ��Ԫ��Ϊ��" << stack.Pop() << endl;
	cout << "��ջһ���Ժ�ջ��Ԫ��Ϊ��" << stack.GetTop() << endl;
	cout << "ջ�Ƿ�Ϊ�գ�";
	int i = stack.Empty();
	if (i == 1)
	{
		cout << "ջ��Ϊ��" << endl;
	}
	else
	{
		cout << "ջΪ��" << endl;
	}
	char expre[] = "A+B*(C-D)-E/F#";
	int ans[6];
	int input;
	cout << "��֪��׺���ʽ��A+B*(C-D)-E/F" << endl;
	cout << "������A,B,C,D,E,F��ֵ" << endl;
	for (int i = 0; i < 6; i++)
	{
		cin >> input;
		ans[i] = input;
	}
	int num = sizeof(expre)-1;
	SeqStack<char> stack2;
	int number=stack2.postfix(expre,num);
	cout << "��׺���ʽ��ֵΪ��";
	stack2.value(ans,number);
	system("pause");
}