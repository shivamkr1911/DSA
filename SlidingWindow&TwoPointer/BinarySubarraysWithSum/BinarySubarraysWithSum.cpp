#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution (Sliding Window: uses count of subarrays with sum ≤ goal) ===============
class Solution1
{
private:
    // Count subarrays with sum <= goal
    int cntSub(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0; // no valid subarrays if goal < 0

        int n = nums.size();
        int l = 0, r = 0;
        int cnt = 0;
        int sum = 0;

        while (r < n)
        {
            sum += nums[r]; // include nums[r] in window

            // shrink window while sum exceeds goal
            while (l <= r && sum > goal)
            {
                sum -= nums[l];
                l++;
            }

            // all subarrays ending at r and starting from l..r are valid
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }

public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int a = cntSub(nums, goal);     // subarrays with sum <= goal
        int b = cntSub(nums, goal - 1); // subarrays with sum <= goal - 1
        return a - b;                   // exact sum = goal
    }
};

// =============== Better Solution (Prefix Sum + HashMap) ===============
class Solution2
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int preSum = 0;
        int cnt = 0;
        unordered_map<int, int> mpp; // prefixSum -> frequency
        mpp[0] = 1;                  // base case: sum from start equals goal

        for (int i = 0; i < nums.size(); ++i)
        {
            preSum += nums[i];

            int rem = preSum - goal; // required prefix to form sum = goal
            cnt += mpp[rem];         // add all subarrays ending here with sum = goal

            mpp[preSum]++; // store/update current prefix sum
        }
        return cnt;
    }
};

// =============== Brute Force (O(n²)) ===============
class Solution3
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int n = nums.size();
        int cnt = 0;

        // Try all subarrays nums[i..j]
        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = i; j < n; ++j)
            {
                sum += nums[j];
                if (sum == goal)
                    cnt++; // valid subarray found
            }
        }
        return cnt;
    }
};
