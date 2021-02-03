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
    bool Find(int k, T& x) const;		//���ص�k��Ԫ�ص�x��
    int Length()const;		//�������
    int Search(const T& x) const;					//����x�ڱ��е�λ�ã��Żر������
    CircularList<T>& Insert(int k, const T& x);			//����x�ڵ�k������֮��
    CircularList<T>& Remove(int k, T& x);			//ɾ����k��Ԫ�ز�����������x


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
    ChainNode<T>* head;		//ָ����һ������ָ��
};



#endif
