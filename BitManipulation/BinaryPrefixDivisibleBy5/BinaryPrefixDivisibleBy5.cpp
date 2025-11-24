#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &nums)
    {
        vector<bool> ans;
        int value = 0; // stores prefix value modulo 5

        for (int i = 0; i < nums.size(); ++i)
        {
            // Build prefix as a binary number:
            // multiply previous by 2, add current bit, and take modulo 5
            value = (value * 2 + nums[i]) % 5;

            // If prefix % 5 == 0 → divisible by 5
            if (value == 0)
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};
