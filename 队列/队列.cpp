#pragma warning(disable:4996)
#include <iostream>
using namespace std;

const int QueueSize = 100;
template<class DataType>
class CirQueue
{
public:
	CirQueue() { front = rear =QueueSize - 1; }
	~CirQueue(){}
	void EnQueue(DataType x);
	DataType DeQueue();
	DataType GetQueue();
	void Empty() { if (front == rear) { cout << "��" << endl;} else { cout << "�ǿ�" << endl; } }

private:
	DataType data[QueueSize];
	int front, rear;
};

template <class DataType>
void CirQueue<DataType>::EnQueue(DataType x)
{
	if ((rear+1)%QueueSize==front)
	{
		throw"����";
	}
	rear = (rear + 1) % QueueSize;
	data[rear] = x;
}

template<class DataType>
DataType CirQueue<DataType>::DeQueue()
{
	if (rear==front)
	{
		throw"����";
	}
	front = (front + 1) % QueueSize;
	return data[front];
}

template<class DataType>
DataType CirQueue<DataType>::GetQueue()
{
	if (rear==front)
	{
		throw"����";
	}
	int i = (front + 1) % QueueSize;
	return data[i];
}

void main()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	CirQueue<int> queue;
	for (int i = 0; i < 10; i++)
	{
		queue.EnQueue(a[i]);
	}
	cout << "��Ӻ��һ��Ԫ��Ϊ:" <<queue.GetQueue()<< endl;
	queue.DeQueue();
	cout << "ɾ����һ��Ԫ�غ��ͷ�ǣ�" << queue.GetQueue() << endl;
	cout << "�����Ƿ�Ϊ�գ�";
	queue.Empty();
	system("pause");
}