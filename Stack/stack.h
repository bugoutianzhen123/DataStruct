#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

// 定义链栈节点
template <typename T>
struct Node
{
    T data;
    Node *next;

    Node(T val) : data(val), next(nullptr) {}
};

// 定义链栈类
template <typename T>
class StackLink
{
private:
    Node<T> *top;
    int size;

public:
    // 初始化
    StackLink() : top(nullptr), size(0) {}

    // 销毁
    ~StackLink()
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
    int Top() 
    {
        if (IsEmpty())
        {
            throw underflow_error("Stack is empty.");
        }
        return top->data;
    }

    // 入栈
    void Push(T value)
    {
        Node<T> *newNode = new Node<T>(value);
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
        Node<T> *temp = top;
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
