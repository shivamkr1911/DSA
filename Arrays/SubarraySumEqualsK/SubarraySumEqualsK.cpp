#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mpp;
        mpp[0] = 1; // Base case: sum 0 occurs once
        int preSum = 0, cnt = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            preSum += nums[i]; // Update prefix sum
            int remove = preSum - k;
            cnt += mpp[remove]; // Count subarrays with sum k
            mpp[preSum]++;      // Store current prefix sum
        }

        return cnt;
    }
};
