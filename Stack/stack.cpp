#include "stack.h"

// 判断给定的入栈序列和出栈序列是否匹配 //采用动态数组
bool isValidSequence(vector<int> &pushSeq, vector<int> &outSeq)
{
    Stack s;
    int j = 0;

    for (int i = 0; i < pushSeq.size(); ++i)
    {
        s.Push(pushSeq[i]);

        // 尝试根据出栈序列进行匹配
        while (!s.IsEmpty() && s.Top() == outSeq[j])
        {
            s.Out();
            j++;
        }
    }

    return s.IsEmpty();
}

