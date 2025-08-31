#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findSubarray(vector<int> &arr)
    {
        int n = arr.size();
        int sum = 0;                  // current subarray sum
        int maxSum = -1;              // maximum sum found so far
        int start = 0;                // start index of current subarray
        int resStart = 0, resEnd = 0; // start and end indices of result subarray

        for (int i = 0; i < n; ++i)
        {
            if (arr[i] >= 0)
            { // include non-negative element
                sum += arr[i];

                // Update maxSum if current sum is greater
                // or if equal sum but earlier start index
                if (sum > maxSum || (sum == maxSum && start <= resStart))
                {
                    maxSum = sum;
                    resStart = start;
                    resEnd = i;
                }
            }
            else
            { // reset on negative element
                sum = 0;
                start = i + 1; // next subarray may start after this
            }
        }

        // If all elements are negative, return {-1}
        if (maxSum < 0)
            return {-1};

        // Build result subarray from resStart to resEnd
        vector<int> ans(arr.begin() + resStart, arr.begin() + resEnd + 1);
        return ans;
    }
};
