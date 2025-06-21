#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function to compute mid^n and compare it with m
    int compute(int mid, int n, int m)
    {
        long long prod = 1;
        for (int i = 1; i <= n; i++)
        {
            prod *= mid;
            if (prod > m)
                return 2; // Too large
        }
        if (prod == m)
            return 1; // Exact match
        return 0;     // Too small
    }

public:
    int nthRoot(int n, int m)
    {
        // Binary search for the nth root of m
        int low = 1, high = m;
        while (low <= high)
        {
            int mid = low + (high - low) / 2; // Avoid overflow
            int val = compute(mid, n, m);

            if (val == 1)
                return mid; // Found nth root
            else if (val == 2)
                high = mid - 1; // mid^n too big
            else
                low = mid + 1; // mid^n too small
        }
        return -1; // If no integer root exists
    }
};
