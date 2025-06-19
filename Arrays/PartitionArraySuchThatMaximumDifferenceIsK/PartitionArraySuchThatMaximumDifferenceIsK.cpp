#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int partitionArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 1;
        int left = 0;
        for (int right = 0; right < n; right++)
        {
            if (nums[right] - nums[left] > k)
            {
                ans++;
                left = right;
            }
        }
        return ans;
    }
};