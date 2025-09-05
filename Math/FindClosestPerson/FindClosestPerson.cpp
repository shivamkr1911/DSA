#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findClosest(int x, int y, int z)
    {
        // If distance of x and y from z is same, return 0
        if (abs(x - z) == abs(y - z))
            return 0;

        // If x is closer to z, return 1, else return 2
        return (abs(x - z)) < (abs(y - z)) ? 1 : 2;
    }
};
