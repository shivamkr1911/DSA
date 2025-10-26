#include <bits/stdc++.h>
using namespace std;

// ================= Left-to-Right Version (bit manipulation) =================
class Solution1
{
public:
    int binaryToDecimal(string &b)
    {
        int ans = 0; // Initialize result as 0
        for (char c : b)
        {
            ans = (ans << 1) | (c - '0'); // Shift result left by 1 (multiply by 2)
                                          // Add current bit using bitwise OR
        }
        return ans; // Return the decimal value
    }
};

// ================= Right-to-Left Version (using power of 2 multiplier) =================
class Solution2
{
public:
    int binaryToDecimal(string &b)
    {
        int n = b.size();
        int res = 0;    // Initialize result
        int power2 = 1; // Start with 2^0
        for (int i = n - 1; i >= 0; --i)
        {
            if (b[i] == '1')
                res += power2; // Add current power of 2 if bit is 1
            power2 *= 2;       // Move to next higher power of 2
        }
        return res; // Return the decimal value
    }
};
