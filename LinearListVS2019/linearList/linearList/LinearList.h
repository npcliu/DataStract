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
	T * element;			//�������
	int maxSize;		//�������ɱ��������
	int length;			//��ǰ�Ѵ��������λ��


public:
		LinearList(int maxListSize = defaultSize);
		LinearList(LinearList<T>& L) ;
		~LinearList() { delete[] element; }
		bool Find(int k, T& x) const override;		//���ص�k��Ԫ�ص�x��
		int Length()const { return length; }		//�������
		int Search(const T& x)const override;					//����x�ڱ��е�λ�ã��Żر������
		AbstractList<T>& Insert(int k, const T& x) override;			//����x�ڵ�k������֮��
		AbstractList<T>& Remove(int k, T& x) override;			//ɾ����k��Ԫ�ز�����������x
		bool IsEmpty()const { return length == 0; };					//�жϱ��Ƿ�Ϊ�գ���Ϊtrue
		//void output(ostream& out) const ;						//���
};

#endif