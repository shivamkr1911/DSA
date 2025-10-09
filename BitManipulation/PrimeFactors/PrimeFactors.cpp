#include <bits/stdc++.h>
using namespace std;

// ================== Optimal Solution 2 ==================

class Solution1
{
public:
    vector<int> primeFac(int n)
    {
        vector<int> ans;

        // Loop runs till sqrt(n)
        // Because a larger factor of n must be paired with a smaller one
        for (int i = 2; i * i <= n; ++i)
        {
            // If i divides n, it is a prime factor
            if (n % i == 0)
            {
                ans.push_back(i);

                // Divide n repeatedly by i to remove all its occurrences
                while (n % i == 0)
                {
                    n /= i;
                }
            }
        }

        // If n is not 1 at the end, then n itself is a prime factor
        if (n != 1)
            ans.push_back(n);

        return ans;
    }
};

// ================== Optimal Solution 1 ==================

class Solution2
{
public:
    vector<int> primeFac(int n)
    {
        vector<int> ans;

        // Loop from 2 to n
        for (int i = 2; i <= n; ++i)
        {
            // If i divides n, it’s a prime factor
            if (n % i == 0)
            {
                ans.push_back(i);

                // Remove all multiples of this factor
                while (n % i == 0)
                {
                    n /= i;
                }
            }
        }
        return ans;
    }
};

// ================== Better Solution ==================

class Solution3
{
private:
    // Function to check if a number is prime
    bool isPrime(int n)
    {
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (n % i == 0)
                cnt++;
        }
        // Prime numbers have exactly 2 divisors
        return cnt == 2 ? true : false;
    }

public:
    vector<int> primeFac(int n)
    {
        vector<int> ans;

        // Loop till sqrt(n) for efficiency
        for (int i = 1; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                // Check if divisor i is prime
                if (isPrime(i))
                    ans.push_back(i);

                // Check for corresponding divisor n/i
                if (n / i != i)
                {
                    if (isPrime(n / i))
                        ans.push_back(n / i);
                }
            }
        }
        return ans;
    }
};

// ================== Brute Force Solution ==================

class Solution4
{
private:
    // Function to check primality
    bool isPrime(int n)
    {
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (n % i == 0)
                cnt++;
        }
        return cnt == 2 ? true : false;
    }

public:
    vector<int> primeFac(int n)
    {
        vector<int> ans;

        // Check all numbers up to n
        for (int i = 2; i <= n; ++i)
        {
            // If i divides n and is prime, store it
            if (n % i == 0)
            {
                if (isPrime(i))
                    ans.push_back(i);
            }
        }
        return ans;
    }
};
