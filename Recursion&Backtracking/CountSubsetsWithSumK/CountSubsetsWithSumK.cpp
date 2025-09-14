// Recursive solution for subset sum count.
// Time: O(2^n) → works only for small n, used for understanding recursion.
// For large constraints, must be optimized using DP (O(n * k)).

#include <bits/stdc++.h>
using namespace std;

// Recursive function to count subsets with sum = k
int func(int ind, int sum, vector<int> &arr, int k, int n)
{
    if (sum > k)
        return 0; // pruning: if sum exceeds k, no valid subset

    // base case: reached end of array
    if (ind == n)
    {
        if (sum == k)
            return 1; // valid subset found
        else
            return 0; // not valid
    }

    // include current element
    sum += arr[ind];
    int l = func(ind + 1, sum, arr, k, n);

    // exclude current element (backtrack sum)
    sum -= arr[ind];
    int r = func(ind + 1, sum, arr, k, n);

    return l + r; // total ways = include + exclude
}

// Wrapper function
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    return func(0, 0, arr, k, n); // start recursion from index 0 with sum = 0
}
