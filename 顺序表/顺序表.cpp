#pragma warning(disable:4996)
#include <iostream>
using namespace std;
const int Maxsize = 100;
template<class  DataType>
class SeqList
{
public:
	SeqList()
	{
		length = 0;
	}
	~SeqList()
	{

	}
	int Length()
	{
		return length;
	}
public:
	SeqList(DataType a[], int n);
	DataType Get(int i);
	int Location(DataType x);
	void Insert(int i, DataType x);
	DataType Delete(int i);
	void PrintList();
private:
	DataType data[Maxsize];
	int length;
};

template<class DataType>
SeqList<DataType>::SeqList(DataType a[], int n)
{
	if (n > Maxsize)
	{
		throw"�����Ƿ�";
	}
	for (int i = 0; i < n; i++)
	{
		data[i] = a[i];
	}
	length = n;
}

template<class DataType>
DataType SeqList<DataType>::Get(int i)
{
	if (i<1 && i>length)
	{
		throw"����λ�÷Ƿ�";
	}
	else
	{
		return data[i - 1];
	}
}

template<class DataType>
int SeqList<DataType>::Location(DataType x)
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == x)
		{
			return i + 1;
		}
	}
	return 0;
}

template<class DataType>
void SeqList<DataType>::Insert(int i, DataType x)
{
	if (length > Maxsize)
	{
		throw"����";
	}
	if (i<1 || i>length)
	{
		throw"λ��";
	}
	for (int j = length; j >= i; j--)
	{
		data[j] = data[j - 1];
	}
	data[i - 1] = x;
	length++;
}

template<class DataType>
DataType SeqList<DataType>::Delete(int i)
{
	if (length == 0)
	{
		throw"����";
	}
	if (i > length)
	{
		throw"λ��";
	}
	DataType x = data[i - 1];
	for (int j = i; j < length; j++)
	{
		data[j - 1] = data[j];
	}
	length--;
	return x;
}

template<class DataType>
void SeqList<DataType>::PrintList()
{
	for (int i = 0; i < length; i++)
	{
		cout << data[i] << " ";
	}
}

void main()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	SeqList<int>list(a, sizeof(a) / sizeof(a[0]));
	cout << "���Ա�ĳ��ȣ�" << list.Length() << endl;
	cout << "���Ա��ʮ��Ԫ��Ϊ��" << list.Get(10) << endl;
	cout << "���Ա�ֵΪ15��Ԫ��λ���ǣ�" << list.Location(15) << endl;
	cout << "�ڵ����λ�ò���20��";
	list.Insert(5, 20);
	list.PrintList();
	cout << endl;
	cout << "ɾ�������λ�õ�Ԫ�أ�";
	list.Delete(5);
	list.PrintList();
	system("pause");
}