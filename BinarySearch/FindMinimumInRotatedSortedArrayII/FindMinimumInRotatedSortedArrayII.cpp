#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = INT_MAX;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            // Handle duplicates
            if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                ans = min(ans, nums[low]);
                low++, high--;
                continue;
            }

            // Left half sorted
            if (nums[low] <= nums[mid])
            {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // Right half sorted
            else
            {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};
