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
    bool Find(int k, T& x) const override;		//返回第k个元素到x中
    int Length()const;		//计算表长度
    int Search(const T& x) const override;					//搜索x在表中的位置，放回表项序号
    AbstractList<T>& Insert(int k, const T& x) override;			//插入x在第k个表项之后
    AbstractList<T>& Remove(int k, T& x) override;			//删除第k个元素并将它返回至x


    friend std::ostream& operator << (std::ostream& out, const Chain<T>& x) {
        ChainNode<T>* current;
        for (current = x.first; current; current = current->link) {
            out << current->data << " ";
        }
        return out;
    }

private:
    ChainNode<T>* first;		//指向第一个结点的指针
};



#endif