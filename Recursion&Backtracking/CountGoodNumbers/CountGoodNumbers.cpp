#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    const int MOD = 1e9 + 7; // Modulo value to keep numbers within range

    // Recursive modular exponentiation (fast power)
    long long modPow2(long long base, long long exp, long long mod)
    {
        if (exp == 0)
            return 1;                                 // Base case
        long long half = modPow2(base, exp / 2, mod); // Recurse on half power
        long long res = (half * half) % mod;          // Square the result
        if (exp % 2 == 1)                             // If exponent is odd
            res = (res * base) % mod;
        return res;
    }

    // Iterative modular exponentiation (fast power)
    long long modPow1(long long base, long long exp, long long mod)
    {
        long long res = 1;
        while (exp > 0)
        {
            if (exp % 2 == 1)
                res = (res * base) % mod; // Multiply when odd power
            base = (base * base) % mod;   // Square base
            exp /= 2;                     // Reduce exponent
        }
        return res;
    }

public:
    int countGoodNumbers(long long n)
    {
        // Recursive Solution
        long long evenCnt = (n + 1) / 2; // Number of even indices → can place {0,2,4,6,8} (5 choices)
        long long oddCnt = n / 2;        // Number of odd indices  → can place primes {2,3,5,7} (4 choices)

        // Compute (5^evenCnt * 4^oddCnt) % MOD
        long long ans1 = modPow2(5, evenCnt, MOD);
        long long ans2 = modPow2(4, oddCnt, MOD);

        return (ans1 * ans2) % MOD;

        // Optimal Solution (iterative fast power)
        /*
        long long evenCnt = (n + 1) / 2;
        long long oddCnt = n / 2;

        long long ans1 = modPow1(5, evenCnt, MOD);
        long long ans2 = modPow1(4, oddCnt, MOD);

        return (ans1 * ans2) % MOD;
        */

        // Brute Force (inefficient → O(n))
        /*
        const int MOD = 1e9 + 7;
        long long evenCnt = (n + 1) / 2;
        long long oddCnt = n / 2;
        long long ans = 1;

        // Multiply 5 for every even index
        for (int i = 0; i < evenCnt; ++i) ans = (ans * 5) % MOD;
        // Multiply 4 for every odd index
        for (int i = 0; i < oddCnt; ++i) ans = (ans * 4) % MOD;

        return ans;
        */
    }
};
