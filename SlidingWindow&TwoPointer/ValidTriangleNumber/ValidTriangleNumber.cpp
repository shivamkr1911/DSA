#include <bits/stdc++.h>
using namespace std;

// Optimal Solution
class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0; // Less than 3 sides cannot form a triangle

        int cnt = 0;

        // Sort the array to use two-pointer technique
        sort(nums.begin(), nums.end());

        // Fix the largest side nums[k] and find pairs (i, j) such that nums[i] + nums[j] > nums[k]
        for (int k = n - 1; k >= 2; --k)
        {
            int i = 0, j = k - 1;
            while (i < j)
            {
                // If nums[i] + nums[j] > nums[k], all elements between i and j with j will satisfy
                if (nums[i] + nums[j] > nums[k])
                {
                    cnt += j - i; // Count all valid pairs
                    j--;          // Move right pointer left
                }
                else
                    i++; // Move left pointer right to increase sum
            }
        }

        return cnt; // Total number of valid triangles
    }
};

// Brute Force
/*
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        // Check all triplets
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    // Triangle inequality check
                    if (nums[i] + nums[j] > nums[k] &&
                        nums[j] + nums[k] > nums[i] &&
                        nums[i] + nums[k] > nums[j])
                        cnt++;
                }
            }
        }

        return cnt; // Total number of valid triangles
     }
};
*/
