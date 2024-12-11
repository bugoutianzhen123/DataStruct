#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *GetCircle(Node *node)
{
    Node *p1 = node, *p2 = node;
    while (p1 && p2->next)
    {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2)
        {
            p1 = node;
            while (p1 != p2)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
            return p1;
        }
    }
    return nullptr;
}

void First()
{
    Node n9{9, nullptr}, n8{8, &n9}, n7{7, &n8}, n6{6, &n7}, n5{5, &n6}, n4{4, &n5}, n3{3, &n4}, n2{2, &n3}, n1{1, &n2};
    n9.next = &n6;
    Node *result = GetCircle(&n1);
    if (result)
    {
        cout << "the node is " << result->data << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}

int GetNumber(vector<int> num)
{
    int n = num.size();
    for (int i = 0; i < n; i++)
    {
        if (num[i] > 0 && num[i] <= n && num[i] != i + 1) 
        {
        }
        int t;
        t = num[num[i] - 1];
        num[num[i] - 1] = num[i];
        num[i] = t;
    }

    for (int i = 0; i < n; i++)
    {
        if (i + 1 != num[i])
        {
            return i + 1;
        }
    }
    return n + 1;
}

void Second()
{
    vector<int> num = {1, 5, 3, 7, -6, 2};
    cout << "the min is " << GetNumber(num) << endl;
}

int main()
{
    // First();
    Second();
}