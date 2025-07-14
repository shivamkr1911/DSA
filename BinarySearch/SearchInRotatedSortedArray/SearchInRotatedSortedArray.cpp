#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] == target)
                return mid; // Found target

            // Left half is sorted
            else if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                    high = mid - 1; // Target in left
                else
                    low = mid + 1; // Target in right
            }

            // Right half is sorted
            else
            {
                if (nums[mid] <= target && target <= nums[high])
                    low = mid + 1; // Target in right
                else
                    high = mid - 1; // Target in left
            }
        }

        return -1; // Not found
    }
};
