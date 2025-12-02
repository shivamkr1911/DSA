#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution (Only for arrays with positives + zeros) ===============
class Solution1
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        int n = arr.size();
        int left = 0, right = 0;
        long long sum = 0; // current window sum
        int maxLen = 0;    // longest subarray with sum = k

        while (right < n)
        {
            sum += arr[right]; // expand window

            // shrink window if sum becomes greater than k
            while (sum > k && left <= right)
            {
                sum -= arr[left];
                left++;
            }

            // update longest valid window
            if (sum == k)
                maxLen = max(maxLen, right - left + 1);

            right++;
        }
        return maxLen;
    }
};

// =============== Better Solution (Handles positives + negatives) ===============
class Solution2
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        int n = arr.size();
        int sum = 0; // prefix sum
        int maxLen = 0;
        map<int, int> preSumMap; // prefixSum → first index

        for (int i = 0; i < n; ++i)
        {
            sum += arr[i];

            // case when subarray starts from index 0
            if (sum == k)
                maxLen = max(maxLen, i + 1);

            int rem = sum - k; // k = sum - rem → needed sum removal
            if (preSumMap.find(rem) != preSumMap.end())
            {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            // store prefix only when not seen earlier
            if (preSumMap.find(sum) == preSumMap.end())
                preSumMap[sum] = i;
        }
        return maxLen;
    }
};

// =============== Brute Force (O(n²)) ===============
class Solution3
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        int n = arr.size();
        int len = 0;

        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = i; j < n; ++j)
            {
                sum += arr[j]; // sum from i to j
                if (sum == k)
                    len = max(len, j - i + 1);
            }
        }
        return len;
    }
};

// =============== Extreme Brute Force (O(n³)) ===============
class Solution4
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        int n = arr.size();
        int len = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                int sum = 0;
                for (int l = i; l <= j; l++)
                    sum += arr[l]; // compute subarray sum manually

                if (sum == k)
                    len = max(len, j - i + 1);
            }
        }
        return len;
    }
};
