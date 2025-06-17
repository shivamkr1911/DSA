#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDifference(string s)
    {
        vector<int> freq(26, 0);
        for (char c : s)
        {
            freq[c - 'a']++;
        }

        int maxOdd = 0;
        int minEven = INT_MAX;

        for (int count : freq)
        {
            if (count == 0)
                continue;
            if (count % 2 == 0)
                minEven = min(minEven, count);
            else
                maxOdd = max(maxOdd, count);
        }

        if (maxOdd == 0 || minEven == INT_MAX)
            return -1;
        return maxOdd - minEven;
    }
};