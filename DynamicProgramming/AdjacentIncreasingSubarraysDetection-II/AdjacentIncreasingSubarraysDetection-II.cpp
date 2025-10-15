#include <bits/stdc++.h>
using namespace std;

// ================= Optimal Solution =================
class Solution1
{
public:
    int maxIncreasingSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> left(n, 1); // left[i] = length of strictly increasing subarray ending at i

        // Fill left array
        for (int i = 1; i < n; ++i)
        {
            if (nums[i - 1] < nums[i])
                left[i] = left[i - 1] + 1;
        }

        vector<int> right(n, 1); // right[i] = length of strictly increasing subarray starting at i

        // Fill right array
        for (int i = n - 2; i >= 0; --i)
        {
            if (nums[i] < nums[i + 1])
                right[i] = right[i + 1] + 1;
        }

        int ans = 0;
        // Check all adjacent subarray pairs and take the max length k
        for (int i = 0; i < n - 1; ++i)
        {
            ans = max(ans, min(left[i], right[i + 1]));
        }

        return ans; // Maximum length k for which two adjacent strictly increasing subarrays exist
    }
};

// ================= Brute Force Solution =================

class Solution2
{
private:
    // Check if subarray starting at 'start' with length 'len' is strictly increasing
    bool isStrictlyInc(vector<int> &nums, int start, int len)
    {
        for (int i = start; i < start + len - 1; ++i)
        {
            if (nums[i] >= nums[i + 1])
                return false;
        }
        return true;
    }

public:
    int maxIncreasingSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int maxK = 0;

        // Check all possible lengths k
        for (int k = 1; k <= n / 2; ++k)
        {
            // Check all starting positions for first subarray
            for (int i = 0; i <= n - 2 * k; ++i)
            {
                // If both subarrays of length k are strictly increasing
                if (isStrictlyInc(nums, i, k) && isStrictlyInc(nums, i + k, k))
                {
                    maxK = k; // Update maximum k
                    break;    // No need to check other positions for this k
                }
            }
        }

        return maxK; // Maximum length k for which adjacent strictly increasing subarrays exist
    }
};
