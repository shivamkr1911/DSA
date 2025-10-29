#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestNumber(int n)
    {

        int cntBits = 0; // Count how many bits are needed to represent n

        // Count bits by right-shifting n until it becomes 0
        while (n >= 1)
        {
            cntBits++;
            n >>= 1; // Move to the next bit
        }

        // Create a number with all bits = 1 for that bit length
        // Example: if cntBits = 3 → (1 << 3) = 8 → 8 - 1 = 7 (111 in binary)
        int ans = (1 << cntBits) - 1;

        return ans; // Return the smallest number with those many 1-bits
    }
};
