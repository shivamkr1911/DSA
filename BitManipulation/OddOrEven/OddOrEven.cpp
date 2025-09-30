#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isEven(int n)
    {
        // Optimal check for even number using bitwise AND
        // The last bit 0 means even, 1 means odd
        return (n & 1) == 0;

        // Brute force alternative:
        // return n % 2 == 0;
    }
};
