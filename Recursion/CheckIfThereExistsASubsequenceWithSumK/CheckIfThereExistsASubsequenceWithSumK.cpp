// Time Complexity: O(2^n), Space Complexity: O(n) (recursion stack)
// Note: This is for understanding recursion.
// For large inputs, use DP (O(n * k)) to avoid TLE.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Recursive helper to check if any subsequence sums to k
    bool func(int ind, int sum, int n, vector<int> &arr, int k)
    {
        // base case: reached end of array
        if (ind == n)
        {
            if (sum == k)
                return true; // found valid subsequence
            else
                return false; // not valid
        }

        // include current element
        sum += arr[ind];
        if (func(ind + 1, sum, n, arr, k) == true)
            return true;

        // exclude current element (backtrack sum)
        sum -= arr[ind];
        if (func(ind + 1, sum, n, arr, k) == true)
            return true;

        return false; // no valid subsequence found
    }

public:
    // Main function to check if subsequence with sum = k exists
    bool checkSubsequenceSum(int n, vector<int> &arr, int k)
    {
        return func(0, 0, n, arr, k); // start recursion from index 0, sum = 0
    }
};
