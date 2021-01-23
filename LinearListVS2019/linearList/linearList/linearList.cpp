// linearList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "LinearList.h"

using namespace std;
template<class T>
LinearList<T>::LinearList(int maxListSize)
{
    maxSize = maxListSize;
    element = new T[maxSize];
    length = 0;
}

template<class T>
bool LinearList<T>::Find(int k,T& x) const
{
    if (k<1 || k>length) return false;
    x = element[k - 1];
    return true;
}

template<class T>
int LinearList<T>::Search(const T& x) const{
    for (int i = 0; i < length; i++) {
        if (element[i] == x) return ++i;

    }
    return 0;
}

template<class T>
AbstractList<T>& LinearList<T>::Insert(int k, const T& x)
{
    //在第k个元素之后插入x
    if (k<0 || k>length) { cout << "未找到第k个位置" << endl; exit(1); }
    if (length == maxSize) { cout << "线性表已满" << endl; exit(1); }
    if (length > 0) {
        //向前移动一个位置
        for (int i = length - 1; i <= k; i--) {
            element[i + 1] = element[i];
        }
    }
    element[k] = x;
    length++;
    return *this;
}

template<class T>
AbstractList<T>&  LinearList<T>::Remove(int k, T& x)
{
    
    //把第k个元素放到x中，然后删除第k个元素
    //如果不存在第k个元素，则引发异常
    if (LinearList<T>::Find(k, x)) {
        for (int i = k; i < length; i++) {
            element[i - 1] = element[i];
            length--;
            return *this;
        }
    }
    else {
        cout << "未找到第k个元素" << endl;
        exit(1);
    }
}



int main()
{
    std::cout << "Hello World!\n";
    

    try {
        LinearList<int> L(5);
        cout << "length = " << L.Length() << endl;
        cout << "isImpty = " << L.IsEmpty() << endl;
        L.Insert(0, 2);
        cout << "isImpty " << L.IsEmpty() << endl;
        int z;
        L.Find(1, z);
        cout << "first element is " << z << endl;
        L.Remove(1, z);
        cout << "delete element is " << z << endl;
        

    }
    catch (exception e) {
        cerr << "An exception has occurred" << endl;
    }
    //Seq.reSize(3);
    //Seq.printfData();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
