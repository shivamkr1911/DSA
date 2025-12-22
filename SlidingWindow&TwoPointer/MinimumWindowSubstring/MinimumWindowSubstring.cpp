#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution (Sliding Window) ===============
class Solution1
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        int hash[256] = {0}; // frequency map for characters of t
        for (int i = 0; i < m; ++i)
            hash[t[i]]++;

        int cnt = 0;        // number of matched characters
        int mini = INT_MAX; // minimum window length
        int startInd = -1;  // starting index of minimum window

        int l = 0, r = 0;

        while (r < n)
        {
            // If current character is needed, count it
            if (hash[s[r]] > 0)
                cnt++;

            hash[s[r]]--; // reduce frequency (even if not needed)

            // Try to shrink window when all characters are matched
            while (cnt == m)
            {
                if (r - l + 1 < mini)
                {
                    mini = r - l + 1;
                    startInd = l;
                }

                // Restore frequency while shrinking from left
                hash[s[l]]++;
                if (hash[s[l]] > 0)
                    cnt--; // one required character is removed

                l++;
            }
            r++;
        }

        return startInd == -1 ? "" : s.substr(startInd, mini);
    }
};

// =============== Brute Force ===============
class Solution2
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        int mini = INT_MAX;
        int startInd = -1;

        // Try every possible starting index
        for (int i = 0; i < n; ++i)
        {
            int hash[256] = {0};
            for (int j = 0; j < m; ++j)
                hash[t[j]]++;

            int cnt = 0;

            // Expand substring from index i
            for (int j = i; j < n; ++j)
            {
                if (hash[s[j]] > 0)
                    cnt++;

                hash[s[j]]--;

                // If all characters matched, update minimum window
                if (cnt == m)
                {
                    if (j - i + 1 < mini)
                    {
                        mini = j - i + 1;
                        startInd = i;
                    }
                }
            }
        }

        return startInd == -1 ? "" : s.substr(startInd, mini);
    }
};