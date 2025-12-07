#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countOdds(int low, int high)
    {
        // If both ends are even → number of odds is exactly half the range
        if (low % 2 == 0 && high % 2 == 0)
            return (high - low) / 2;

        // Otherwise at least one boundary is odd → one extra odd exists
        return (high - low) / 2 + 1;

        // One-liner alternative (same logic using integer division)
        // return (high + 1) / 2 - low / 2;
    }
};
