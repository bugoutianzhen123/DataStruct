#include "BinaryTree.h"

void Tree()
{
    BinaryTree tree;
    tree.Insert(5, 5).Insert(2, 2).Insert(7, 7).Insert(1, 1).Insert(4, 4);
    //        5
    //       / \
    //      2   7
    //     / \   
    //    1   4
    cout << "it's wpl is" << tree.WPL() << endl;

    tree.Insert(8, 8);
    //        5
    //       / \
    //      2   7
    //     / \   \
    //    1   4   8
    cout << "it's wpl is" << tree.WPL() << endl;
}

void Graph()
{
}
