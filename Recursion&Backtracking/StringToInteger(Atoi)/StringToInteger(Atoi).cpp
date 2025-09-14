#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Recursive helper function to build the integer
    int helper(const string &s, int i, int sign, long res)
    {
        // Base case: stop if out of bounds or non-digit encountered
        if (i >= s.size() || !isdigit(s[i]))
            return sign * res;

        int digit = s[i] - '0';

        // Check for overflow before adding the digit
        if (res > (INT_MAX - digit) / 10)
            return sign == 1 ? INT_MAX : INT_MIN;

        // Update result
        res = res * 10 + digit;

        // Recurse for next character
        return helper(s, i + 1, sign, res);
    }

public:
    int myAtoi(string s)
    {
        // Recursive approach (main function)
        int n = s.size();
        int sign = 1;
        int i = 0;

        // Skip leading whitespaces
        while (i < n && s[i] == ' ')
            i++;

        // Handle sign if present
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }

        // Start recursive conversion
        return helper(s, i, sign, 0);

        // Iterative approach (alternative)
        /*
        int n = s.size();
        int res = 0;
        int i = 0;
        int sign = 1;

        // Skip leading whitespaces
        while (i < n && s[i] == ' ') i++;

        // Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }

        // Convert digits and handle overflow
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            if (res > (INT_MAX - digit) / 10)
                return sign == 1 ? INT_MAX : INT_MIN;
            res = res * 10 + digit;
            i++;
        }
        return sign * res;
        */
    }
};
