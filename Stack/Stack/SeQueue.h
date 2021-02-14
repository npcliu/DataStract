#ifndef LINKSTACK__H_
#define LINKSTACK__H_

template<class Type>
class SeQueue {

private:
	int rear, front;
	Type* queue;
	int maxSize;
public:
	SeQueue(int size = 10);
	~SeQueue() { delete[] queue; }
	void enQueue(const Type& item);
	Type deQueue();
	bool empty();
};

#endif


