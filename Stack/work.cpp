#include "stack.cpp"

int main()
{
    vector<int> pushSeq = {1, 2, 3}; // 入栈序列
    vector<int> outSeq1 = {2, 1, 3}; // 有效
    vector<int> outSeq2 = {3, 1, 2}; // 无效

    if (isValidSequence(pushSeq, outSeq1))
    {
        cout << "是有效的出栈序列" << endl;
    }
    else
    {
        cout << "不是有效的出栈序列" << endl;
    }

    if (isValidSequence(pushSeq, outSeq2))
    {
        cout << "是有效的出栈序列" << endl;
    }
    else
    {
        cout << "不是有效的出栈序列" << endl;
    }

    return 0;
}
