#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();

        // Binary Search without using STL
        int ans = n; // Default insert at end
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] >= target)
            {
                ans = mid;      // Possible position found
                high = mid - 1; // Search left part
            }
            else
            {
                low = mid + 1; // Search right part
            }
        }
        return ans;

        // Using STL:
        // return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
