#ifndef SEQSTACK__H_
#define SEQSTACK__H_

template <class Type>
class SeqStack {
private :
	int top;
	Type* stacka;		//用数组存储栈中元素
	int maxSize;

public:
	SeqStack(int size);
	~SeqStack(){ delete[] stacka; }
	void push(const Type& item);
	Type pop(void);
	Type getTop();
	int empty(void)const { return top == -1; }
	int full() const { return top == maxSize - 1; }
	void clear() { top = -1; }

};

#endif // !SEQSTACK__H_

