#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        // Use XOR to find bits that are different between start and goal.
        int num = start ^ goal;
        int cnt = 0;

        // --- Method 1: Active Solution (Fixed Iteration) ---
        // Iterate through all 32 bits of the integer.
        for (int i = 0; i < 32; ++i)
        {
            // Check if the i-th bit of 'num' is 1 and add it to the count.
            cnt += (num >> i) & 1;
        }

        // --- Method 2: Commented-Out Alternative (Variable Iteration) ---
        // This loop is often slightly faster as it stops once all set bits
        // have been checked, rather than always running 32 times.
        /*
        while (num > 0) {
             // Check if the last bit is 1.
             cnt += num & 1;
             // Right-shift the number to check the next bit.
             num /= 2;
        }
        */
        // The total count is the number of flips needed.
        return cnt;
    }
};