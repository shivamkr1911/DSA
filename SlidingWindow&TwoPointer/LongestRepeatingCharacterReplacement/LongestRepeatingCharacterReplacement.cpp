#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution ===============
class Solution1
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int l = 0, r = 0;
        int maxLen = 0;          // stores longest valid substring length
        int maxFreq = 0;         // stores count of most frequent character
        vector<int> hash(26, 0); // frequency map for characters 'A' to 'Z'

        while (r < n)
        {
            hash[s[r] - 'A']++;                       // add current character
            maxFreq = max(maxFreq, hash[s[r] - 'A']); // update most frequent char count

            // If more than k replacements needed → shrink window
            if ((r - l + 1) - maxFreq > k)
            {
                hash[s[l] - 'A']--;
                l++;
            }

            // Valid window → update maximum length
            if ((r - l + 1) - maxFreq <= k)
                maxLen = max(maxLen, r - l + 1);

            r++;
        }
        return maxLen;
    }
};

// =============== Better Solution ===============
class Solution2
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int l = 0, r = 0;
        int maxLen = 0, maxFreq = 0;
        vector<int> hash(26, 0);

        while (r < n)
        {
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);

            // Shrink window while replacements exceed k
            while ((r - l + 1) - maxFreq > k)
            {
                hash[s[l] - 'A']--;

                // Recalculate maxFreq (since we removed a char)
                maxFreq = 0;
                for (int i = 0; i < 26; i++)
                    maxFreq = max(maxFreq, hash[i]);
                l++;
            }

            // Update max length for valid window
            if ((r - l + 1) - maxFreq <= k)
                maxLen = max(maxLen, r - l + 1);

            r++;
        }
        return maxLen;
    }
};

// =============== Brute Force ===============
class Solution3
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int maxLen = 0;

        // Try all substrings
        for (int i = 0; i < n; ++i)
        {
            int maxFreq = 0;
            vector<int> hash(26, 0);

            for (int j = i; j < n; ++j)
            {
                hash[s[j] - 'A']++;
                maxFreq = max(maxFreq, hash[s[j] - 'A']);

                int changes = (j - i + 1) - maxFreq; // chars needing replacement

                // If replacements allowed ≤ k, update maxLen
                if (changes <= k)
                    maxLen = max(maxLen, j - i + 1);
                else
                    break; // more than k replacements → stop expanding
            }
        }
        return maxLen;
    }
};
