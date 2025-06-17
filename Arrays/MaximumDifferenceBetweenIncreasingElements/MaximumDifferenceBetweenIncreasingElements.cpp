#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int mini = nums[0];
        int res = -1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == mini)
                continue;
            int diff = nums[i] - mini;
            res = max(res, diff);
            if (mini > nums[i])
                mini = nums[i];
        }
        return res;
    }
};