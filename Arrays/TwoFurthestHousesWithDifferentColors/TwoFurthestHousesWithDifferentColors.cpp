#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<int> &colors)
    {
        int n = colors.size();
        int first = colors[0];
        int last = colors[n - 1];
        int res = -1;
        for (int i = 1; i < n; i++)
        {
            if (colors[i] != first)
                res = max(res, i);
            if (colors[i] != last)
                res = max(res, n - i - 1);
        }
        return res;
    }
};