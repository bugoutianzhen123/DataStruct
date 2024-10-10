#include <iostream>
#include <cstring>

using namespace std;

// 学生类，包含学生的基本信息
class Student
{
public:
    char no[9];    // 学号
    char name[11]; // 姓名
    int score;     // 成绩
    int time;      // 时间

    // 构造函数
    Student(const char *n, const char *nm, int sc, int t)
    {
        strncpy(no, n, sizeof(no));
        strncpy(name, nm, sizeof(name));
        score = sc;
        time = t;
    }
};

// 双向循环链表节点类
class DulNode
{
public:
    Student stu;    // 学生信息
    DulNode *prior; // 指向前一个节点的指针
    DulNode *next;  // 指向下一个节点的指针

    // 构造函数
    DulNode(const Student &student) : stu(student), prior(nullptr), next(nullptr) {}
};

// 双向循环链表类
class DulCircularLinkedList
{
private:
    DulNode *head; // 链表头节点

public:
    // 构造函数
    DulCircularLinkedList()
    {
        head = new DulNode(Student("", "", 0, 0)); // 创建一个虚拟头节点
        head->next = head;                         // 初始化指向自身
        head->prior = head;                        // 初始化指向自身
    }
    // 析构函数
    ~DulCircularLinkedList()
    {
        if (head)
        {
            DulNode *current = head->next;
            while (current != head)
            {
                DulNode *nextNode = current->next; // 保存下一个节点
                delete current;                    // 删除当前节点
                current = nextNode;                // 移动到下一个节点
            }
            delete head; // 删除头节点
        }
    }

    // 插入节点
    DulCircularLinkedList &insert(const Student &student);
    // 打印链表内容
    void print() const;
    // 排序链表
    DulCircularLinkedList &sort();

private:
    // 分区函数，用于快速排序
    DulNode *partition(DulNode *low, DulNode *high);
    // 递归快速排序
    void quickSort(DulNode *low, DulNode *high);
};