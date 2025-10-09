#include <bits/stdc++.h>
using namespace std;

// ================== Optimal Solution - Using Sieve of Eratosthenes ==================

class Solution1
{
private:
    // Function to generate the Smallest Prime Factor (SPF) array using Sieve
    vector<int> getSieve(int n)
    {
        vector<int> spf(n + 1);

        // Step 1: Initialize SPF for each number as itself
        for (int i = 2; i <= n; i++)
            spf[i] = i;

        // Step 2: Apply Sieve logic to fill SPF array
        for (int i = 2; i * i <= n; i++)
        {
            // If 'i' is still its own SPF → means 'i' is prime
            if (i == spf[i])
            {
                // Mark SPF for all multiples of i
                for (int j = i * i; j <= n; j += i)
                {
                    // Only update if it hasn't been updated yet
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
        return spf;
    }

public:
    void sieve() {} // Empty function (for compatibility with problem structure)

    // Function to find all prime factors of N using the SPF array
    vector<int> findPrimeFactors(int N)
    {
        // Step 1: Get SPF array for numbers up to N
        vector<int> spf = getSieve(N);
        vector<int> ans;

        // Step 2: Repeatedly divide N by its smallest prime factor
        while (N != 1)
        {
            ans.push_back(spf[N]); // Add current smallest prime factor
            N /= spf[N];           // Reduce N
        }

        return ans; // Return list of prime factors
    }
};

// ================== Brute Force Solution ==================

class Solution2
{
public:
    void sieve() {} // Empty function (not used in brute force)

    // Function to find all prime factors by direct division
    vector<int> findPrimeFactors(int N)
    {
        vector<int> ans;

        // Try dividing by all numbers up to sqrt(N)
        for (int i = 2; i * i <= N; ++i)
        {
            // If i divides N
            if (N % i == 0)
            {
                // Keep dividing until i no longer divides N
                while (N % i == 0)
                {
                    ans.push_back(i);
                    N = N / i;
                }
            }
        }

        // If after the loop N > 1, then N itself is prime
        if (N > 1)
            ans.push_back(N);

        return ans;
    }
};
