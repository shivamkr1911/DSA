#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size();
        int ans = INT_MAX;
        long long sum = 0;
        unordered_map<int, int> mpp; // prefixSum % p → last index
        mpp[0] = -1;                 // base case for handling subarray from start

        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        int rem = totalSum % p; // required modulo adjustment

        // If total sum itself is divisible by p, no need to remove anything
        if (rem == 0)
            return 0;

        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            int curr = sum % p;

            // Needed prefix remainder so that removing subarray makes sum divisible by p
            int target = (curr - rem + p) % p;

            // If such prefix exists, update minimum length
            if (mpp.find(target) != mpp.end())
                ans = min(ans, i - mpp[target]);

            // Store/update the current prefix remainder index
            mpp[curr] = i;
        }

        // If we couldn't find valid removal
        if (ans == n)
            return -1;

        return ans;
    }
};
