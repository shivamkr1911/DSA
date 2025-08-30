#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // Optimal Solution - Dutch National Flag Algorithm
        int low = 0, mid = 0;       // low -> boundary for 0s, mid -> current element
        int high = nums.size() - 1; // high -> boundary for 2s

        // Process elements until mid crosses high
        while (mid <= high)
        {
            if (nums[mid] == 0) // Case 0: swap with low pointer
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) // Case 1: keep in middle, just move forward
            {
                mid++;
            }
            else // Case 2: swap with high pointer
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }

        // Better Solution - Counting Method
        // Count 0s and 1s, then fill array accordingly
        /*
        int cnt0 = 0, cnt1 = 0;
        int n = nums.size();

        // Count number of 0s and 1s
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0) cnt0++;
            else if (nums[i] == 1) cnt1++;
        }

        for (int i = 0; i < cnt0; i++) nums[i] = 0; // Fill 0s

        for (int i = cnt0; i < cnt0 + cnt1; i++) nums[i] = 1; // Fill 1s

        for (int i = cnt0 + cnt1; i < n; i++) nums[i] = 2; // Fill remaining 2s
        */

        // Brute Force - Sorting Approach
        // Just sort the array using built-in sort (like merge sort / quicksort)
        /*
        sort(nums.begin(), nums.end());
        */
    }
};
