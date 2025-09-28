#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sort the sides in non-decreasing order

        // Traverse from the largest possible triplet
        for (int i = n - 3; i >= 0; i--)
        {
            // Check triangle inequality condition
            if (nums[i] + nums[i + 1] > nums[i + 2])
                return nums[i] + nums[i + 1] + nums[i + 2]; // Return perimeter
        }
        return 0; // No valid triangle found
    }
};
