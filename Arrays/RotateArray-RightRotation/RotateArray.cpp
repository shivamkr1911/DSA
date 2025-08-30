#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        // Store last k elements
        vector<int> temp(k);
        for (int i = 0; i < k; i++)
        {
            temp[i] = nums[n - k + i];
        }

        // Shift first (n-k) elements to right
        for (int i = n - k - 1; i >= 0; i--)
        {
            nums[i + k] = nums[i];
        }

        // Place stored elements at front
        for (int i = 0; i < k; i++)
        {
            nums[i] = temp[i];
        }

        return;

        // Or - In-place rotation, O(1) extra space
        /*
        int n = nums.size();
        k = k % n; // Handle if k > n
        reverse(nums.begin(), nums.begin() + (n - k)); // Reverse first part
        reverse(nums.begin() + n - k, nums.end());     // Reverse last part
        reverse(nums.begin(), nums.end());             // Reverse whole array
        return;
        */
    }
};
