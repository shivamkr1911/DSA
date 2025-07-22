#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findFloor(vector<int> &arr, int x)
    {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (arr[mid] <= x)
                low = mid + 1; // Try to find larger valid floor
            else
                high = mid - 1; // Move left if mid is too large
        }

        return high; // Return index of floor
    }
};
