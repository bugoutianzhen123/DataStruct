#include <iostream>
#include <stdexcept>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
    int Data;
    Node *Left;
    Node *Right;

    Node(int data) : Data(data), Left(nullptr), Right(nullptr) {}
};

class BinaryTree
{
private:
    enum ChildNode
    {
        Left,
        Right,
    };
    // 销毁一个节点及其所有子节点
    void DestroyTree(Node *node)
    {
        if (node == nullptr)
            return;
        DestroyTree(node->Left);
        DestroyTree(node->Right);
        delete node;
    }

    // 插入
    void InsertOrder(Node *&node, int data)
    {
        if (node == nullptr)
        {
            node = new Node(data); // 创建新节点
        }
        else if (data < node->Data)
        {
            InsertOrder(node->Left, data); // 插入到左子树
        }
        else if (data > node->Data)
        {
            InsertOrder(node->Right, data); // 插入到右子树
        }
        // 如果 data == node->Data, 可以选择不做插入（避免重复值）
    }

    // 查找指定节点
    Node *FindNode(Node *node, int data)
    {
        if (node == nullptr)
            return nullptr;
        if (data < node->Data)
            return FindNode(node->Left, data);
        if (data > node->Data)
            return FindNode(node->Right, data);
        return node;
    }

    // 查找有指定子节点的节点
    Node *FindChildNode(Node *node, int data)
    {
        if (node == nullptr)
            return nullptr;

        if ((node->Left && node->Left->Data == data) || (node->Right && node->Right->Data == data))
            return node;
        Node *left = FindChildNode(node->Left, data);
        if (left != nullptr)
            return left;

        return FindChildNode(node->Right, data);
    }

    // 获取树的深度
    int Height(Node *node)
    {
        if (node == nullptr)
            return 0;
        int leftHeight = Height(node->Left);
        int rightHeight = Height(node->Right);
        return max(leftHeight, rightHeight) + 1;
    }

    // 前序遍历
    void PreTraverse(Node *node)
    {
        if (node == nullptr)
            return;
        cout << node->Data << " ";
        PreTraverse(node->Left);
        PreTraverse(node->Right);
    }
    // 中序遍历
    void MidTraverse(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        MidTraverse(node->Left);
        cout << node->Data << " ";
        MidTraverse(node->Right);
    }

    // 后序遍历
    void PoTraverse(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        PoTraverse(node->Left);
        PoTraverse(node->Right);
        cout << node->Data << " ";
    }

    // 广度优先插入
    void LevelOrderInsert()
    {
        if (Root == nullptr)
            return;      // 如果树为空，直接返回
        queue<Node *> q; // 创建队列
        q.push(Root);    // 根节点入队

        while (!q.empty())
        {
            Node *node = q.front();    // 获取队列头部节点
            q.pop();                   // 移除队列头部节点
            cout << node->Data << " "; // 访问节点

            if (node->Left)
                q.push(node->Left); // 左子节点入队
            if (node->Right)
                q.push(node->Right); // 右子节点入队
        }
    }

    // 根据先序，中序遍历的结果生成树
    Node *BuildTreeFromArray(queue<int> *pre, vector<int> mid, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }
        int data = pre->front();
        pre->pop();

        Node *node = new Node(data);
        int RootIndex;
        for (int i = start; i <= end; i++)
        {
            if (mid[i] == data)
            {
                RootIndex = i;
                break;
            }
            RootIndex = -1;
        }

        node->Left = BuildTreeFromArray(pre, mid, start, RootIndex - 1);
        node->Right = BuildTreeFromArray(pre, mid, RootIndex + 1, end);
        return node;
    }

    //    Node *BuildTreeFromPre(queue<string> str){
    //        if(str.empty()){
    //            return nullptr;
    //        }
    //        string data = str.front();
    //        str.pop();
    //        if(data == "#"){
    //            return nullptr;
    //        }
    //        Node *newNode = new Node()
    //    }

    // 交换所有子节点
    void ExchangeChild(Node *node)
    {
        if (node == nullptr || (node->Left == nullptr && node->Right == nullptr))
            return;
        ExchangeChild(node->Left);
        ExchangeChild(node->Right);
        Node *temp;
        temp = node->Left;
        node->Left = node->Right;
        node->Right = temp;
    }

    // 判断子树是否平衡，若不平衡则返回 -1，若平衡则返回树的高度
    int CheckBalance(Node *root)
    {
        if (root == nullptr)
            return 0;

        int leftHeight = CheckBalance(root->Left);
        if (leftHeight == -1)
            return -1;

        int rightHeight = CheckBalance(root->Right);
        if (rightHeight == -1)
            return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        // 返回当前节点的高度
        return max(leftHeight, rightHeight) + 1;
    }

public:
    Node *Root;
    BinaryTree() : Root(nullptr) {}

    ~BinaryTree()
    {
        DestroyTree(Root);
        cout << "the tree was deleted" << endl;
    }

    // 判断是否为空
    bool EmptyTree()
    {
        return Root == nullptr;
    }

    // 二分插入数据
    BinaryTree &Insert(int data)
    {
        InsertOrder(Root, data);
        return *this;
    }

    // 获取深度
    int GetTreeDepth()
    {
        int h = Height(Root);
        printf("it's depth is %d", h);
        return h;
    }

    // 获取左孩子
    Node *GetLeftChild(int e)
    {
        Node *node = FindNode(Root, e)->Left;
        if (node == nullptr)
        {
            printf("no left child\n");
        }
        else
        {
            printf("the %d's left child is %d\n", e, node->Data);
        }
        return node;
    }

    // 获取右孩子
    Node *GetRightChild(int e)
    {
        Node *node = FindNode(Root, e)->Right;
        if (node == nullptr)
        {
            printf("no right child\n");
        }
        else
        {
            printf("the %d's right child is %d\n", e, node->Data);
        }
        return node;
    }

    // 获取双亲
    Node *GetParent(int e)
    {
        Node *node = FindChildNode(Root, e);
        if (node == nullptr)
        {
            printf("no parent\n");
        }
        else
        {
            printf("the %d's parent is %d\n", e, node->Data);
        }
        return node;
    }

    // 获取左兄弟
    Node *GetLeftBrother(int e)
    {
        Node *node;
        node = FindChildNode(Root, e);
        if (node == nullptr)
        {
            printf("no left brother\n");
        }
        else
        {
            printf("the %d's left brother is %d\n", e, node->Left->Data);
        }
        return node->Left;
    }

    // 获取右兄弟
    Node *GetRightBrother(int e)
    {
        Node *node;
        node = FindChildNode(Root, e);
        if (node == nullptr)
        {
            printf("no right brother\n");
        }
        else
        {
            printf("the %d's right brother is %d\n", e, node->Right->Data);
        }
        return node->Right;
    }

    // 插入到指定节点的左或右
    BinaryTree &InsertChild(int p, int LR, BinaryTree *tree)
    {
        Node *node = FindNode(Root, p);
        if (LR == 0)
        {
            Node *temp = node->Left;
            node->Left = tree->Root;
            tree->Root->Right = temp;
            return *this;
        }
        else if (LR == 1)
        {
            Node *temp = node->Right;
            node->Right = tree->Root;
            tree->Root->Right = temp;
            return *this;
        }
        else
        {
            printf("error");
            return *this;
        }
    }

    // 删除指定节点的左子树或右子树
    BinaryTree &DeleteChild(int p, int LR)
    {
        Node *node = FindNode(Root, p);
        if (LR == 0)
        {
            DestroyTree(node->Left);
            node->Left = nullptr;
            return *this;
        }
        else if (LR == 1)
        {
            DestroyTree(node->Right);
            node->Right = nullptr;
            return *this;
        }
        return *this;
    }

    // 遍历
    enum TraverseMeth
    {
        pre,
        mid,
        po,
        level
    };

    // 根据指定方法遍历
    BinaryTree &Traverse(TraverseMeth arg = pre)
    {
        switch (arg)
        {
        case pre:
            PreTraverse(Root);
            cout << endl;
            return *this;
        case mid:
            MidTraverse(Root);
            cout << endl;
            return *this;
        case po:
            PoTraverse(Root);
            cout << endl;
            return *this;

        case level:
            return *this;
        default:
            cout << "this traverse type is wrong" << endl;
            return *this;
        }
    }
    // 根据线序遍历与中序遍历的结果生成树
    BinaryTree &BuildTreeFromTraverse(vector<int> PreArr, vector<int> MidArr)
    {
        queue<int> pre;
        for (int data : PreArr)
        {
            pre.push(data);
        }

        Root = BuildTreeFromArray(&pre, MidArr, 0, MidArr.size() - 1);
        return *this;
    }

    // 交换所有子节点
    BinaryTree &ExchangeChild()
    {
        ExchangeChild(Root);
        return *this;
    }

    // 判断是否平衡
    void IfBlance()
    {
        int i = CheckBalance(Root);
        if (i == -1)
        {
            cout << "this tree  isn't blance" << endl;
            return;
        }
        else
        {
            cout << "this tree  is blance" << endl;
            return;
        }
    }
};