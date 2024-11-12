#include "kmp.cpp"

int main()
{
    string text = "jldaljdajwlddjaskljadsl";
    string target = "jasklj";

    int result = Kmp(text, target);

    if (result == -1)
    {
        cout << "can't find" << endl;
    }
    else
    {
        cout << "target found in " << result << endl;
    }
    cout << "test" << endl;
    return 0;
}