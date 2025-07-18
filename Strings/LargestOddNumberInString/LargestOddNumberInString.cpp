#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestOddNumber(string num)
    {
        // Traverse the string from the end to the beginning
        for (int i = num.size() - 1; i >= 0; i--)
        {
            // Check if the current digit is odd
            if ((num[i] - '0') % 2 == 1)
            {
                // Return the substring from start to this position (inclusive)
                return num.substr(0, i + 1);
            }
        }
        // No odd digit found — return an empty string
        return "";
    }
};
