#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution - Two Pointer ===============
class Solution1
{
private:
    // Counts subarrays with at most k odd numbers
    int cntSub(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 0, r = 0;
        int cnt = 0;
        int sum = 0; // stores count of odd numbers in current window

        while (r < n)
        {
            sum += nums[r] % 2; // add 1 if nums[r] is odd

            // Shrink window until odd count ≤ k
            while (l <= r && sum > k)
            {
                sum -= nums[l] % 2;
                l++;
            }

            // All subarrays ending at r and starting from l..r are valid
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }

public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        // Exactly k odds = (at most k odds) - (at most k-1 odds)
        int a = cntSub(nums, k);
        int b = cntSub(nums, k - 1);
        return a - b;
    }
};

// =============== Better Solution - Prefix Sum + Map ===============
class Solution2
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        unordered_map<int, int> mpp; // oddCount → frequency
        mpp[0] = 1;                  // base case

        int oddCnt = 0;
        int ans = 0;

        for (int x : nums)
        {
            oddCnt += x % 2; // increment if x is odd

            // Count subarrays ending here with exactly k odd numbers
            if (mpp.count(oddCnt - k))
                ans += mpp[oddCnt - k];

            mpp[oddCnt]++;
        }
        return ans;
    }
};

// =============== Brute Force ===============
class Solution3
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;

        // Try all subarrays
        for (int i = 0; i < n; ++i)
        {
            int oddCnt = 0;
            for (int j = i; j < n; ++j)
            {
                if (nums[j] % 2 == 1)
                    oddCnt++;

                if (oddCnt == k)
                    ans++;
            }
        }
        return ans;
    }
};