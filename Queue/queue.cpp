#include "head.h"

void Circular()
{
    CircularQueue circularQueue;
    if (circularQueue.JudgeIfEmpty())
        cout << "this is empty" << endl;

    circularQueue.InQueue(1).InQueue(2).InQueue(3);
    circularQueue.Print();
    cout << "it\'s lengt is" << circularQueue.Length() << endl;
    circularQueue.OutQueue();
    cout << "it\'s lengt is" << circularQueue.Length() << endl;
}

void Double()
{
    DoubleQueue dou;
    if (dou.JudgeEmpty())
    {
        cout << "this is empty" << endl;
    }

    dou.InFront(1).InFront(2).InFront(3).InRear(4).InRear(5).Print();
    cout << "it\'s lengt is" << dou.Length() << endl;
    dou.OutFront().OutRear().Print();
    cout << "it\'s lengt is" << dou.Length() << endl;
}

int maxDifference(vector<int> &nums)
{
    int maxDiff = -1;
    int n = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < n; i++)
    {
        CircularQueue queue(n);

        for (int j = i; j < n; j++)
        {
            if (nums[i] == nums[j])
            {
                queue.InQueue(j);
                bool valid = true;
                for (int k = i + 1; k < j; k++)
                {
                    if (nums[k] < nums[i])
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    maxDiff = max(maxDiff, j - i);
                }
                while (!queue.JudgeIfEmpty())
                {
                    queue.OutQueue();
                }
            }
        }
    }

    return maxDiff;
}

int work()
{
    vector<int> nums = {5, 3, 4, 5, 3, 2, 5};
    int result = maxDifference(nums);
    cout << "The maximum difference of indices is: " << result << endl;
    return 0;
}