#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int upperBound(vector<int> &arr, int target)
    {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (arr[mid] <= target)
                low = mid + 1; // Move right if mid is ≤ target
            else
                high = mid - 1; // Move left if mid > target
        }

        return low; // First index where arr[i] > target
    }
};
