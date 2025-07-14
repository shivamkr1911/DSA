#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();

        // Edge case: only one element
        if (n == 1)
            return nums[0];

        // Check if single element is at start
        if (nums[0] != nums[1])
            return nums[0];

        // Check if single element is at end
        else if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1, high = n - 2;

        // Binary Search
        while (low <= high)
        {
            int mid = (low + high) / 2;

            // Found single element
            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
                return nums[mid];

            // Check if in left part of single element
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
                (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
                low = mid + 1;

            // Else in right part
            else
                high = mid - 1;
        }

        return -1; // Should never reach here if input is valid
    }
};
