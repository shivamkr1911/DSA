#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCeil(vector<int> &arr, int x)
    {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (arr[mid] >= x)
                high = mid - 1; // Try to find smaller valid ceil
            else
                low = mid + 1; // Move right if mid is too small
        }

        return (low < n) ? low : -1; // Return index of ceil, else -1 if not found
    }
};
