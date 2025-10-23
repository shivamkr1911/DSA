#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasSameDigits(string s)
    {
        int n = s.size();

        // Keep reducing the string until only two digits remain
        while (n > 2)
        {
            // For every adjacent pair, replace s[i] with (a + b) % 10
            for (int i = 0; i < n - 1; ++i)
            {
                int a = s[i] - '0';          // Convert current character to digit
                int b = s[i + 1] - '0';      // Convert next character to digit
                s[i] = ((a + b) % 10) + '0'; // Store the new digit (as char)
            }
            n--; // Length reduces by 1 after each pass
        }

        // After reduction, check if the remaining two digits are same
        return (s[0] == s[1]);
    }
};
