#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        int n = nums.size();

        // Check local neighbors: repeated element must appear close by
        for (int i = 0; i < n - 2; ++i)
        {
            if (nums[i] == nums[i + 1] || nums[i] == nums[i + 2])
                return nums[i];
        }

        // If not found earlier, the repeated element is the last one
        return nums[n - 1];
    }
};
