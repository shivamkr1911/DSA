#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function to count how many subarrays are needed
    // if no subarray has sum greater than maxSum
    int countSubarrays(vector<int> &nums, int maxSum)
    {
        int currentSum = 0;
        int subarrayCount = 1; // start with one subarray
        for (int i = 0; i < nums.size(); i++)
        {
            if (currentSum + nums[i] <= maxSum)
                currentSum += nums[i]; // add to current subarray
            else
            {
                subarrayCount++;      // start a new subarray
                currentSum = nums[i]; // reset sum for new subarray
            }
        }
        return subarrayCount;
    }

public:
    // Function to split array into k subarrays such that
    // the largest sum among them is minimized
    int splitArray(vector<int> &nums, int k)
    {
        int low = *max_element(nums.begin(), nums.end());   // min possible max sum
        int high = accumulate(nums.begin(), nums.end(), 0); // max possible sum
        while (low <= high)
        {
            int mid = (low + high) / 2; // candidate max sum
            if (countSubarrays(nums, mid) > k)
                low = mid + 1; // need more subarrays, increase max sum
            else
                high = mid - 1; // can split with fewer or equal subarrays, try smaller sum
        }
        return low; // minimum largest sum possible
    }
};
