#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution ===============
class Solution1
{
public:
    void print_divisors(int n)
    {
        vector<int> ans;

        // Traverse only up to √n to collect divisor pairs
        for (int i = 1; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                ans.push_back(i); // first divisor
                if (n / i != i)
                    ans.push_back(n / i); // paired divisor (avoid duplicate for perfect square)
            }
        }

        // Sorting ensures divisors are printed in increasing order
        sort(ans.begin(), ans.end());

        // Print all collected divisors
        for (int i : ans)
            cout << i << " ";
    }
};
// =============== Brute Force ===============
class Solution2
{
public:
    void print_divisors(int n)
    {
        // Check every number from 1 to n to see if it divides n
        for (int i = 1; i <= n; ++i)
        {
            if (n % i == 0)
                cout << i << " ";
        }
    }
};
