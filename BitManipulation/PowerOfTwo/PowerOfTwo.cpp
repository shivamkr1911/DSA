#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        // Optimal: n > 0 and only one set bit in n
        return (n > 0 && (n & (n - 1)) == 0);

        // Brute Force:
        /*
        if (n == 1) return true;          // 2^0 case
        while (n > 1) {
            if (n % 2 != 0) return false; // not divisible by 2 → false
            n /= 2;                        // divide by 2
        }
        return (n == 1);                   // ended at 1 → true
        */
    }
};
