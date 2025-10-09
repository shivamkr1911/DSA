#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void print_divisors(int n)
    {
        // ================== Optimal Solution ==================

        vector<int> ans; // To store all divisors

        // Loop runs till sqrt(n)
        // Because divisors appear in pairs (i and n/i)
        for (int i = 1; i * i <= n; ++i)
        {

            // If i divides n completely, it is a divisor
            if (n % i == 0)
            {
                ans.push_back(i); // Store the smaller divisor

                // If n/i is not equal to i (to avoid duplicates for perfect squares)
                if (n / i != i)
                {
                    ans.push_back(n / i); // Store the paired (larger) divisor
                }
            }
        }

        // Sort divisors to print in ascending order
        sort(ans.begin(), ans.end());

        // Print all divisors
        for (int i : ans)
        {
            cout << i << " ";
        }

        // ================== Brute Force Solution ==================

        /*
        // Check every number from 1 to n
        for (int i = 1; i <= n; ++i) {
            // If i divides n completely, print it
            if (n % i == 0)
                cout << i << " ";
        }
        */
    }
};
