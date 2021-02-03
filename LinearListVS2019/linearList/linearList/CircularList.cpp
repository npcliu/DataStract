
#include <iostream>
#include "CircularList.h"


using namespace std;



template<class T>
CircularList<T>::~CircularList()
{
    ChainNode<T>* next;
    while (head) {
        next = head->link;
        delete head;
        head = next;
    }
}

template<class T>
int CircularList<T>::Search(const T& x) const {
    //在带有头节点的循环列表中寻找x
    ChainNode<T>* current = head->link;
    ChainNode<T>* IsHead = 0;
    int index = 1;
    //head->data = x;//把表头的数据赋值为1，防止程序死循环
    while (current && current->data != x && IsHead!=head) {
        current = current->link;
        index++;
        IsHead = current->link;

    }
    return ((current == head) ? 0 : index);
}


template<class T>
CircularList<T>& CircularList<T>::Insert(int k, const T& x)
{
    //在第k个元素之后插入x
    if (k < 0) { cout << "第" << k << "个元素不存在" << endl; exit(1); }
    //p最终指向第k个结点
    ChainNode<T>* p = head->link;
    ChainNode<T>* IsHead = 0;
    int i = 0;
    if (k > 1) {
        //将p移动至第k个元素
        for (int index = 1; index < k-1 && (IsHead != head); index++) {
            p = p->link;
            IsHead = p->link;
            i++;
        }
        if (k < i+1) { cout << "不存在第k个元素" << endl; exit(1); }

        ChainNode<T>* y = new ChainNode<T>;
        y->data = x;
        if (k) {
            y->link = p->link;//把第k+1个结点赋给y
            p->link = y;//把y作为第k个结点的link
        }
        else {
            y->link = head;
            head = y;
        }
    }
    else {
        ChainNode<T>* y = new ChainNode<T>;
        y->data = x;
        y->link = p;
        head->link = y;
    }
    head->data++;
    return *this;
}

//测试链表用
int main()
{
    std::cout << "Hello World!\n";
    CircularList<int> CircularList;
    CircularList.Insert(1, 1);
    CircularList.Insert(2, 2);
    CircularList.Insert(3, 3);
    CircularList.Insert(4, 4);
    int x = CircularList.Search(1);
    cout << x << endl;
    cout << CircularList;
    while (1);
    return 0;

}