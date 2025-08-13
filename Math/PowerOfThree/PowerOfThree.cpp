#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n < 1)
            return false; // exclude 0 and negatives
        while (n % 3 == 0)
        {           // divisible by 3
            n /= 3; // divide by 3
        }
        return n == 1; // true if reduced to 1

        // Recursive Solution
        /*
        if (n < 1) return false;        // exclude 0 and negatives
        if (n == 1) return true;        // base: 3^0 = 1
        if (n % 3 != 0) return false;   // not divisible by 3
        return isPowerOfThree(n / 3);   // check smaller n
        */
    }
};
