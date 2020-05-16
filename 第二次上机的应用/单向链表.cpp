#pragma warning(disable:4996)
#include <iostream>
using namespace std;
#define MAX 10
template<class DataType>
struct Node
{
	DataType data;
	Node<DataType>* next;
};

template<class DataType>
class LinkList
{
public:
	LinkList();
	LinkList(DataType a[], int n);
	~LinkList();
	void PrintList();
	void Reverse();
	void Del_even();
	void Insert(DataType x);
	void Insert(LinkList<DataType> list);
private:
	Node<DataType>* first;
	DataType* p_reserve = new DataType[n_sign];
	int n_sign;
};

template<class DataType>
LinkList<DataType>::LinkList()
{
	first = new Node<DataType>;
	first->next = NULL;
}

template<class DataType>
LinkList<DataType>::LinkList(DataType a[], int n)
{
	int m = 0;
	n_sign = n;
	for (int j = n - 1; j >= 0; j--)
	{
		p_reserve[m] = a[j];
		m++;
	}
	first = new Node<DataType>;
	Node<DataType>*r = first;
	for (int i = 0; i < n; i++)
	{
		Node<DataType>*s = new Node<DataType>;
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

template<class DataType>
LinkList<DataType>::~LinkList()
{
	while (first != NULL)
	{
		Node<DataType>*q = first;
		first = first->next;
		delete q;
	}
}

template<class DataType>
void LinkList<DataType>::PrintList()
{
	Node<DataType>*p = first->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

template<class DataType>
void LinkList<DataType>::Reverse()
{
	int i = 0;
	while (i < n_sign)
	{
		cout << p_reserve[i] << " ";
		i++;
	}
}

template<class DataType>
void LinkList<DataType>::Del_even()
{
	Node<DataType>* p = first;
	while ((p != NULL) && (p->next != NULL))
	{
		if (p->next->data % 2 == 0)
		{
			Node<DataType>*q = p->next;
			p->next = q->next;
			delete q;
		}
		else
		{
			p = p->next;
		}
	}
}

template<typename T>
void List_sort(T a[], int n)
{
	int i, j;
	bool exchange;
	for ( i = 0; i < n-1; i++)
	{
		exchange = false;
		for ( j = n-1; j >i; j--)
		{
			if (a[j]<a[j-1])
			{
				int tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
				exchange = true;
			}
		}
		if (exchange==false)
		{
			return;
		}
	}
}

template<class DataType>
void LinkList<DataType>::Insert(DataType x)
{
	Node<DataType>*p = first;
	while (p->next->data<x&&p!=NULL)
	{
		p = p->next;
	}
	Node<DataType>*s = new Node<DataType>;
	s->data = x;
	s->next = p->next;
	p->next = s;
}

template<class DataType>
void LinkList<DataType>::Insert(LinkList<DataType> list)
{
	Node<DataType>*p = list.first;
	while ((p->next)!=NULL)
	{
		this->Insert(p->next->data);
		p = p->next;
	}
	this->PrintList();
}

void main()
{
	int a[MAX],num;
	cout << "请输入十个整数（用空格分开）存入单向链表：";
	for (int i = 0; i < MAX; i++)
	{
		cin >> num;
		a[i] = num;
	}
	LinkList <int>list(a, sizeof(a) / sizeof(a[0]));
	cout << "建立一个带头结点的单向链表其中输入的元素为：";
	list.PrintList();
	puts(" ");
	cout << "逆置如上的单向链表:";
	list.Reverse();
	puts(" ");
	cout << "删除顺序表中所有的偶数";
	list.Del_even();
	list.PrintList();
	puts(" ");
	int b[MAX], num2;
	cout << "请输入你想建立的十个元素递增有序链表（顺序可以打乱）：";
	for (int i = 0; i < MAX; i++)
	{
		cin >> num2;
		b[i] = num2;
	}
	List_sort(b, sizeof(b) / sizeof(b[0]));
	LinkList<int> list2(b, sizeof(b) / sizeof(b[0]));
	cout << "建立的非递减有序表为：";
	list2.PrintList();
	puts(" ");
	int num_insert;
	cout << "请输入你要插入的元素：";
	cin >> num_insert;
	cout << "插入该元素后上述非递减有序表为：";
	list2.Insert(num_insert);
	list2.PrintList();
	puts(" ");
	int c[5], num3;
	int d[5], num4;
	cout << "请输入第一个表中你想放入的5个元素(顺序可以打乱）：";
	for (int i = 0; i < 5; i++)
	{
		cin >> num3;
		c[i] = num3;
	}
	List_sort(c, sizeof(c) / sizeof(c[0]));
	LinkList<int>list3(c, sizeof(c) / sizeof(c[0]));
	cout << "第一个表为：";
	list3.PrintList();
	puts(" ");
	cout << "请输入第二个表中你想放入的5个元素(顺序可以打乱）：";
	for (int i = 0; i < 5; i++)
	{
		cin >> num4;
		d[i] = num4;
	}
	List_sort(d, sizeof(d) / sizeof(d[0]));
	LinkList<int>list4(d, sizeof(d) / sizeof(d[0]));
	cout << "第二个表为：";
	list4.PrintList();
	puts(" ");
	cout << "合并两个表后的元素为：";
	list4.Insert(list3);
	system("pause");
}