#pragma once
#ifndef CHAIN__LIST_
#define CHAIN__LIST_
#include<iostream>
#include<stdlib.h>
#include "AbstractList.h"
#include <ostream>
//template<class T>
//class Chain;
//
//template<class T>
//ostream& operator<<(ostream& out, const Chain<T>& x);



template<class T>
class ChainNode {
	
public:
	T data;
	ChainNode<T>* link;

};


template<class T>
class Chain : AbstractList<T> {
public:
    Chain() { first = 0; }
    ~Chain();
    bool IsEmpty() const { return first == 0; }
    bool Find(int k, T& x) const override;		//���ص�k��Ԫ�ص�x��
    int Length()const;		//�������
    int Search(const T& x) const override;					//����x�ڱ��е�λ�ã��Żر������
    AbstractList<T>& Insert(int k, const T& x) override;			//����x�ڵ�k������֮��
    AbstractList<T>& Remove(int k, T& x) override;			//ɾ����k��Ԫ�ز�����������x


    friend std::ostream& operator << (std::ostream& out, const Chain<T>& x) {
        ChainNode<T>* current;
        for (current = x.first; current; current = current->link) {
            out << current->data << " ";
        }
        return out;
    }

private:
    ChainNode<T>* first;		//ָ���һ������ָ��
};



#endif