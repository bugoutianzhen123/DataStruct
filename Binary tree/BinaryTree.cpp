#include "BinaryTree.h"

void Test()
{
    BinaryTree tree;
    if (tree.EmptyTree())
    {
        cout << "it's empty" << endl;
    }
    else
    {
        cout << "it isn't empty" << endl;
    }
    tree.Insert(10).Insert(5).Insert(12).Insert(7).Insert(1).Insert(2).Insert(20).Insert(15);
    if (tree.EmptyTree())
    {
        cout << "it's empty" << endl;
    }
    else
    {
        cout << "it isn't empty" << endl;
    }
    tree.Traverse();
    cout << "it's depth is" << tree.GetTreeDepth() << endl;
    tree.GetLeftChild(2);
    tree.GetRightChild(2);
    tree.GetParent(2);

    
}