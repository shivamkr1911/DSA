#include <bits/stdc++.h>
using namespace std;

class Solution
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
