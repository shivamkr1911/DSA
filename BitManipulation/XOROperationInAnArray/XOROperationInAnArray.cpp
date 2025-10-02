#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int xorOperation(int n, int start)
    {
        int ans = 0;
        // Initialize result with 0 because XOR with 0 gives the same number

        // Loop through n elements
        for (int i = 0; i < n; ++i)
        {
            // Each element in the array is defined as start + 2*i
            // Example: if start=3 and n=4 → elements = [3, 5, 7, 9]
            ans ^= start + 2 * i; // XOR current element with the result
        }

        // Final XOR of all elements
        return ans;
    }
};
