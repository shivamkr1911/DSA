#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution 1 - Sliding Window using Fixed ASCII Array ===============
class Solution1
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;

        vector<int> hash(256, -1); // store last seen index of each character
        int l = 0, r = 0;          // left and right pointers for sliding window
        int maxi = 0;              // stores the maximum length found

        while (r < n)
        {
            // If current character already seen → move left pointer ahead of its last occurrence
            if (hash[s[r]] != -1)
                l = max(l, hash[s[r]] + 1);

            hash[s[r]] = r;              // update last seen index
            maxi = max(maxi, r - l + 1); // calculate window size
            r++;
        }
        return maxi;
    }
};

// =============== Optimal Solution 2 - Sliding Window using HashMap ===============
class Solution2
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;

        int l = 0;
        int maxi = 0;
        unordered_map<char, int> mpp; // store last index of each character

        for (int r = 0; r < n; ++r)
        {
            // If character repeats inside the window, move left pointer ahead
            if (mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l)
            {
                l = mpp[s[r]] + 1;
            }
            mpp[s[r]] = r;               // update character’s last seen index
            maxi = max(maxi, r - l + 1); // update maximum length
        }
        return maxi;
    }
};

// =============== Brute Force Solution ===============
class Solution3
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;
        int n = s.size();
        int maxi = 0;

        // Try every substring and check if all characters are unique
        for (int i = 0; i < n; ++i)
        {
            vector<int> freq(256, 0); // frequency array to mark visited chars
            for (int j = i; j < n; ++j)
            {
                if (freq[s[j]] == 1) // character already present → stop
                    break;

                int len = j - i + 1;
                freq[s[j]] = 1;        // mark as seen
                maxi = max(maxi, len); // update max length
            }
        }
        return maxi;
    }
};
