#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int ZeroIndex = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                ZeroIndex = i;
                break;
            }
        }

        if (ZeroIndex == -1)
            return;

        for (int i = ZeroIndex + 1; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[ZeroIndex], nums[i]);
                ZeroIndex++;
            }
        }
    }
};
