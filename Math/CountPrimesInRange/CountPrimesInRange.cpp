#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution ===============
class Solution1
{
private:
    // Function to generate the Sieve of Eratosthenes up to 'n'
    vector<int> getSieve(int n)
    {
        vector<int> prime(n + 1, 1); // initially assume all numbers are prime
        prime[0] = 0, prime[1] = 0;  // 0 and 1 are not prime

        // mark non-prime numbers using sieve logic
        for (int i = 2; i * i <= n; i++)
        {
            if (prime[i] == 1) // if i is still marked prime
            {
                // mark all multiples of i as non-prime
                for (int j = i * i; j <= n; j += i)
                {
                    prime[j] = 0;
                }
            }
        }
        return prime;
    }

public:
    // Function to count primes in the range [L, R]
    int countPrimes(int L, int R)
    {
        vector<int> prime = getSieve(R); // get prime status up to R
        int cnt = 0;

        // prefix sum array of primes — each index stores count of primes ≤ i
        for (int i = 2; i <= R; ++i)
        {
            cnt += prime[i]; // running total of primes
            prime[i] = cnt;  // prefix sum update
        }

        // result = primes up to R - primes up to (L-1)
        return prime[R] - prime[L - 1];
    }
};

// =============== Better Solution ===============
/*
class Solution2
{
private:
    // Function to generate prime numbers up to 'n' using sieve
    vector<int> getSieve(int n)
    {
        vector<int> prime(n + 1, 1);
        prime[0] = 0, prime[1] = 0;

        for (int i = 2; i * i <= n; i++)
        {
            if (prime[i] == 1)
            {
                for (int j = i * i; j <= n; j += i)
                {
                    prime[j] = 0;
                }
            }
        }
        return prime;
    }

public:
    // Function to count primes in range [L, R]
    int countPrimes(int L, int R)
    {
        vector<int> prime = getSieve(R); // get prime status up to R
        int cnt = 0;

        // count only primes between L and R directly
        for (int i = L; i <= R; ++i)
        {
            if (prime[i] == 1)
                cnt++;
        }
        return cnt;
    }
};
*/

// =============== Brute Force Solution ===============
/*
class Solution3
{
private:
    // Check if a number is prime by counting divisors
    bool isPrime(int n)
    {
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (n % i == 0)
                cnt++;
        }
        return cnt == 2 ? true : false; // only 2 divisors → prime
    }

public:
    // Count primes between L and R using isPrime()
    int countPrimes(int L, int R)
    {
        int cnt = 0;
        for (int i = L; i <= R; ++i)
        {
            if (isPrime(i))
                cnt++;
        }
        return cnt;
    }
};
*/
