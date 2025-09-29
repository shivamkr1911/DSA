#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int binaryToDecimal(string &b)
    {
        int n = b.size();
        int res = 0;    // Stores the final decimal value
        int power2 = 1; // Represents powers of 2 (starting from 2^0)

        // Traverse binary string from right to left
        for (int i = n - 1; i >= 0; --i)
        {
            if (b[i] == '1')
                res += power2; // Add current power of 2 if bit is '1'
            power2 *= 2;       // Move to the next power of 2
        }

        return res; // Return the decimal equivalent
    }
};
