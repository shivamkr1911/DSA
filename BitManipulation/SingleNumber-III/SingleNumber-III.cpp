#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution (XOR & Bitmasking) ===============
class Solution1
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        long xorr = 0;

        // XOR all numbers; result is XOR of the two unique numbers
        for (int i = 0; i < n; ++i)
        {
            xorr ^= nums[i];
        }

        // Find rightmost set bit (differentiates the two unique numbers)
        int rightMost = (xorr & (xorr - 1)) ^ xorr;

        int b1 = 0, b2 = 0;

        // Divide numbers into two groups based on rightMost bit and XOR separately
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] & rightMost)
                b1 ^= nums[i]; // Group with the bit set
            else
                b2 ^= nums[i]; // Group with the bit not set
        }

        return {b1, b2}; // Two unique numbers
    }
};

// =============== Brute Force Solution (Using Hash Map) ===============
class Solution2
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mpp;

        // Count frequency of each number
        for (int i = 0; i < n; ++i)
        {
            mpp[nums[i]]++;
        }

        vector<int> ans;

        // Collect numbers with frequency 1
        for (auto it : mpp)
        {
            if (it.second == 1)
                ans.push_back(it.first);
        }

        return ans;
    }
};
