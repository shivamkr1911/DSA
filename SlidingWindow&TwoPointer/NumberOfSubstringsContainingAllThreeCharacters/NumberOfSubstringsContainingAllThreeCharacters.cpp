#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution ===============
class Solution1
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        int cnt = 0;

        // lastSeen[i] stores the last index of character ('a'+i)
        int lastSeen[3] = {-1, -1, -1};

        for (int i = 0; i < n; ++i)
        {
            // Update last seen index of current character
            lastSeen[s[i] - 'a'] = i;

            // Minimum index among last seen of a, b, c
            // +1 gives number of valid substrings ending at i
            cnt += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
        }

        return cnt;
    }
};

// =============== Better Solution ===============
class Solution2
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        int cnt = 0;

        // Fix starting index i
        for (int i = 0; i < n; ++i)
        {
            int hash[3] = {0, 0, 0}; // track presence of a, b, c

            // Expand substring from i
            for (int j = i; j < n; ++j)
            {
                hash[s[j] - 'a'] = 1;

                // Once all three characters are present
                if (hash[0] + hash[1] + hash[2] == 3)
                {
                    // All substrings ending from j to n-1 are valid
                    cnt += n - j;
                    break;
                }
            }
        }
        return cnt;
    }
};

// =============== Brute Force ===============
class Solution3
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        int cnt = 0;

        // Try all substrings
        for (int i = 0; i < n; ++i)
        {
            int hash[3] = {0, 0, 0};

            for (int j = i; j < n; ++j)
            {
                hash[s[j] - 'a'] = 1;

                // Count substring if it contains a, b, and c
                if (hash[0] + hash[1] + hash[2] == 3)
                    cnt++;
            }
        }
        return cnt;
    }
};