#include <bits/stdc++.h>
using namespace std;

// ================== Optimal Solution 2 - Optimized Sieve of Eratosthenes ==================
class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0; // No primes less than 2

        // Create a boolean array initialized with 1 (true)
        // prime[i] = 1 means i is considered prime initially
        vector<int> prime(n, 1);

        // 0 and 1 are not prime numbers
        prime[0] = prime[1] = 0;

        // Outer loop runs till sqrt(n)
        for (int i = 2; i * i < n; ++i)
        {
            // If i is still marked as prime
            if (prime[i] == 1)
            {
                // Start marking multiples of i as non-prime from i*i (optimization)
                for (int j = i * i; j < n; j += i)
                {
                    prime[j] = 0;
                }
            }
        }

        // Count total primes below n
        int cnt = 0;
        for (int i = 2; i < n; ++i)
        {
            if (prime[i] == 1)
                cnt++;
        }

        return cnt;
    }
};

// ================== Optimal Solution 1 - Sieve of Eratosthenes Algorithm ==================

class Solution2
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0; // No primes less than 2

        vector<int> prime(n, 1);
        prime[0] = prime[1] = 0; // 0 and 1 are not primes

        // Mark all multiples of each prime as non-prime
        for (int i = 2; i < n; ++i)
        {
            if (prime[i] == 1)
            {
                for (int j = 2 * i; j < n; j += i)
                {
                    prime[j] = 0;
                }
            }
        }

        // Count total primes below n
        int cnt = 0;
        for (int i = 2; i < n; ++i)
        {
            if (prime[i] == 1)
                cnt++;
        }

        return cnt;
    }
};

// ================== Brute Force Solution ==================

class Solution3
{
private:
    // Helper function to check if a number is prime
    bool isPrime(int n)
    {
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (n % i == 0)
                cnt++;
        }
        return cnt == 2 ? true : false; // Prime if divisible by exactly 2 numbers
    }

public:
    int countPrimes(int n)
    {
        int cnt = 0;
        // Check every number from 2 to n-1
        for (int i = 2; i < n; ++i)
        {
            if (isPrime(i))
                cnt++;
        }
        return cnt;
    }
};
