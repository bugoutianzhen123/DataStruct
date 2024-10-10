#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

// 定义链栈节点
struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

// 定义链栈类
class Stack
{
private:
    Node *top;
    int size;

public:
    // 初始化
    Stack() : top(nullptr), size(0) {}

    // 销毁
    ~Stack()
    {
        DestroyStack();
    }

    void DestroyStack()
    {
        while (top != nullptr)
        {
            Out();
        }
    }

    // 判断是否为空
    bool IsEmpty() const
    {
        return top == nullptr;
    }

    // 输出栈顶元素
    int Top() const
    {
        if (IsEmpty())
        {
            throw underflow_error("Stack is empty.");
        }
        return top->data;
    }

    // 入栈
    void Push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    // 出栈
    void Out()
    {
        if (IsEmpty())
        {
            throw underflow_error("Stack is empty.");
        }
        Node *temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    // 获取栈的大小
    int GetSize() const
    {
        return size;
    }
};

