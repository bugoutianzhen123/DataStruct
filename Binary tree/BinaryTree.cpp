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
    //        10
    //       /  \
    //      5    12
    //     / \     \
    //    1   7     20
    //     \        /
    //      2       15
    tree.Print();
    // tree.Traverse();
    tree.Traverse(tree.level);

    // if (tree.EmptyTree())
    // {
    //     cout << "it's empty" << endl;
    // }
    // else
    // {
    //     cout << "it isn't empty" << endl;
    // }

    // cout << "preTraverse:";
    // tree.Traverse();
    // tree.Traverse(tree.mid);

    // cout << "it's depth is" << tree.GetTreeDepth() << endl;
    // tree.GetLeftChild(5);
    // tree.GetRightChild(5);
    // tree.GetParent(20);
    // tree.GetLeftBrother(5);
    // tree.GetRightBrother(5);

    // // 插入子树
    // BinaryTree other;
    // other.Insert(40).Insert(30).Insert(35);

    // //     40
    // //    /
    // //   30
    // //    \
    // //     35

    // tree.InsertChild(20, 0, &other);

    // tree.Traverse(tree.pre);
    // //        10
    // //       /  \
    // //      5    12
    // //     / \     \
    // //    1   7     20
    // //     \        /
    // //      2      40
    // //            /  \
    // //           30  15
    // //            \
    // //             35
    // tree.DeleteChild(10, 0);
    // tree.Traverse(tree.pre);
    // //        10
    // //          \
    // //           12
    // //             \
    // //              20
    // //              /
    // //             40
    // //            /  \
    // //           30  15
    // //            \
    // //             35

    // tree.DeleteChild(10, 1);
    // tree.Traverse(tree.pre);
    // //         10
}

void GetTreeFromArray()
{
    vector<int> ar1 = {10, 5, 1, 2, 7, 12, 20, 15};
    vector<int> ar2 = {1, 2, 5, 7, 10, 12, 15, 20};

    BinaryTree tree;
    tree.BuildTreeFromTraverse(ar1, ar2).Traverse();

    // 交换所有子节点
    tree.ExchangeChild().Traverse();
    return;
}

void Blance()
{
    BinaryTree tree1, tree2;
    tree1.Insert(5).Insert(4).Insert(6).IfBlance();
    tree2.Insert(5).Insert(8).Insert(10).Insert(12).Insert(3).Insert(7).IfBlance();
    return;
}

struct TreeNode
{
    string data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(string x) : data(x), left(nullptr), right(nullptr) {}
};

// TreeNode *FindParent(TreeNode *node,string data){
//      if(node == )
// }

TreeNode *buildTree(queue<string> &q, int *i)
{
    if (q.empty())
    {
        return nullptr;
    }

    string val = q.front();
    q.pop();

    if (val == "#")
    {
        return nullptr;
    }

    TreeNode *newNode = new TreeNode(val);

    newNode->left = buildTree(q, i);
    newNode->right = buildTree(q, i);

    (*i)++;
    return newNode;
}

void inorderTraversal(TreeNode *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void the4()
{
    queue<string> q;
    q.push("A");
    q.push("B");
    q.push("D");
    q.push("#");
    q.push("#");
    q.push("E");
    q.push("#");
    q.push("#");
    q.push("C");
    q.push("F");
    q.push("#");
    q.push("#");

    int i = 0;
    TreeNode *root = buildTree(q, &i);

    inorderTraversal(root);
    cout << endl;
    cout << "it have " << i << "nodes " << endl;
}
