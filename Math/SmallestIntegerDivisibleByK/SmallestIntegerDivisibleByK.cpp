#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {

        // If k is divisible by 2 or 5, no repunit (111...) can be divisible by k
        if (k % 2 == 0 || k % 5 == 0)
            return -1;

        int num = 0; // stores remainder of the repunit modulo k

        // Try lengths from 1 to k (Pigeonhole principle ensures answer ≤ k)
        for (int len = 1; len <= k; ++len)
        {
            // Construct repunit modulo k:
            // num = (previous * 10 + 1) % k
            num = (num * 10 + 1) % k;

            // If divisible → return current length
            if (num == 0)
                return len;
        }

        return -1; // no such repunit found
    }
};
