#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, int> get(int a, int b)
    {
        // Swap values of a and b using XOR
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        return {a, b};
    }
};
