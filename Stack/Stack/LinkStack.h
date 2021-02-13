#ifndef LINKSTACK__H_
#define LINKSTACK__H_

template<class Type> class LinkStack;
template<class Type>
class Node {
	friend class LinkStack<Type>;
private:
	Type data;
	Node<Type>* next;

public:
	Node(Type d = 0, Node<Type>* ls = NULL) :data(d), next(ls) {}
};

template<class Type>
class LinkStack {

private:
	Node<Type>* top;
public:
	LinkStack() :top(NULL) {}
	void push(const Type& item);
	int pop(void);
	Type getTop();
};

#endif
