#include "head.h"

vector<int> GetRre(string &t)
{

    int l = t.length();
    int j = 0;

    vector<int> pre(l, 0);
    for (int i = 1; i < l; i++)
    {
        while (j > 0 && t[i] != t[j])
        {
            j = pre[j - 1];
        }
        if (t[i] == t[j])
        {
            j++;
        }
        pre[i] = j;
    }
    return pre;
}

int Kmp(string &text, string &target)
{
    int m = text.length();
    int n = target.length();

    if (n == 0)
        return 0;

    vector<int> pre = GetRre(target);

    int j = 0;
    for (int i = 0; i < m; i++)
    {
        while (j > 0 && text[i] != target[j])
        {
            j = pre[j - 1];
        }

        if (text[i] == target[j])
            j++;

        if (j == n)
            return i - n + 1;
    }
    return -1;
}
