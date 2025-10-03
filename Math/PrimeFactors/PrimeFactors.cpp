#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution 2 ===============
class Solution1
{
public:
    // Function to return all prime factors of n
    vector<int> primeFac(int n)
    {
        vector<int> ans;
        // Check divisibility up to sqrt(n)
        for (int i = 2; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                ans.push_back(i); // i is a prime factor
                // Remove all multiples of i
                while (n % i == 0)
                {
                    n /= i;
                }
            }
        }
        // If remaining n > 1, it is a prime factor
        if (n != 1)
            ans.push_back(n);
        return ans;
    }
};

// =============== Optimal Solution 1 ===============
class Solution2
{
public:
    // Function to return all prime factors of n
    vector<int> primeFac(int n)
    {
        vector<int> ans;
        // Check divisibility up to n
        for (int i = 2; i <= n; ++i)
        {
            if (n % i == 0)
            {
                ans.push_back(i); // i is a prime factor
                // Remove all multiples of i
                while (n % i == 0)
                {
                    n /= i;
                }
            }
        }
        return ans;
    }
};

// =============== Better Solution ===============
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
        return cnt == 2; // prime has exactly 2 divisors
    }

public:
    // Function to return all prime factors of n
    vector<int> primeFac(int n)
    {
        vector<int> ans;
        for (int i = 1; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                if (isPrime(i))
                    ans.push_back(i); // i is a prime factor
                if (n / i != i && isPrime(n / i))
                    ans.push_back(n / i); // paired factor
            }
        }
        return ans;
    }
};

// =============== Brute Force ===============
class Solution4
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
        return cnt == 2; // prime check
    }

public:
    // Function to return all prime factors of n
    vector<int> primeFac(int n)
    {
        vector<int> ans;
        for (int i = 2; i <= n; ++i)
        {
            if (n % i == 0 && isPrime(i))
                ans.push_back(i); // i is prime factor
        }
        return ans;
    }
};
