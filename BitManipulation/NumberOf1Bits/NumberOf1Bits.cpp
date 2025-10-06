#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution (Brian Kernighan’s Algorithm) ===============
class Solution1
{
public:
    int hammingWeight(int n)
    {
        int cnt = 0; // count of set bits

        while (n != 0)
        {
            cnt++;             // found one set bit
            n = (n & (n - 1)); // clear the rightmost set bit
        }

        return cnt; // return total set bits
    }
};

// =============== Brute Force Solution (Bit-by-Bit Checking) ===============
class Solution2
{
public:
    int hammingWeight(int n)
    {
        int cnt = 0; // count of set bits

        while (n > 0)
        {
            cnt += n & 1; // check if last bit is 1
            n /= 2;       // move to next bit
        }

        return cnt; // return total set bits
    }
};
