#include <bits/stdc++.h>
using namespace std;

// Optimal Solution using Backtracking
class Solution
{
private:
    // Helper function to find subsets of size 'k' that sum to 'n'
    void findSubset(int start, int k, int n, vector<vector<int>> &res, vector<int> &ds)
    {
        // Base case: if we have exactly k elements and their sum is n, store the subset
        if (k == 0 && n == 0)
        {
            res.push_back(ds);
            return;
        }

        // If k elements are already chosen OR sum becomes invalid (negative), stop recursion
        if (k == 0 || n <= 0)
            return;

        // Try picking numbers from 'start' to 9 (since only digits 1-9 are allowed)
        for (int i = start; i < 10; ++i)
        {
            // Include current number i
            ds.push_back(i);

            // Recurse with reduced k and n, next start = i+1 (since each number can be used once)
            findSubset(i + 1, k - 1, n - i, res, ds);

            // Backtrack: remove last element before exploring next option
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res; // Stores all valid subsets
        vector<int> ds;          // Temporary subset (decision stack)

        // Start from number 1
        findSubset(1, k, n, res, ds);

        return res;
    }
};

// Brute Force Solution (Generate all subsets using Power Set)
/*
class Solution {
private:
    // Generate all possible subsets of nums[]
    void generateSubsets(int ind, vector<int> &nums, int k, int n, vector<int> &ds, vector<vector<int>> &res) {
        // If we have considered all elements
        if (ind == nums.size()) {
            // Check if subset has exactly k elements and sums to n
            if (ds.size() == k && accumulate(ds.begin(), ds.end(), 0) == n) {
                res.push_back(ds);
            }
            return;
        }

        // Include nums[ind] in current subset
        ds.push_back(nums[ind]);
        generateSubsets(ind + 1, nums, k, n, ds, res);

        // Exclude nums[ind] (backtrack step)
        ds.pop_back();
        generateSubsets(ind + 1, nums, k, n, ds, res);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;           // Stores all valid subsets
        vector<int> ds;                    // Temporary subset
        vector<int> nums = {1,2,3,4,5,6,7,8,9}; // Only numbers 1-9 are allowed

        // Start generating subsets from index 0
        generateSubsets(0, nums, k, n, ds, res);

        return res;
    }
};
*/
