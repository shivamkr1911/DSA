#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        int res = -1;
        vector<int> freq(501, 0); // Frequency array

        for (int num : arr)
        {
            freq[num]++; // Count frequency
        }

        for (int i = 1; i <= 500; ++i)
        {
            if (freq[i] == i)
                res = i; // Update if lucky number found
        }

        return res;
    }
};
