#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to calculate XOR of numbers from 1 to n
    // There is a pattern in XOR from 1 to n:
    // n % 4 == 0 → result = n
    // n % 4 == 1 → result = 1
    // n % 4 == 2 → result = n + 1
    // n % 4 == 3 → result = 0
    int xor1ToN(int n)
    {
        if (n % 4 == 1)
            return 1; // Pattern case 1
        else if (n % 4 == 2)
            return n + 1; // Pattern case 2
        else if (n % 4 == 3)
            return 0; // Pattern case 3
        else
            return n; // Pattern case 0 (n % 4 == 0)
    }

public:
    // Function to calculate XOR of numbers in range [l, r]
    int findXOR(int l, int r)
    {
        // XOR from l to r = (XOR from 1 to r) ^ (XOR from 1 to l-1)
        // Because numbers before l cancel out
        return xor1ToN(l - 1) ^ xor1ToN(r);
    }
};
