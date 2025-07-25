#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        // Find the maximum value in the array
        int maxi = *max_element(nums.begin(), nums.end());

        // If all elements are non-positive, return the maximum (could be 0 or negative)
        if (maxi <= 0)
            return maxi;

        unordered_set<int> seen; // To track unique positive elements
        int ans = 0;

        for (int x : nums)
        {
            // Add only unique positive values
            if (x > 0 && !seen.count(x))
            {
                ans += x;
                seen.insert(x);
            }
        }

        return ans;
    }
};
