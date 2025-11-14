#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution ===============
class Solution1
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int zeros = 0;    // count of zeros in the current window
        int maxLen = 0;   // stores the longest valid window
        int l = 0, r = 0; // window pointers

        while (r < n)
        {
            if (nums[r] == 0)
                zeros++; // count zero

            // If zeros exceed k, shrink window from left
            if (zeros > k)
            {
                if (nums[l] == 0)
                    zeros--;
                l++;
            }

            // Valid window with at most k zeros
            if (zeros <= k)
                maxLen = r - l + 1;

            r++;
        }
        return maxLen;
    }
};

// =============== Better Solution ===============
class Solution2
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 0, r = 0;
        int zeros = 0; // track zeros in current window
        int len = 0, maxLen = 0;

        while (r < n)
        {
            if (nums[r] == 0)
                zeros++;

            // shrink window if zeros exceed k
            while (zeros > k && l <= r)
            {
                if (nums[l] == 0)
                    zeros--;
                l++;
            }

            // calculate current valid window size
            len = r - l + 1;
            maxLen = max(maxLen, len);
            r++;
        }
        return maxLen;
    }
};

// =============== Brute Force ===============
class Solution3
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxLen = 0;

        // Try every possible subarray and count zeros
        for (int i = 0; i < n; ++i)
        {
            int zeros = 0;
            for (int j = i; j < n; ++j)
            {
                if (nums[j] == 0)
                    zeros++;

                // stop when zeros exceed k
                if (zeros > k)
                    break;

                // update max length of valid subarray
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};
