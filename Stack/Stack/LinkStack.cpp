

#include <iostream>
#include "LinkStack.h"
using namespace std;


template<class Type>
inline void LinkStack<Type>::push(const Type& item)
{
	top = new Node<Type>(item, top);
}

template<class Type>
int LinkStack<Type>::pop(void)
{
	if (top == NULL) {
		cout << "Õ»ÒÑ¿Õ£¡" << endl;
		exit(1);
	}
	Node<Type>* p = top;
	Type item = top->data;
	top = p->next;
	delete p;
	return item;
	
}

template<class Type>
Type LinkStack<Type>::getTop()
{
	if (top == NULL) {
		cout << "¿ÕÕ»" << endl;
		exit(1);
	}
	return top->data;
}

//int main()
//{
//	LinkStack<int> ls;
//	ls.push(1);
//	cout<<ls.getTop();
//	ls.pop();
//	ls.getTop();
//
//
//	return 0;
//}