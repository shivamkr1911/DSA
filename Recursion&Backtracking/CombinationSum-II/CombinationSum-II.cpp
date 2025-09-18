#include <bits/stdc++.h>
using namespace std;

// Optimal Solution
class Solution
{
private:
    // Helper function to find unique combinations
    void findCombination(int ind, vector<int> &arr, int target, vector<vector<int>> &res, vector<int> &ds)
    {
        // Base case: if target becomes 0, add current combination
        if (target == 0)
        {
            res.push_back(ds);
            return;
        }
        // Loop through candidates starting from 'ind'
        for (int i = ind; i < arr.size(); ++i)
        {
            // Skip duplicates (only take first occurrence at each recursion level)
            if (i > ind && arr[i] == arr[i - 1])
                continue;

            // If current number is greater than remaining target, no need to continue
            if (arr[i] > target)
                break;

            // Pick current number
            ds.push_back(arr[i]);
            // Recurse with next index (i+1) since each element can be used once
            findCombination(i + 1, arr, target - arr[i], res, ds);
            // Backtrack (remove last element)
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        // Sort to handle duplicates and enable early stopping
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res; // stores final result
        vector<int> ds;          // temporary combination
        findCombination(0, candidates, target, res, ds);
        return res;
    }
};

// Brute Force
/*
class Solution {
private:
    // Recursive helper (stores combinations in a set to remove duplicates)
    void findCombination(int ind, set<vector<int>> &hashSet, vector<int> &arr, int target, vector<int> &ds) {
        // Base case: reached end of array
        if (ind == arr.size()) {
            if (target == 0) {
                vector<int> tmp = ds;
                sort(tmp.begin(), tmp.end()); // sort to avoid different order duplicates
                hashSet.insert(tmp);          // insert into set for uniqueness
            }
            return;
        }

        // Pick current element if it does not exceed target
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);
            findCombination(ind + 1, hashSet, arr, target - arr[ind], ds);
            ds.pop_back(); // backtrack
        }

        // Skip current element
        findCombination(ind + 1, hashSet, arr, target, ds);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> hashSet;  // ensures unique combinations
        vector<int> ds;            // temporary combination
        findCombination(0, hashSet, candidates, target, ds);
        // Convert set back to vector for output
        return vector<vector<int>>(hashSet.begin(), hashSet.end());
    }
};
*/
