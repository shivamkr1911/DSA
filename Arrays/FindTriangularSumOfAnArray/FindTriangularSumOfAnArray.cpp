#include <bits/stdc++.h>
using namespace std;

// Optimal Solution
class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        int n = nums.size();
        // Reduce the array size step by step
        for (int len = n; len > 1; --len)
        {
            // Update each element as sum of current and next modulo 10
            for (int i = 0; i < len - 1; ++i)
            {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums[0]; // Final single element is the triangular sum
    }
};

// Better Solution
/*
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n); // Temporary array to store new sums
        while (n > 1) {
            for (int i = 0; i < n - 1; i++) {
                next[i] = (nums[i] + nums[i + 1]) % 10; // Calculate new values
            }
            n--;              // Reduce effective array size
            nums.swap(next);  // Efficiently update nums to hold the newly calculated values
        }
        return nums[0];      // Return final element
    }
};
*/

// Brute Force
/*
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while (nums.size() > 1) {
            vector<int> newNums;
            int n = nums.size();
            // Compute sum of adjacent elements modulo 10
            for (int i = 0; i < n - 1; ++i) {
                int sum = (nums[i] + nums[i + 1]) % 10;
                newNums.push_back(sum);
            }
            nums = newNums; // Replace old array with new sums
        }
        return nums[0]; // Final element is the triangular sum
    }
};
*/
