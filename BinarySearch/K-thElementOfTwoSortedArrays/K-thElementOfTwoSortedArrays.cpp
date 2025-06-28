#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        int n1 = a.size();
        int n2 = b.size();

        // Always binary search on the smaller array
        if (n1 > n2)
            return kthElement(b, a, k);

        int low = max(0, k - n2); // Minimum elements to pick from a[]
        int high = min(k, n1);    // Maximum elements to pick from a[]

        while (low <= high)
        {
            int mid1 = (low + high) >> 1; // Number of elements taken from a[]
            int mid2 = k - mid1;          // Remaining elements taken from b[]

            // Left side and right side elements around the cut
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 < n1)
                r1 = a[mid1]; // Smallest in right part of a[]
            if (mid2 < n2)
                r2 = b[mid2]; // Smallest in right part of b[]
            if (mid1 - 1 >= 0)
                l1 = a[mid1 - 1]; // Largest in left part of a[]
            if (mid2 - 1 >= 0)
                l2 = b[mid2 - 1]; // Largest in left part of b[]

            // Check if partition is correct
            if (l1 <= r2 && l2 <= r1)
            {
                return max(l1, l2); // Correct partition, kth element is max of left parts
            }
            else if (l1 > r2)
            {
                high = mid1 - 1; // l1 too big, move left in a[]
            }
            else
            {
                low = mid1 + 1; // l2 too big, move right in a[]
            }
        }
        return 0; // Should never reach here if k is valid
    }
};
