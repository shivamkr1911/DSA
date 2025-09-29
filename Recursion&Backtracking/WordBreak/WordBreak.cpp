#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Recursive helper function with memoization
    bool solve(string s, unordered_set<string> &dict, unordered_map<string, bool> &memo)
    {
        // Base case: if the string is empty, it means we successfully segmented it
        if (s.empty())
            return true;

        // If this substring was already computed, return its stored result
        if (memo.count(s))
            return memo[s];

        // Try all possible prefixes of the string
        for (int i = 1; i <= s.size(); ++i)
        {
            string prefix = s.substr(0, i); // Current prefix of length i

            // If the prefix exists in dictionary
            if (dict.count(prefix))
            {
                string rest = s.substr(i); // Remaining part after prefix

                // Recursively check if the rest of the string can be segmented
                if (solve(rest, dict, memo))
                    return memo[s] = true; // Store and return true if valid
            }
        }

        // If no valid segmentation found, mark this substring as false
        return memo[s] = false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // Convert wordDict into a set for faster lookups
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        // Memoization map: stores results of substrings
        unordered_map<string, bool> memo;

        // Start recursive check
        return solve(s, dict, memo);
    }
};
