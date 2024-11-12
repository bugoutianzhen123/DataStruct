#include <iostream>
#include <stdexcept>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// 循环队列
class CircularQueue
{
private:
    int *Base;
    int Front;
    int Rear;
    int Max;

public:
    CircularQueue(int max = 10)
    {
        Base = (int *)malloc(sizeof(int) * (max + 1));
        Front = Rear = 0;
        Max = max + 1;
    }
    ~CircularQueue()
    {
        delete Base;
    }

    // 判空
    bool JudgeIfEmpty()
    {
        return Rear == Front;
    }

    // 判满
    bool JudgeIfFull()
    {
        return (Rear + 1) % Max == Front;
    }

    // 入队
    CircularQueue &InQueue(int n)
    {
        if (JudgeIfFull())
        {
            cout << "The queue id already full" << endl;
            return *this;
        }
        Base[Rear++] = n;
        Rear = Rear % Max;
        return *this;
    }

    // 出队
    CircularQueue &OutQueue()
    {
        if (JudgeIfEmpty())
        {
            cout << "The queue id already empty" << endl;
            return *this;
        }
        Front = (Front + 1) % Max;
        return *this;
    }

    // 打印整个队列
    CircularQueue &Print()
    {
        for (int n = Front; n != Rear;)
        {
            printf("%d ", Base[n++]);
            n = n % Max;
        }
        printf("\n");
        return *this;
    }

    // 获取队列长度
    int Length()
    {
        int l = Rear - Front;
        return l < 0 ? l + Max : l;
    }

    // 获取队头元素
    CircularQueue &GetHead(int *n)
    {
        if (JudgeIfEmpty())
        {
            cout << "The queue id already empty" << endl;
            return *this;
        }
        *n = Base[Front];
        return *this;
    }
};

// 双端队列
struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoubleQueue
{
private:
    Node *Front;
    Node *Rear;

public:
    DoubleQueue()
    {
        Front = nullptr;
        Rear = nullptr;
    }
    ~DoubleQueue()
    {
        while (Front)
        {
            OutFront();
        }
    }

    // 判空
    bool JudgeEmpty()
    {
        return Front == nullptr;
    }

    // 头入
    DoubleQueue &InFront(int value)
    {
        Node *newNode = new Node(value);
        if (!Front)
        {
            Front = Rear = newNode;
            return *this;
        }
        newNode->next = Front;
        Front->prev = newNode;
        Front = newNode;
        return *this;
    }

    // 头出
    DoubleQueue &OutFront()
    {
        if (!Front)
        {
            cout << "The queue id already empty" << endl;
            return *this;
        }
        Node *temp = Front;
        Front = Front->next;
        if (Front)
        {
            Front->prev = nullptr;
        }
        else
        {
            Rear = nullptr;
        }
        delete temp;
        return *this;
    }

    // 尾入
    DoubleQueue &InRear(int value)
    {
        Node *newNode = new Node(value);
        if (!Rear)
        {
            Front = Rear = newNode;
            return *this;
        }
        newNode->prev = Rear;
        Rear->next = newNode;
        Rear = newNode;
        return *this;
    }

    // 尾出
    DoubleQueue &OutRear()
    {
        if (!Rear)
        {
            cout << "The queue id already empty" << endl;
            return *this;
        }
        Node *temp = Rear;
        Rear = Rear->prev;
        if (Rear)
        {
            Rear->next = nullptr;
        }
        else
        {
            Front = nullptr;
        }
        delete temp;
        return *this;
    }

    // 获取队头元素
    DoubleQueue &GetFront(int *n)
    {
        if (!Front)
        {
            cout << "The queue id already empty" << endl;
            return *this;
        }
        *n = Front->data;
        return *this;
    }
    // 获取队尾元素
    DoubleQueue &GetRear(int *n)
    {
        if (!Rear)
        {
            cout << "The queue id already empty" << endl;
            return *this;
        }
        *n = Rear->data;
        return *this;
    }
    // 打印队列
    DoubleQueue &Print()
    {
        Node *head = Front;
        while (head)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
        return *this;
    }

    // 获取队列长度
    int Length()
    {
        Node *head = Front;
        int i = 0;
        while (head)
        {
            i++;
            head = head->next;
        }
        return i;
    }
};