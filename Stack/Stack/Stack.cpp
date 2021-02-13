// Stack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "SeqStack.h"
using namespace std;


template<class Type>
inline SeqStack<Type>::SeqStack(int size):top(-1),maxSize(size)
{//建立一个最大尺寸为size的空栈
    stacka = new Type[size];
    if (stacka == NULL) {
        cout << "动态存储分配失败" << endl;
        exit(1);
    }

}

template<class Type>
void SeqStack<Type>::push(const Type& item)
{//如果栈已满，则进行出错处理，否则把item入栈
    if (full()) {
        cout << "栈已满，无法入栈" << endl;
        exit(1);
    }
    top++;
    stacka[top] = item;

}

template<class Type>
Type SeqStack<Type>::pop(void)
{//如果栈为空，则出错，否则出栈，并返回栈顶元素
    if (empty()) {
        cout << "栈已空，无法出栈" << endl;
        exit(1);
    }
    Type data = stacka[top];
    top--;

    return data;
}

template<class Type>
Type SeqStack<Type>::getTop()
{//如果栈不空，返回栈顶元素
    if (empty()) {
        cout << "栈空！" << endl;
        exit(1);
    }
    return stacka[top];
    
}




//int main()
//{
//    SeqStack<int> stack(5);
//    cout << stack.empty() << endl;
//    stack.push(1);
//    cout << stack.getTop() << endl;
//    stack.push(2);
//    cout << stack.getTop() << endl;
//    stack.pop();
//    cout << stack.getTop() << endl;
//
//
//
//}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
