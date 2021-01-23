
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
    //寻找链表中第k个元素，并将值传至x
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
    //寻找x,如果发现x，则返回x的地址
    //如果x不在链表中，则返回0
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
{//把第k个元素取至x,然后从链表中删除第k个元素
    //如果不存在第k个元素，则引发异常
    if (k < 1 || !first) { cout << "不存在第k个元素" << endl; exit(1); }
    ChainNode<T>* p = first;
    if (k == 1)first = first->link;
    else
    {
        ChainNode<T>* q = first;
        for (int index = 1; index < k - 1 && q; index++)
            q = q->link;
        if (!q || q->link) { cout << "不存在第k个元素" << endl; exit(1); }
        p = q->link;
        q->link = p->link;//从链表删除第k个元素
    }
    x = p->data;
    delete p;
    return *this;
}



template<class T>
AbstractList<T>& Chain<T>::Insert(int k, const T& x)
{
    //在第k个元素之后插入x
    if(k<0) { cout << "第"<<k<<"个元素不存在" << endl; exit(1); }
    //p最终指向第k个结点
    ChainNode<T>* p = first;
    //将p移动至第k个元素
    for (int index = 1; index < k && p; index++) {
        p = p->link;
    }
    if (k > 0 && !p) { cout << "不存在第k个元素" << endl; exit(1); }
    ChainNode<T>* y = new ChainNode<T>;
    y->data = x;
    if (k) {
        y->link = p->link;//把第k+1个结点赋给y
        p->link = y;//把y作为第k个结点的link
    }
    else {
        y->link = first;
        first = y;
    }
    return *this;
}


//测试链表用
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