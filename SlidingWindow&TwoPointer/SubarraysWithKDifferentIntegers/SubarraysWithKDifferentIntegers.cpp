#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution (Sliding Window + Inclusion-Exclusion) ===============
class Solution1
{
private:
    // Count subarrays with at most k distinct elements
    int cntSub(vector<int> &nums, int k)
    {
        if (k < 0)
            return 0; // no valid subarrays if k < 0

        int n = nums.size();
        int cnt = 0;
        unordered_map<int, int> mpp; // element → frequency in window
        int left = 0, right = 0;

        while (right < n)
        {
            mpp[nums[right]]++; // include nums[right]

            // Shrink window until distinct count ≤ k
            while (mpp.size() > k)
            {
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0)
                    mpp.erase(nums[left]);
                left++;
            }

            // All subarrays ending at right and starting from left..right are valid
            cnt += right - left + 1;
            right++;
        }
        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        // Exactly k distinct = at most k − at most (k−1)
        int a = cntSub(nums, k);
        int b = cntSub(nums, k - 1);
        return a - b;
    }
};

// =============== Brute Force ===============
class Solution2
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0;

        // Try all subarrays starting at index i
        for (int i = 0; i < n; ++i)
        {
            unordered_map<int, int> mpp; // track distinct elements

            for (int j = i; j < n; ++j)
            {
                mpp[nums[j]]++;

                // Valid subarray with exactly k distinct elements
                if (mpp.size() == k)
                    cnt++;
                else if (mpp.size() > k)
                    break; // stop if distinct count exceeds k
            }
        }
        return cnt;
    }
};
