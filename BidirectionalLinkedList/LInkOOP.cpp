#include "LinkOOP.h"

// 插入节点
DulCircularLinkedList &DulCircularLinkedList::insert(const Student &student)
{
    DulNode *newNode = new DulNode(student); // 创建新节点
    DulNode *tail = head->prior;             // 获取当前链表的尾节点

    tail->next = newNode;  // 将新节点添加到尾部
    newNode->prior = tail; // 更新新节点的前驱指针
    newNode->next = head;  // 新节点指向头节点
    head->prior = newNode; // 头节点的前驱指针指向新节点
    return *this;
}

// 打印链表内容
void DulCircularLinkedList::print() const
{
    DulNode *current = head->next; // 从头节点的下一个节点开始
    while (current != head)
    {
        cout << "No: " << current->stu.no << ", Name: " << current->stu.name
             << ", Score: " << current->stu.score << ", Time: " << current->stu.time << endl;
        current = current->next; // 移动到下一个节点
    }
}

// 分区函数，用于快速排序
DulNode *DulCircularLinkedList::partition(DulNode *low, DulNode *high)
{
    int pivotScore = high->stu.score;
    int pivotTime = high->stu.time;
    DulNode *i = low->prior; // 初始化 i 为 low 的前一个节点

    for (DulNode *j = low; j != high; j = j->next)
    {
        // 按照成绩从高到低排序，成绩相同则按照时间升序排序
        if (j->stu.score > pivotScore ||
            (j->stu.score == pivotScore && j->stu.time < pivotTime))
        {
            i = (i == nullptr) ? low : i->next; // 如果 i 为 null，指向 low
            swap(i->stu, j->stu);               // 交换 i 和 j 的学生信息
        }
    }
    i = (i == nullptr) ? low : i->next; // 更新 i
    swap(i->stu, high->stu);            // 交换基准和 i 指向的节点
    return i;                           // 返回分区后的基准节点
}

// 递归快速排序
void DulCircularLinkedList::quickSort(DulNode *low, DulNode *high)
{
    if (high != nullptr && low != high && low != high->next)
    {
        DulNode *p = partition(low, high); // 获取分区后的基准节点
        quickSort(low, p->prior);          // 递归对基准节点左侧排序
        quickSort(p->next, high);          // 递归对基准节点右侧排序
    }
}

// 排序链表
DulCircularLinkedList &DulCircularLinkedList::sort()
{
    if (head->next != head)
    {                                // 确保链表不为空
        DulNode *tail = head->prior; // 获取链表的尾节点
        quickSort(head->next, tail); // 对链表进行快速排序
    }
    return *this;
}

int main()
{
    DulCircularLinkedList list; // 创建链表实例

    // 插入示例数据
    list.insert(Student("001", "Alice", 85, 1)).insert(Student("002", "Bob", 92, 2)).insert(Student("003", "Charlie", 85, 3));
    list.insert(Student("004", "David", 90, 4)).insert(Student("005", "Eve", 90, 1));

    cout << "Before sorting:" << endl;
    list.print();
    cout << "After sorting by score (high to low) and time (low to high):" << endl;

    list.sort().print();

    return 0;
}