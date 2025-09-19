#include <bits/stdc++.h>
using namespace std;

// Optimal Solution
class Solution
{
private:
    // Recursive function to calculate subset sums
    void findSubset(int ind, int sum, vector<int> &arr, vector<int> &res)
    {
        // Base case: if index reaches end, store the current sum
        if (ind == arr.size())
        {
            res.push_back(sum);
            return;
        }

        // Include current element in the sum
        sum += arr[ind];
        findSubset(ind + 1, sum, arr, res);

        // Exclude current element (backtrack)
        sum -= arr[ind];
        findSubset(ind + 1, sum, arr, res);
    }

public:
    vector<int> subsetSums(vector<int> &arr)
    {
        vector<int> res; // stores all subset sums
        findSubset(0, 0, arr, res);
        return res;
    }
};

// Brute Force - Using Power Set
/*
class Solution {
  private:
    // Helper to calculate sum of a subset
    int findSum(vector<int> &ds) {
        int s = 0;
        for (int i = 0; i < ds.size(); ++i)
            s += ds[i];
        return s;
    }

    // Recursive function to generate all subsets
    void findSubset(int ind, vector<int> &arr, vector<int> &res, vector<int> &ds) {
        // Base case: if index reaches end, compute subset sum
        if (ind == arr.size()) {
            int sum = findSum(ds);
            res.push_back(sum);
            return;
        }

        // Pick current element
        ds.push_back(arr[ind]);
        findSubset(ind + 1, arr, res, ds);

        // Do not pick current element (backtrack)
        ds.pop_back();
        findSubset(ind + 1, arr, res, ds);
    }

  public:
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> res; // stores all subset sums
        vector<int> ds;  // stores current subset
        findSubset(0, arr, res, ds);
        return res;
    }
};
*/
