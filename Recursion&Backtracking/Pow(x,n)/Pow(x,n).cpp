#include <bits/stdc++.h>
using namespace std;

// =============== Recursive Solution (Optimal) ===============
class Solution1
{
private:
    // Recursive helper function to calculate power
    double helper(double x, long long n)
    {
        if (n == 0)
            return 1.0;                 // base case: x^0 = 1
        double half = helper(x, n / 2); // compute power of half exponent
        // if n is even -> multiply half*half
        // if n is odd  -> multiply extra x
        return (n % 2 == 0) ? half * half : half * half * x;
    }

public:
    double myPow(double x, int n)
    {
        // Handle negative powers using reciprocal
        long long nn = n; // use long long to avoid overflow
        if (nn < 0)
            return 1.0 / helper(x, -nn); // reciprocal for negative exponent
        return helper(x, nn);            // call helper for positive exponent
    }
};

// =============== Iterative Binary Exponentiation (Better) ===============
class Solution2
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        long long nn = n;
        if (nn < 0)
            nn = -1 * nn; // make exponent positive
        while (nn)
        {
            if (nn % 2)
            { // if odd, multiply once
                ans = ans * x;
                nn = nn - 1;
            }
            else
            { // if even, square base
                x = x * x;
                nn = nn / 2;
            }
        }
        if (n < 0) // if original n was negative
            ans = (double)(1.0) / (double)(ans);
        return ans;
    }
};

// =============== Brute Force ===============
class Solution3
{
public:
    double myPow(double x, int n)
    {
        if (n == 0 || x == 1.0)
            return 1; // base cases
        long long temp = n;
        if (n < 0)
        {
            x = 1 / x;           // invert base if exponent is negative
            temp = -1 * 1LL * n; // make exponent positive
        }
        double ans = 1;
        for (long long i = 0; i < temp; i++)
        {
            ans *= x; // multiply base temp times
        }
        return ans;
    }
};
