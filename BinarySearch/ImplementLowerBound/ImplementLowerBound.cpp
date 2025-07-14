#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lowerBound(vector<int> &arr, int target)
    {
        // Binary search for lower bound: first element >= target
        int low = 0, high = arr.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] >= target)
                high = mid - 1; // Move left to find first >= target
            else
                low = mid + 1; // Move right
        }
        return low; // Index of lower bound
    }
};
