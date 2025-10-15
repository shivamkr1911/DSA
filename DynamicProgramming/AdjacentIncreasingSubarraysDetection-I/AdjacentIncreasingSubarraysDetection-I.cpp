#include <bits/stdc++.h>
using namespace std;

// ================= Optimal Solution =================
class Solution1
{
public:
    bool hasIncreasingSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> incLen(n, 1); // incLen[i] = length of strictly increasing subarray ending at index i

        // Compute length of strictly increasing subarrays ending at each index
        for (int i = 1; i < n; ++i)
        {
            if (nums[i - 1] < nums[i])
                incLen[i] = incLen[i - 1] + 1;
        }

        // Check all possible positions where the first subarray ends
        for (int i = k - 1; i <= n - k - 1; ++i)
        {
            // If first subarray ending at i has length >= k
            // and second subarray ending at i+k has length >= k
            if (incLen[i] >= k && incLen[i + k] >= k)
                return true; // Found two adjacent strictly increasing subarrays of length k
        }
        return false; // No such subarrays exist
    }
};

// ================= Brute Force Solution =================

class Solution2
{
private:
    // Check if subarray starting at 'start' with length k is strictly increasing
    bool isStrictlyInc(vector<int> &nums, int start, int k)
    {
        for (int i = start; i < start + k - 1; ++i)
        {
            if (nums[i] >= nums[i + 1])
                return false; // Found non-increasing pair
        }
        return true; // Subarray is strictly increasing
    }

public:
    bool hasIncreasingSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n < 2 * k)
            return false; // Not enough elements for two adjacent subarrays

        // Check all possible starting positions for the first subarray
        for (int i = 0; i <= n - 2 * k; ++i)
        {
            // First subarray starts at i, second subarray starts immediately after at i+k
            if (isStrictlyInc(nums, i, k) && isStrictlyInc(nums, i + k, k))
                return true; // Found two adjacent strictly increasing subarrays of length k
        }
        return false; // No valid adjacent subarrays found
    }
};
