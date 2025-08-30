#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        // Optimal solution - Works only when array has positive numbers or 0s
        int n = arr.size();
        int left = 0, right = 0;
        long long sum = 0; // current window sum
        int maxLen = 0;    // stores max length
        while (right < n)
        {
            sum += arr[right]; // expand window by including right element
            // shrink window until sum <= k
            while (sum > k && left <= right)
            {
                sum -= arr[left];
                left++;
            }
            // if sum matches k, update max length
            if (sum == k)
            {
                maxLen = max(maxLen, right - left + 1);
            }
            right++; // move right pointer
        }
        return maxLen;

        // Better solution Or Optimal for arr with positive or negative values
        /*
        int n = arr.size();
        int sum = 0;                       // prefix sum
        int maxLen = 0;                    // stores max length
        map<int, int> preSumMap;           // stores prefix sum -> index
        for (int i = 0; i < n; ++i) {
            sum += arr[i];                 // update prefix sum
            if (sum == k)
                maxLen = max(maxLen, i + 1);   // whole subarray matches
            int rem = sum - k;                 // required prefix sum
            if (preSumMap.find(rem) != preSumMap.end()) {
                int len = i - preSumMap[rem];  // length of subarray
                maxLen = max(maxLen, len);
            }
            // store prefix sum only if not already present
            if (preSumMap.find(sum) == preSumMap.end()) {
                preSumMap[sum] = i;
            }
        }
        return maxLen;
        */

        // Brute force - O(n^2)
        /*
        int n = arr.size();
        int len = 0;
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += arr[j];                // subarray sum from i to j
                if (sum == k)
                    len = max(len, j - i + 1);
            }
        }
        return len;
        */

        // Extreme brute force - O(n^3)
        /*
        int n = arr.size();
        int len = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int sum = 0;
                for (int l = i; l <= j; l++) {
                    sum += arr[l];           // calculate sum of subarray i..j
                }
                if (sum == k)
                    len = max(len, j - i + 1);
            }
        }
        return len;
        */
    }
};
