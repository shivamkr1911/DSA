#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution - Using Sieve ===============

class Solution1
{
private:
    // Function to compute smallest prime factor (spf) for each number up to n
    vector<int> getSieve(int n)
    {
        vector<int> spf(n + 1);

        // initialize spf[i] = i
        for (int i = 2; i <= n; i++)
            spf[i] = i;

        // mark smallest prime factors using sieve logic
        for (int i = 2; i * i <= n; i++)
        {
            if (i == spf[i]) // i is prime
            {
                for (int j = i * i; j <= n; j += i)
                {
                    if (spf[j] == j) // not updated yet
                        spf[j] = i;  // set smallest prime factor
                }
            }
        }
        return spf;
    }

public:
    void sieve() {} // placeholder, no-op

    // Function to return prime factors of N using precomputed spf
    vector<int> findPrimeFactors(int N)
    {
        vector<int> spf = getSieve(N);
        vector<int> ans;

        while (N != 1)
        {
            ans.push_back(spf[N]); // add smallest prime factor
            N /= spf[N];           // reduce N
        }
        return ans;
    }
};

// =============== Brute Force Solution ===============

class Solution2
{
public:
    void sieve() {} // placeholder, no-op

    // Function to return prime factors of N by checking divisibility
    vector<int> findPrimeFactors(int N)
    {
        vector<int> ans;
        for (int i = 2; i * i <= N; ++i)
        {
            if (N % i == 0)
            {
                while (N % i == 0)
                {
                    ans.push_back(i); // add factor i
                    N = N / i;        // reduce N
                }
            }
        }
        if (N > 1)
            ans.push_back(N); // if remaining N is prime
        return ans;
    }
};
