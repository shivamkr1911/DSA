#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.size();
        int res = 0;
        int i = 0;
        int sign = 1;

        // Step 1: Skip leading whitespaces
        while (i < n && s[i] == ' ')
            i++;

        // Step 2: Check for sign
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }

        // Step 3: Convert digits to number until non-digit is found
        while (i < n && isdigit(s[i]))
        {
            int digit = s[i] - '0';

            // Step 4: Handle overflow
            if (res > (INT_MAX - digit) / 10)
                return sign == 1 ? INT_MAX : INT_MIN;

            res = res * 10 + digit;
            i++;
        }

        // Step 5: Apply sign
        return sign * res;
    }
};
