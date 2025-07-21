#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubstring(string s)
    {
        int n = s.size();
        int res = 0;
        int left = 0, right = 0;
        map<char, int> mpp;
        mpp['a'] = 0;
        mpp['b'] = 0;
        mpp['c'] = 0;

        while (right < n)
        {
            mpp[s[right]]++; // Include current character in the window

            // Check if window has at least one of each 'a', 'b', and 'c'
            while (mpp['a'] > 0 && mpp['b'] > 0 && mpp['c'] > 0)
            {
                res += n - right; // Count all substrings ending at or after right
                mpp[s[left]]--;   // Shrink window from the left
                left++;
            }

            right++;
        }
        return res;
    }
};
