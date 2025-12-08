#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution ===============
class Solution1
{
public:
    int countTriples(int n)
    {
        unordered_set<int> squares; // store all perfect squares ≤ n²

        // Precompute squares: i² for all 1 ≤ i ≤ n
        for (int i = 1; i <= n; i++)
            squares.insert(i * i);

        int cnt = 0;

        // Check all (a, b) pairs where 1 ≤ a, b ≤ n
        for (int a = 1; a <= n; a++)
        {
            for (int b = 1; b <= n; b++)
            {
                int sum = a * a + b * b; // check if a² + b² is a perfect square
                if (squares.count(sum))  // if yes → c exists such that c² = sum
                    cnt++;
            }
        }

        return cnt; // number of valid (a, b, c) triples
    }
};

// =============== Brute Force ===============
class Solution2
{
public:
    int countTriples(int n)
    {
        int cnt = 0;

        // Try all pairs (a, b) and compute possible c
        for (int a = 1; a <= n; ++a)
        {
            for (int b = 1; b <= n; ++b)
            {
                int c2 = a * a + b * b; // c² value
                int c = sqrt(c2);       // potential integer c

                // valid if c is an integer and c ≤ n
                if (c <= n && c * c == c2)
                    cnt++;
            }
        }

        return cnt;
    }
};
