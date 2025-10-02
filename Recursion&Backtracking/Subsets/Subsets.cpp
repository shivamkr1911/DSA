#include <bits/stdc++.h>
using namespace std;

// =============== Recursive and Backtracking Solution ===============

class Solution1
{
private:
    // Backtracking function to generate subsets
    void backtrack(int idx, vector<int> &ds, vector<int> &nums, vector<vector<int>> &res)
    {
        // If all elements are considered, add current subset to result
        if (idx == nums.size())
        {
            res.push_back(ds);
            return;
        }

        // Exclude current element
        backtrack(idx + 1, ds, nums, res);

        // Include current element
        ds.push_back(nums[idx]);
        backtrack(idx + 1, ds, nums, res);

        // Backtrack: remove last element before returning
        ds.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> ds;              // Temporary list to hold current subset
        backtrack(0, ds, nums, res); // Start recursion from index 0
        return res;
    }
};

// =============== Bit Manipulation Solution ===============

class Solution2
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();         // Number of elements in nums
        int totalSubsets = (1 << n); // Total subsets = 2^n (each element can either be present or absent)
        vector<vector<int>> ans;     // To store all subsets

        // Iterate through all numbers from 0 to 2^n - 1
        // Each number represents a subset in binary form
        for (int num = 0; num < totalSubsets; num++)
        {
            vector<int> subset; // Current subset

            // Check each bit of num
            for (int i = 0; i < n; ++i)
            {
                // If the i-th bit is set in num, include nums[i] in the subset
                if (num & (1 << i))
                {
                    subset.push_back(nums[i]);
                }
            }

            // Add the constructed subset to the result
            ans.push_back(subset);
        }

        return ans; // Return all subsets
    }
};
