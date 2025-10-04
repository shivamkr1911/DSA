#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution 2 - Optimized Sieve ===============
class Solution1
{
public:
    // Function to count primes less than n using optimized sieve
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0; // no primes less than 2

        vector<int> prime(n, 1);
        prime[0] = prime[1] = 0; // 0 and 1 are not primes

        // mark non-primes starting from i*i
        for (int i = 2; i * i < n; ++i)
        {
            if (prime[i] == 1)
            {
                for (int j = i * i; j < n; j += i)
                    prime[j] = 0; // mark multiples as non-prime
            }
        }

        int cnt = 0;
        for (int i = 2; i < n; ++i)
            if (prime[i] == 1)
                cnt++; // count primes

        return cnt;
    }
};

// =============== Optimal Solution 1 - Basic Sieve ===============
class Solution2
{
public:
    // Function to count primes less than n using sieve
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0; // no primes less than 2

        vector<int> prime(n, 1);
        prime[0] = prime[1] = 0; // 0 and 1 are not primes

        // mark non-primes starting from 2*i
        for (int i = 2; i < n; ++i)
        {
            if (prime[i] == 1)
            {
                for (int j = 2 * i; j < n; j += i)
                    prime[j] = 0; // mark multiples as non-prime
            }
        }

        int cnt = 0;
        for (int i = 2; i < n; ++i)
            if (prime[i] == 1)
                cnt++; // count primes

        return cnt;
    }
};

// =============== Brute Force ===============

class Solution3
{
private:
    // Check if a number is prime
    bool isPrime(int n)
    {
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (n % i == 0)
                cnt++;
        }
        return cnt == 2; // prime if divisible exactly by 1 and itself
    }

public:
    // Count primes less than n using brute force
    int countPrimes(int n)
    {
        int cnt = 0;
        for (int i = 2; i < n; ++i)
        {
            if (isPrime(i))
                cnt++;
        }
        return cnt;
    }
};
