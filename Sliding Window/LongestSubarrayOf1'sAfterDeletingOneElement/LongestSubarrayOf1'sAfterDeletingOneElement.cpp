#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        // Optimal Solution (Two Pointers / Sliding Window)
        int n = nums.size();
        int zeroCnt = 0; // count of zeros in window
        int left = 0, right = 0;
        int res = 0; // store max length

        while (right < n)
        {
            if (nums[right] == 0)
                zeroCnt++; // include current element
            // shrink window if more than 1 zero
            while (zeroCnt > 1)
            {
                if (nums[left] == 0)
                    zeroCnt--;
                left++;
            }
            res = max(res, right - left); // update max length
            right++;
        }
        return res;

        // Brute Force (O(n^2))
        /*
        int n = nums.size();
        int res = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int cnt = 0, maxCnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;        // delete one element
                if (nums[j] == 1) {
                    cnt++;
                    maxCnt = max(maxCnt, cnt);  // update max streak
                } else {
                    cnt = 0;   // reset count on zero
                }
            }
            res = max(res, maxCnt);
        }
        return res;
        */
    }
};
