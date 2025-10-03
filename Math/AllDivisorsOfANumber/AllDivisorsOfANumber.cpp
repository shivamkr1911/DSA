#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution ===============
class Solution1
{
public:
    // Function to print all divisors of n
    void print_divisors(int n)
    {
        vector<int> ans;
        // Check divisibility up to sqrt(n)
        for (int i = 1; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                ans.push_back(i); // i is a divisor
                if (n / i != i)
                    ans.push_back(n / i); // paired divisor
            }
        }
        sort(ans.begin(), ans.end()); // sort divisors
        for (int i : ans)
            cout << i << " "; // print each divisor
    }
};

// =============== Brute Force Solution ===============
class Solution2
{
public:
    // Function to print all divisors of n
    void print_divisors(int n)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (n % i == 0)
                cout << i << " "; // print divisor
        }
    }
};
