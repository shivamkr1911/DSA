#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKRotation(vector<int> &arr)
    {
        int n = arr.size();
        int low = 0, high = n - 1;
        int mini = INT_MAX; // Store minimum element
        int idx = -1;       // Store index of minimum element

        while (low <= high)
        {
            int mid = (low + high) / 2;

            // If subarray is sorted
            if (arr[low] <= arr[high])
            {
                if (arr[low] < mini)
                {
                    mini = arr[low];
                    idx = low;
                }
                break;
            }

            // Left half is sorted
            if (arr[low] <= arr[mid])
            {
                if (arr[low] < mini)
                {
                    mini = arr[low];
                    idx = low;
                }
                low = mid + 1;
            }
            // Right half is sorted
            else
            {
                if (arr[mid] < mini)
                {
                    mini = arr[mid];
                    idx = mid;
                }
                high = mid - 1;
            }
        }

        return idx; // Number of rotations = index of minimum
    }
};
