#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution ===============
class Solution1
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;

        int l = 0;                    // left pointer for sliding window
        int maxi = INT_MIN;           // stores max length
        unordered_map<char, int> mpp; // stores last seen index of each character

        for (int r = 0; r < n; ++r)
        {
            // If current character already exists in window → move left pointer
            if (mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l)
            {
                l = mpp[s[r]] + 1; // move 'l' just after previous duplicate
            }

            mpp[s[r]] = r;               // update last seen index
            maxi = max(maxi, r - l + 1); // calculate window size
        }

        return maxi;
    }
};

// =============== Brute Force Solution ===============
class Solution2
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;
        int n = s.size();
        int maxi = INT_MIN;

        // Check all substrings
        for (int i = 0; i < n; ++i)
        {
            vector<int> freq(255, 0); // frequency array for visited chars

            for (int j = i; j < n; ++j)
            {
                if (freq[s[j]] == 1) // duplicate found → stop
                    break;

                freq[s[j]] = 1;      // mark current char visited
                int len = j - i + 1; // current substring length
                maxi = max(maxi, len);
            }
        }

        return maxi;
    }
};
