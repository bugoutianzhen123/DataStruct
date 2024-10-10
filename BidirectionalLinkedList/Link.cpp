#include "head.h"

DulLinkList createList()
{
    DulLinkList head = new DulNode();
    head->prior = nullptr;
    head->next = nullptr;
    return head;
}

void insertNode(DulLinkList &list, STUDENT student)
{
    DulNode *newNode = new DulNode();
    newNode->Stu = student;
    newNode->next = nullptr;

    DulNode *tail = list;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->prior = tail;
}

void printList(DulLinkList list)
{
    DulNode *current = list->next; // Skip the head
    while (current != nullptr)
    {
        cout << "No: " << current->Stu.no << ", Name: " << current->Stu.name
             << ", Score: " << current->Stu.score << ", Time: " << current->Stu.time << endl;
        current = current->next;
    }
}

DulNode *partition(DulNode *low, DulNode *high)
{
    int pivot = high->Stu.score;
    DulNode *i = low->prior; // Initialize i to before the first element

    for (DulNode *j = low; j != high; j = j->next)
    {
        if (j->Stu.score < pivot)
        {
            i = (i == nullptr) ? low : i->next;
            swap(i->Stu, j->Stu);
        }
    }
    i = (i == nullptr) ? low : i->next;
    swap(i->Stu, high->Stu);
    return i; // Return the partitioning index
}

void quickSort(DulNode *low, DulNode *high)
{
    if (high != nullptr && low != high && low != high->next)
    {
        DulNode *p = partition(low, high);
        quickSort(low, p->prior); // Before pivot
        quickSort(p->next, high); // After pivot
    }
}

DulNode *getTail(DulNode *list)
{
    while (list != nullptr && list->next != nullptr)
    {
        list = list->next;
    }
    return list;
}

void sortList(DulLinkList &list)
{
    DulNode *tail = getTail(list->next);
    quickSort(list->next, tail); // Skip the head
}

int main()
{
    DulLinkList list = createList();

    // Sample data
    STUDENT s1 = {"001", "Alice", 85, 1};
    STUDENT s2 = {"002", "Bob", 92, 2};
    STUDENT s3 = {"003", "Charlie", 78, 3};
    STUDENT s4 = {"004", "David", 90, 4};

    insertNode(list, s1);
    insertNode(list, s2);
    insertNode(list, s3);
    insertNode(list, s4);

    cout << "Before sorting:" << endl;
    printList(list);

    sortList(list);

    cout << "After sorting by score:" << endl;
    printList(list);

    return 0;
}