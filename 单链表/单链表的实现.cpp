#pragma warning(disable:4996)
#include <iostream>
using namespace std;

template<class DataType>
struct Node
{
	DataType data;
	Node<DataType>*next;
};

template <class DataType>
class Linklist
{
public:
	Linklist();
	Linklist(DataType a[], int n);
	~Linklist();
	int Length();
	DataType Get(int i);
	int Locate(DataType x);
	void Insert(int i, DataType x);
	DataType Delete(int i);
	void PrintList();
private:
	Node<DataType>*first;
};

template<class DataType>
void Linklist <DataType>::PrintList()
{
	Node<DataType>*p = first->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

template<class DataType>
int Linklist<DataType>::Length()
{
	Node<DataType>*p = first->next;
	int count = 0;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}

template<class DataType>
DataType Linklist<DataType>::Get(int i)
{
	Node<DataType>*p = NULL;
	p = first->next;
	int count = 1;
	while (p != NULL && count < i)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)
	{
		throw"异常";
	}
	else
	{
		return p->data;
	}
}

template<class DataType>
int Linklist<DataType>::Locate(DataType x)
{
	Node<DataType>*p = first->next;
	int count = 1;
	while (p != NULL)
	{
		if (p->data == x)
		{
			return count;
		}
		p = p->next;
		count++;
	}
	return 0;
}

template<class DataType>
void Linklist<DataType>::Insert(int i, DataType x)
{
	Node<DataType>*p = first;
	int count = 0;
	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)
	{
		throw"位置";
	}
	else
	{
		Node<DataType>*s = new Node<DataType>;
		s->next = p->next;
		s->data = x;
		p->next = s;
	}
}

template<class DataType>
Linklist<DataType>::Linklist()
{
	first = new Node<DataType>;
	first->next = NULL;
}

template<class DataType>
Linklist<DataType>::Linklist(DataType a[], int n)
{
	first = new Node<DataType>;
	first->next = NULL;
	Node<DataType>*s;
	for (int i = 0; i < n; i++)
	{
		s = new Node<DataType>;
		s->data = a[i];
		s->next = first->next;
		first->next = s;
	}
}

template<class DataType>
DataType Linklist<DataType>::Delete(int i)
{
	Node<DataType>*p = first;
	int count = 0;
	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL || p->next == NULL)
	{
		throw"位置";
	}
	else
	{
		Node<DataType>*q = p->next;
		DataType x = q->data;
		p->next = q->next;
		delete q;
		return x;
	}
}

template<class DataType>
Linklist<DataType>::~Linklist()
{
	Node<DataType>*q = NULL;
	while (first != NULL)
	{
		q = first;
		first = first->next;
		delete q;
	}
}

void main()
{
	int a[] = { 16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 };
	Linklist<int>list(a, sizeof(a) / sizeof(a[0]));
	cout << "遍历单链表：";
	list.PrintList();
	cout << "单链表的长度为：" << list.Length() << endl;
	cout << "单链表第五个结点元素的值是：" << list.Get(5) << endl;
	cout << "单链表值为12的元素序号是：" << list.Locate(12) << endl;
	cout << "在第12个位置插入值为20的结点：";
	list.Insert(12, 20);
	list.PrintList();
	cout << endl;
	cout << "删除第十二个结点：";
	list.Delete(12);
	list.PrintList();
	cout << endl;
	system("pause");
}