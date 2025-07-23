#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int depth = 0;    // Current depth
        int maxDepth = 0; // Maximum depth encountered

        for (char ch : s)
        {
            if (ch == '(')
            {
                depth++;
                maxDepth = max(maxDepth, depth); // Update max depth if needed
            }
            else if (ch == ')')
            {
                depth--;
            }
        }

        return maxDepth;
    }
};
