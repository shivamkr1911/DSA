#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        if (arr[0] > arr[1])
            return 0;
        if (arr[n - 1] > arr[n - 2])
            return n - 1;
        int low = 1, high = n - 2;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
                return mid;
            // If the mid element is part of the increasing sequence
            if (arr[mid] < arr[mid + 1])
                low = mid + 1;
            // If the mid element is part of the decreasing sequence
            else
                high = mid - 1;
        }
        return -1;
    }
};