#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution (Bit Manipulation) ===============
class Solution1
{
public:
    int divide(int dividend, int divisor)
    {
        // Handle overflow case: INT_MIN / -1 exceeds 32-bit range
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine if the result should be positive
        bool isPositive = (dividend > 0) == (divisor > 0);

        // Convert both numbers to positive long long to prevent overflow
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);
        long long ans = 0;

        // Subtract divisor multiples using bit shifts
        while (n >= d)
        {
            int cnt = 0;

            // Find the largest multiple (d * 2^cnt) <= n
            while (n >= (d << (cnt + 1)))
            {
                cnt++;
            }

            ans += 1LL << cnt; // add corresponding multiple to answer
            n -= d << cnt;     // reduce n by that multiple
        }

        // Apply correct sign
        ans = isPositive ? ans : -ans;

        // Clamp the result within 32-bit integer range
        if (ans > INT_MAX)
            return INT_MAX;
        if (ans < INT_MIN)
            return INT_MIN;

        return (int)ans;
    }
};

// =============== Brute Force Solution (Repeated Subtraction) ===============
class Solution2
{
public:
    int divide(int dividend, int divisor)
    {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine sign of result
        bool isPositive = (dividend > 0) == (divisor > 0);

        // Convert to positive values
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);
        long long ans = 0;

        // Repeatedly subtract divisor from dividend
        while (n >= d)
        {
            n -= d;
            ans++;
        }

        // Apply sign
        ans = isPositive ? ans : -ans;

        return (int)ans;
    }
};
