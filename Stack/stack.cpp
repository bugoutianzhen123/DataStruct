#include "stack.h"
#include <stdexcept>
#include <vector>

using namespace std;

// 判断给定的入栈序列和出栈序列是否匹配
bool isValidSequence(vector<int> &pushSeq, vector<int> &outSeq)
{
    StackLink<int> s;
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

// 判断给定的字符串中的开闭括号是否成对出现
void JugedBracket()
{
    char ch;
    StackLink<int> s;
    while (scanf("%c", &ch) && ch != '\n')
    {
        switch (ch)
        {
        case '(':
            s.Push(1);
            break;
        case ')':
            if (s.IsEmpty())
            {
                cout << "no" << endl;
                return;
            }
            if (s.Top() == 1)
                s.Out();
            break;
        case '[':
            s.Push(2);
            break;
        case ']':
            if (s.IsEmpty())
            {
                cout << "no" << endl;
                return;
            }
            if (s.Top() == 2)
                s.Out();
            break;

        default:
            break;
        }
    }

    if (s.IsEmpty())
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}

// 判断回文数
void DetermineTheNumberOfPalindromes()
{
    StackLink<char> sch;
    string str;
    int i = 0;
    cin >> str;
    while (str[i])
    {
        sch.Push(str[i++]);
    }

    i = 0;
    while (str[i])
    {
        if (sch.Top() == str[i++])
        {
            sch.Out();
        }
        else
        {
            cout << "no" << endl;
            return;
        }
    }

    if (sch.IsEmpty())
        cout << "yes" << endl;
}

int GetMax(vector<int> &num, int Index, int n)
{
    if (Index == n - 1)
        return num[Index];
    int max = GetMax(num, Index + 1, n);
    return max > num[Index] ? max : num[Index];
}

int GetMin(vector<int> &num, int Index, int n)
{
    if (Index == n - 1)
        return num[Index];
    int min = GetMax(num, Index + 1, n);
    return min < num[Index] ? min : num[Index];
}

void LinearList()
{
    vector<int> num = {1, 5, 6, 12, 3, 1, 4, 7, 8, 3, 0};
    int max, min;

    max = GetMax(num, 0, num.size());
    min = GetMin(num, 0, num.size());

    cout << "Max value: " << max << endl;
    cout << "Min value: " << min << endl;
}
