#include "stack.cpp"

int main()
{
    // 判断是否是有效的出入栈
    // isValid();

    // 开闭括号是否匹配
    // JugedBracket();

    // 判断是否回文
    // DetermineTheNumberOfPalindromes();
    // 找最值
    LinearList();

    return 0;
}

void isValid()
{
    StackLink<int> a;
    a.Push(1);
    a.Push(2);
    printf("%d\n", a.Top());
    a.IsEmpty();
    a.GetSize();
    a.IsEmpty();

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
}