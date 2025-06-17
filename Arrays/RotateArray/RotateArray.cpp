#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> temp(k);
        for (int i = 0; i < k; i++)
        {
            temp[i] = nums[n - k + i];
        }

        for (int i = n - k - 1; i >= 0; i--)
        {
            nums[i + k] = nums[i];
        }

        for (int i = 0; i < k; i++)
        {
            nums[i] = temp[i];
        }

        return;

        // Or - Space Complexity O(1)

        // reverse(nums.begin(), nums.begin() + (n - k));
        // reverse(nums.begin() + n - k, nums.end());
        // reverse(nums.begin(), nums.end());
        // return;
    }
};
