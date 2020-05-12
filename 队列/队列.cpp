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
	void Empty() { if (front == rear) { cout << "空" << endl;} else { cout << "非空" << endl; } }

private:
	DataType data[QueueSize];
	int front, rear;
};

template <class DataType>
void CirQueue<DataType>::EnQueue(DataType x)
{
	if ((rear+1)%QueueSize==front)
	{
		throw"上溢";
	}
	rear = (rear + 1) % QueueSize;
	data[rear] = x;
}

template<class DataType>
DataType CirQueue<DataType>::DeQueue()
{
	if (rear==front)
	{
		throw"下溢";
	}
	front = (front + 1) % QueueSize;
	return data[front];
}

template<class DataType>
DataType CirQueue<DataType>::GetQueue()
{
	if (rear==front)
	{
		throw"下溢";
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
	cout << "入队后第一个元素为:" <<queue.GetQueue()<< endl;
	queue.DeQueue();
	cout << "删除第一个元素后队头是：" << queue.GetQueue() << endl;
	cout << "队列是否为空：";
	queue.Empty();
	system("pause");
}