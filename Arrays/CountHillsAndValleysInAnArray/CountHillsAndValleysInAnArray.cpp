#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countHillValley(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> unique;

        // Step 1: Remove consecutive duplicate elements
        unique.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
                unique.push_back(nums[i]);
        }

        int res = 0;

        // Step 2: Count hills and valleys in the filtered list
        for (int i = 1; i < unique.size() - 1; ++i)
        {
            // Hill: Current is greater than both neighbors
            if (unique[i] > unique[i - 1] && unique[i] > unique[i + 1])
                res++;
            // Valley: Current is smaller than both neighbors
            else if (unique[i] < unique[i - 1] && unique[i] < unique[i + 1])
                res++;
        }

        return res;
    }
};
