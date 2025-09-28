#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        // Optimal Solution - Single pass
        int n = nums.size();
        int mini = nums[0]; // Track minimum value seen so far
        int res = INT_MIN;  // Store maximum difference

        for (int i = 1; i < n; ++i)
        {
            int diff = nums[i] - mini; // Difference with current minimum
            res = max(res, diff);      // Update maximum difference
            mini = min(mini, nums[i]); // Update minimum
        }
        return (res > 0 ? res : -1); // Return -1 if no positive difference exists

        // Brute Force Solution - O(n^2)
        /*
        int n = nums.size();
        int res = INT_MIN;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int diff = nums[j] - nums[i];
                res = max(res, diff);   // Update maximum difference
            }
        }
        return (res > 0 ? res : -1);
        */
    }
};
