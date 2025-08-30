#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // Optimal Solution - Kadane's Algorithm
        // Idea: Keep running sum, reset if sum < 0, track maximum sum
        int n = nums.size();
        int sum = 0;        // current subarray sum
        int maxi = INT_MIN; // maximum sum so far

        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];        // include current element
            maxi = max(maxi, sum); // update maximum sum
            if (sum < 0)
                sum = 0; // reset if sum negative
        }
        return maxi; // return maximum subarray sum

        // Better Solution - Prefix Sum Approach
        /*
        // Check sum of all subarrays starting from each index
        int maxi = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];       // sum from i to j
                maxi = max(maxi, sum); // update maximum
            }
        }
        return maxi;
        */

        // Brute Force Solution - Triple Nested Loops
        /*
        // Compute sum for all possible subarrays
        int maxi = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int sum = 0;
                for (int k = i; k <= j; ++k) {
                    sum += nums[k];       // sum of subarray nums[i..j]
                }
                maxi = max(maxi, sum);   // update maximum sum
            }
        }
        return maxi;
        */
    }
};
