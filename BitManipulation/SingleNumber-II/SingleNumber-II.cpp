#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution 1 (Sorting) ===============
class Solution1
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();

        // Sort the array so that numbers appearing 3 times are grouped together
        sort(nums.begin(), nums.end());

        // Check every 3rd element; the unique number will break the triplet pattern
        for (int i = 1; i < n; i += 3)
        {
            if (nums[i] != nums[i - 1])
            {
                return nums[i - 1]; // Found the unique number
            }
        }

        // If the unique number is the last element
        return nums[n - 1];
    }
};

// =============== Optimal Solution 2 (Bit Manipulation Counters) ===============
class Solution2
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        int ones = 0, twos = 0;

        // Traverse all numbers
        for (int i = 0; i < n; ++i)
        {
            // Update ones and twos to track bits appearing once and twice
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }

        return ones; // 'ones' holds the unique number
    }
};

// =============== Better Solution (Bitwise Counting) ===============
class Solution3
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;

        // Check each bit position
        for (int bitIdx = 0; bitIdx < 32; bitIdx++)
        {
            int cnt = 0;

            // Count number of elements with current bit set
            for (int i = 0; i < n; ++i)
            {
                if (nums[i] & (1 << bitIdx))
                    cnt++;
            }

            // If count modulo 3 is 1, this bit belongs to the unique number
            if (cnt % 3 == 1)
                ans = ans | (1 << bitIdx);
        }

        return ans; // Return the unique number
    }
};

// =============== Brute Force Solution (Using Hash Map) ===============
class Solution4
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mpp;

        // Count frequency of each number
        for (int i = 0; i < n; ++i)
        {
            mpp[nums[i]]++;
        }

        // Find the number that occurs only once
        for (auto it : mpp)
        {
            if (it.second == 1)
                return it.first;
        }

        return -1; // If no unique number found (should not happen as per problem constraints)
    }
};
