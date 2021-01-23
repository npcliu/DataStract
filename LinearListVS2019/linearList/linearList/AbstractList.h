#pragma once
#ifndef LINEAR__LIST_
#define LINEAR__LIST_
#include<iostream>
#include<stdlib.h>
typedef bool BOOL;
template <class T>
class AbstractList {
public:
    //LinearList() {}
    //~LinearList() {}
        virtual bool Find(int k, T& x) const = 0;
        virtual int Length()const = 0;
        virtual int Search(const T& x)const = 0;
        virtual AbstractList<T>& Insert(int k, const T& x) = 0;
        virtual AbstractList<T>& Remove(int k, T& x) = 0;
        virtual bool IsEmpty()const = 0;
        //virtual void output(ostream& out)const = 0;
    //virtual LinearList<T> operator=(LinearList<T>& L)=0;//复制 该函数未实现定义
    
};
#endif

