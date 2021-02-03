#ifndef CIRCULAR__LIST_
#define CIRCULAR__LIST_
#include<iostream>
#include<stdlib.h>
#include "AbstractList.h"
#include <ostream>
#include "Chain.h"

template<class T>
class CircularList {
public:
    CircularList() { head = new ChainNode<T>; head->link = head; head->data = 0; };
    //CircularList(const T& item);
    ~CircularList();
    bool IsEmpty() const { return head == 0; }
    bool Find(int k, T& x) const;		//返回第k个元素到x中
    int Length()const;		//计算表长度
    int Search(const T& x) const;					//搜索x在表中的位置，放回表项序号
    CircularList<T>& Insert(int k, const T& x);			//插入x在第k个表项之后
    CircularList<T>& Remove(int k, T& x);			//删除第k个元素并将它返回至x


    friend std::ostream& operator << (std::ostream& out, const CircularList<T>& x) {
        ChainNode<T>* current = x.head;
        ChainNode<T>* IsHead = 0;
        for (current = x.head; current&&(IsHead != x.head); current = current->link) {
            out << current->data << " ";
            IsHead = current->link;
        }
        return out;
    }

private:
    ChainNode<T>* head;		//指向下一个结点的指针
};



#endif
