#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string makeFancyString(string s)
    {
        string res;
        int cnt = 1; // Count of consecutive characters
        res += s[0]; // Add the first character to result

        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == s[i - 1])
                cnt++; // Same as previous, increment count
            else
                cnt = 1; // Different character, reset count

            if (cnt < 3)
                res += s[i]; // Add only if it's not the 3rd repeat
        }

        return res;
    }
};
