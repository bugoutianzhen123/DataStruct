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
    Node *FindChildNode(Node *node, int data, Node *target)
    {
        if (node == nullptr)
            return nullptr;
        if (data < node->Data)
            return FindChildNode(node->Left, data, node);
        if (data > node->Data)
            return FindChildNode(node->Right, data, node);
        return target;
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

    // 广度优先
    void LevelOrder()
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

public:
    Node *Root;
    BinaryTree() : Root(nullptr) {}

    ~BinaryTree()
    {
        DestroyTree(Root);
    }

    // 判断是否为空
    bool EmptyTree()
    {
        return Root == nullptr;
    }

    // 插入数据
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
            printf("no left child");
        }
        else
        {
            printf("the left child is %d", node->Data);
        }
        return node;
    }

    // 获取右孩子
    Node *GetRightChild(int e)
    {
        Node *node = FindNode(Root, e)->Right;
        if (node == nullptr)
        {
            printf("no right child");
        }
        else
        {
            printf("the right child is %d", node->Data);
        }
        return node;
    }

    // 获取双亲
    Node *GetParent(int e)
    {
        Node *node = FindChildNode(Root, e, nullptr);
        if (node == nullptr)
        {
            printf("no parent");
        }
        else
        {
            printf("the parent is %d", node->Data);
        }
        return node;
    }

    // 获取左兄弟
    Node *GetLeftBrother(int e)
    {
        Node *node;
        node = FindChildNode(Root, e, nullptr);
        return node->Left;
    }

    // 获取右兄弟
    Node *GetRightBrother(int e)
    {
        Node *node;
        node = FindChildNode(Root, e, nullptr);
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
            return *this;
        }
        else if (LR == 1)
        {
            DestroyTree(node->Right);
            return *this;
        }
        return *this;
    }

    // 遍历
    BinaryTree &Traverse()
    {
        PreTraverse(Root);
        return *this;
    }
};