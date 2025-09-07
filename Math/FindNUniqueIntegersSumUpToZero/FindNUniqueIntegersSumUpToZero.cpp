#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> arr;

        // If n is odd, include 0 in the array
        if (n % 2 != 0)
            arr.push_back(0);

        // Add pairs of numbers (i and -i) to keep the sum = 0
        for (int i = 1; i <= n / 2; ++i)
        {
            arr.push_back(i);  // positive number
            arr.push_back(-i); // corresponding negative number
        }

        // The array will always sum up to 0
        return arr;
    }
};
