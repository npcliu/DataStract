
#include <iostream>
#include "Chain.h"

using namespace std;



template<class T>
Chain<T>::~Chain() 
{
    ChainNode<T>* next;
    while (first) {
        next = first->link;
        delete first;
        first = next;
    }
}

template<class T>
int Chain<T>::Length() const
{
    ChainNode<T>* current = first;
    int len = 0;
    while (current) {
        len++;
        current = current->link;
    }
    return len;
}



template<class T>
bool Chain<T>::Find(int k, T& x) const
{
    //Ѱ�������е�k��Ԫ�أ�����ֵ����x
    if (k < 1)return false;
    ChainNode<T>* current = first;
    int index = 1;
    while (index < k && current) {
        current = current->link;
        index++;
    }
    if (current) {
        x = current->data;
        return true;
    }
    return false;
}

template<class T>
int Chain<T>::Search(const T& x) const {
    //Ѱ��x,�������x���򷵻�x�ĵ�ַ
    //���x���������У��򷵻�0
    ChainNode<T>* current = first;
    int index = 1;
    while (current && current->data != x) {
        current = current->link;
        index++;

    }
    if (current) return index;
    return 0;
    
}

template<class T>
AbstractList<T>& Chain<T>::Remove(int k, T& x)
{//�ѵ�k��Ԫ��ȡ��x,Ȼ���������ɾ����k��Ԫ��
    //��������ڵ�k��Ԫ�أ��������쳣
    if (k < 1 || !first) { cout << "�����ڵ�k��Ԫ��" << endl; exit(1); }
    ChainNode<T>* p = first;
    if (k == 1)first = first->link;
    else
    {
        ChainNode<T>* q = first;
        for (int index = 1; index < k - 1 && q; index++)
            q = q->link;
        if (!q || q->link) { cout << "�����ڵ�k��Ԫ��" << endl; exit(1); }
        p = q->link;
        q->link = p->link;//������ɾ����k��Ԫ��
    }
    x = p->data;
    delete p;
    return *this;
}



template<class T>
AbstractList<T>& Chain<T>::Insert(int k, const T& x)
{
    //�ڵ�k��Ԫ��֮�����x
    if(k<0) { cout << "��"<<k<<"��Ԫ�ز�����" << endl; exit(1); }
    //p����ָ���k�����
    ChainNode<T>* p = first;
    //��p�ƶ�����k��Ԫ��
    for (int index = 1; index < k && p; index++) {
        p = p->link;
    }
    if (k > 0 && !p) { cout << "�����ڵ�k��Ԫ��" << endl; exit(1); }
    ChainNode<T>* y = new ChainNode<T>;
    y->data = x;
    if (k) {
        y->link = p->link;//�ѵ�k+1����㸳��y
        p->link = y;//��y��Ϊ��k������link
    }
    else {
        y->link = first;
        first = y;
    }
    return *this;
}


//����������
int main()
{
    std::cout << "Hello World!\n";
    Chain<int> chain;
    chain.Insert(0, 5);
    chain.Insert(1, 5).Insert(2,10);
    int x;
    //x = chain.Length();
    //x = chain.Search(5);
    chain.Find(2, x);
    cout << x;
    chain.Remove(1, x);
    cout << chain;
}