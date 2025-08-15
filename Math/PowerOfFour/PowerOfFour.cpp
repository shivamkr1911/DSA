#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n < 1)
            return false; // Must be positive
        while (n % 4 == 0)
        {
            n /= 4; // Keep dividing by 4
        }
        return n == 1; // True if reduced to 1

        // Recursive Solution
        /*
        if (n < 1) return false;          // Must be positive
        if (n == 1) return true;          // Reached 1 → true
        if (n % 4 != 0) return false;     // Not divisible by 4 → false
        return isPowerOfFour(n / 4);      // Recur with n/4
        */
    }
};
