#include <bits/stdc++.h>

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
    // 二分插入
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
    // 广度优先遍历
    void LevelOrderTraverse(Node *root)
    {
        if (root == nullptr)
        {
            cout << "this tree is null" << endl;
            return;
        }
        int depth = 0;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int LevelNumber = q.size(); // 当层节点数

            for (int i = 0; i < LevelNumber; i++)
            {
                Node *node = q.front();
                q.pop();
                cout << node->Data << " ";
                if (node->Left != nullptr)
                {
                    q.push(node->Left);
                }
                if (node->Right != nullptr)
                {
                    q.push(node->Right);
                }
            }
            depth++;
        }
        cout << "共有" << depth << "层" << endl;
        return;
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
    // 打印树
    void PrintTree(Node *root, int space = 0, int level_gap = 4)
    {
        if (root == nullptr)
            return;

        // 增加间距
        space += level_gap;

        // 先打印右子树
        PrintTree(root->Right, space);

        // 打印当前节点
        cout << endl;
        for (int i = level_gap; i < space; i++)
            cout << " ";
        cout << root->Data << endl;

        // 打印左子树
        PrintTree(root->Left, space);
    }

    void writeArray(Node *currNode, int rowIndex, int columnIndex, vector<vector<string>> &res, int treeDepth)
    {
        // 保证输入的树不为空
        if (currNode == nullptr)
            return;

        // 先将当前节点保存到二维数组中
        res[rowIndex][columnIndex] = to_string(currNode->Data);

        // 计算当前位于树的第几层
        int currLevel = (rowIndex + 1) / 2;

        // 若到了最后一层，则返回
        if (currLevel == treeDepth)
            return;

        // 计算当前行到下一行，每个元素之间的间隔（下一行的列索引与当前元素的列索引之间的间隔）
        int gap = treeDepth - currLevel - 1;

        // 对左儿子进行判断，若有左儿子，则记录相应的"/"与左儿子的值
        if (currNode->Left != nullptr)
        {
            res[rowIndex + 1][columnIndex - gap] = "/";
            writeArray(currNode->Left, rowIndex + 2, columnIndex - gap * 2, res, treeDepth);
        }

        // 对右儿子进行判断，若有右儿子，则记录相应的"\"与右儿子的值
        if (currNode->Right != nullptr)
        {
            res[rowIndex + 1][columnIndex + gap] = "\\";
            writeArray(currNode->Right, rowIndex + 2, columnIndex + gap * 2, res, treeDepth);
        }
    }

    void show(Node *root)
    {
        if (root == nullptr)
        {
            cout << "EMPTY!" << endl;
            return;
        }

        // 得到树的深度
        int treeDepth = Height(root);

        // 最后一行的宽度为2的（n - 1）次方乘3，再加1
        // 作为整个二维数组的宽度
        int arrayHeight = treeDepth * 2 - 1;
        int arrayWidth = (2 << (treeDepth - 2)) * 3 + 1;

        // 用一个字符串数组来存储每个位置应显示的元素
        vector<vector<string>> res(arrayHeight, vector<string>(arrayWidth, " "));

        // 从根节点开始，递归处理整个树
        writeArray(root, 0, arrayWidth / 2, res, treeDepth);

        // 此时，已经将所有需要显示的元素储存到了二维数组中，将其拼接并打印即可
        for (const auto &line : res)
        {
            string lineString;
            for (int i = 0; i < line.size(); ++i)
            {
                lineString += line[i];
                if (line[i].length() > 1 && i <= line.size() - 1)
                {
                    i += line[i].length() > 4 ? 2 : line[i].length() - 1;
                }
            }
            cout << lineString << endl;
        }
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
            LevelOrderTraverse(Root);
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
    // 打印树
    BinaryTree &Print(int space = 0, int level_gap = 4)
    {
        // PrintTree(Root);
        show(Root);
        return *this;
    }
};