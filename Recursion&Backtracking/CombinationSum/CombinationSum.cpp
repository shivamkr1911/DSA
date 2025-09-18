#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Recursive helper function to find all combinations
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &res, vector<int> &ds)
    {
        // Base case: if we have considered all elements
        if (ind == arr.size())
        {
            // If target becomes 0, current subset is a valid combination
            if (target == 0)
                res.push_back(ds);
            return;
        }

        // If current element can be taken (does not exceed target)
        if (arr[ind] <= target)
        {
            ds.push_back(arr[ind]); // include element
            // Stay on same index (since we can reuse same element) and reduce target
            findCombination(ind, target - arr[ind], arr, res, ds);
            ds.pop_back(); // backtrack (remove last element)
        }

        // Move to next element (exclude current one)
        findCombination(ind + 1, target, arr, res, ds);
    }

public:
    // Main function to return all unique combinations summing to target
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;                         // stores all valid combinations
        vector<int> ds;                                  // temporary list for current combination
        findCombination(0, target, candidates, res, ds); // start recursion
        return res;
    }
};
