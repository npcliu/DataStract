#pragma once
#ifndef SEQUENTIAL__LIST_
#define SEQUENTIAL__LIST_
#include<iostream>
#include<stdlib.h>
#include "AbstractList.h"
const int defaultSize = 10;
template<class T>
class LinearList : public AbstractList<T> {
private:
	T * element;			//存放数组
	int maxSize;		//最大可容纳表项的项数
	int length;			//当前已存表项的最后位置


public:
		LinearList(int maxListSize = defaultSize);
		LinearList(LinearList<T>& L) ;
		~LinearList() { delete[] element; }
		bool Find(int k, T& x) const override;		//返回第k个元素到x中
		int Length()const { return length; }		//计算表长度
		int Search(const T& x)const override;					//搜索x在表中的位置，放回表项序号
		AbstractList<T>& Insert(int k, const T& x) override;			//插入x在第k个表项之后
		AbstractList<T>& Remove(int k, T& x) override;			//删除第k个元素并将它返回至x
		bool IsEmpty()const { return length == 0; };					//判断表是否为空，空为true
		//void output(ostream& out) const ;						//输出
};

#endif