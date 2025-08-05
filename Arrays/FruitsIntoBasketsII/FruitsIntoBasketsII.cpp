#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int res = 0;
        int n = baskets.size();
        vector<bool> used(n, false); // Track used baskets

        for (int f : fruits)
        {
            bool placed = false;
            // Try to place fruit in an unused basket with enough capacity
            for (int b = 0; b < n; b++)
            {
                if (!used[b] && f <= baskets[b])
                {
                    used[b] = true; // Mark basket as used
                    placed = true;
                    break;
                }
            }
            if (!placed)
                res++; // Fruit couldn’t be placed
        }
        return res; // Return count of unplaced fruits
    }
};
