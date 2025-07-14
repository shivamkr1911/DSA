#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();

        // Single element is always peak
        if (n == 1)
            return 0;

        // Check if first element is peak
        if (nums[0] > nums[1])
            return 0;

        // Check if last element is peak
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int low = 1, high = n - 2;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            // Found peak element
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
                return mid;

            // Go right if mid in increasing part
            else if (nums[mid] < nums[mid + 1])
                low = mid + 1;

            // Go left if mid in decreasing part
            else
                high = mid - 1;
        }

        return -1; // Should never reach here
    }
};
