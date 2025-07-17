#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string ans;
        int open = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                // Skip the first '(' of the primitive
                if (open > 0)
                    ans += c;
                open++; // Increment count of open brackets
            }
            else
            {
                open--; // Decrement count on ')'
                // Skip the last ')' of the primitive
                if (open > 0)
                    ans += c;
            }
        }

        return ans;
    }
};
