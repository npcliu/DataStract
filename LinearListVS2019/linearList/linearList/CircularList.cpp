
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
    //�ڴ���ͷ�ڵ��ѭ���б���Ѱ��x
    ChainNode<T>* current = head->link;
    ChainNode<T>* IsHead = 0;
    int index = 1;
    //head->data = x;//�ѱ�ͷ�����ݸ�ֵΪ1����ֹ������ѭ��
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
    //�ڵ�k��Ԫ��֮�����x
    if (k < 0) { cout << "��" << k << "��Ԫ�ز�����" << endl; exit(1); }
    //p����ָ���k�����
    ChainNode<T>* p = head->link;
    ChainNode<T>* IsHead = 0;
    int i = 0;
    if (k > 1) {
        //��p�ƶ�����k��Ԫ��
        for (int index = 1; index < k-1 && (IsHead != head); index++) {
            p = p->link;
            IsHead = p->link;
            i++;
        }
        if (k < i+1) { cout << "�����ڵ�k��Ԫ��" << endl; exit(1); }

        ChainNode<T>* y = new ChainNode<T>;
        y->data = x;
        if (k) {
            y->link = p->link;//�ѵ�k+1����㸳��y
            p->link = y;//��y��Ϊ��k������link
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

//����������
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