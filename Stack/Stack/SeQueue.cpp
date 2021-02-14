
#include <iostream>
#include "SeQueue.h"
using namespace std;

template<class Type>
inline SeQueue<Type>::SeQueue(int size):front(-1),rear(-1),maxSize(size)
{
	queue = new Type[maxSize];
	if (queue == NULL) {
		cout << "��̬�ڴ����ʧ��" << endl;
		exit(1);
	}
}

template<class Type>
void SeQueue<Type>::enQueue(const Type& item)
{//�������δ������Ԫ�ز����β������OK
	if (rear == maxSize - 1)
		exit(1);
	else {
		rear = rear + 1;
		queue[rear] = item;
		
	}
	
}

template<class Type>
Type SeQueue<Type>::deQueue()
{
	Type x;
	if (front == rear) {
		cout << "����Ϊ��" << endl;
		exit(1);
	}
	else {
		front = front + 1;
		x = queue[front];
		return x;
	}
	
}

template<class Type>
bool SeQueue<Type>::empty()
{
	return front == rear;
}

int main()
{
	SeQueue<int> sq(20);
	sq.enQueue(1);
	sq.enQueue(2);
	int x = sq.deQueue();
	cout << x;
	return 0;
}