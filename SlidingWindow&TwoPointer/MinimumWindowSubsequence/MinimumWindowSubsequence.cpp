#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        int minLen = INT_MAX; // length of smallest valid window
        int start = -1;       // starting index of result window

        int i = 0; // pointer for s1

        while (i < n)
        {
            int j = 0; // pointer for s2

            // Forward scan: try to match s2 as a subsequence in s1
            while (i < n && j < m)
            {
                if (s1[i] == s2[j])
                    j++;
                i++;
            }

            // If full subsequence not matched, no further valid window possible
            if (j < m)
                break;

            // Backward shrink to minimize the window
            int end = i - 1; // last matched position in s1
            j = m - 1;

            while (end >= 0 && j >= 0)
            {
                if (s1[end] == s2[j])
                    j--;
                end--;
            }

            end++; // move to actual starting index of window

            // Update minimum window if smaller
            if (i - end < minLen)
            {
                minLen = i - end;
                start = end;
            }

            // Restart search just after the current window start
            i = end + 1;
        }

        return start == -1 ? "" : s1.substr(start, minLen);
    }
};
