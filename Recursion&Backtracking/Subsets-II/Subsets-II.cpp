#include <bits/stdc++.h>
using namespace std;

// Optimal Solution
class Solution
{
private:
    // Recursive function to generate all unique subsets
    void findSubset(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &res)
    {
        // Store the current subset
        res.push_back(ds);

        // Loop through remaining elements
        for (int i = ind; i < nums.size(); ++i)
        {
            // Skip duplicates at the same recursive level
            if (i > ind && nums[i] == nums[i - 1])
                continue;

            // Include nums[i] in the current subset
            ds.push_back(nums[i]);

            // Recurse for next elements
            findSubset(i + 1, nums, ds, res);

            // Backtrack: remove last added element
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> res;        // stores all unique subsets
        vector<int> ds;                 // stores current subset
        sort(nums.begin(), nums.end()); // sort to handle duplicates
        findSubset(0, nums, ds, res);
        return res;
    }
};

// Brute Force - Power Set
/*
class Solution {
private:
    // Recursive function to generate all subsets
    void findSubset(int ind, vector<int> &nums, vector<int> &ds, set<vector<int>> &res) {
        // Base case: if all elements considered, insert into set
        if (ind == nums.size()) {
            res.insert(ds); // set automatically handles duplicates
            return;
        }

        // Include current element
        ds.push_back(nums[ind]);
        findSubset(ind + 1, nums, ds, res);

        // Exclude current element (backtrack)
        ds.pop_back();
        findSubset(ind + 1, nums, ds, res);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort to keep subsets ordered
        set<vector<int>> res;           // set avoids duplicate subsets
        vector<int> ds;                 // stores current subset
        findSubset(0, nums, ds, res);

        // Convert set into vector for final output
        return vector<vector<int>>(res.begin(), res.end());
    }
};
*/
