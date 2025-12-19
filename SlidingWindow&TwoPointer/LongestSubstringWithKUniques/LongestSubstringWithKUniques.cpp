#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution (Sliding Window) ===============
class Solution1
{
public:
    int longestKSubstr(string &s, int k)
    {
        int n = s.size();
        unordered_map<char, int> mpp; // character → frequency in current window
        int maxi = -1;                // stores maximum valid length
        int left = 0, right = 0;      // window pointers

        while (right < n)
        {
            mpp[s[right]]++; // include current character

            // If more than k distinct characters, shrink from left
            if (mpp.size() > k)
            {
                mpp[s[left]]--;
                if (mpp[s[left]] == 0)
                    mpp.erase(s[left]);
                left++;
            }

            // If window has exactly k distinct characters, update answer
            if (mpp.size() == k)
                maxi = max(maxi, right - left + 1);

            right++;
        }
        return maxi;
    }
};

// =============== Brute Force ===============
class Solution2
{
public:
    int longestKSubstr(string &s, int k)
    {
        int n = s.size();
        int maxi = -1;

        // Try all substrings starting at index i
        for (int i = 0; i < n; ++i)
        {
            unordered_map<char, int> mpp;

            for (int j = i; j < n; ++j)
            {
                mpp[s[j]]++;

                // Valid substring with exactly k distinct characters
                if (mpp.size() == k)
                    maxi = max(maxi, j - i + 1);

                // More than k distinct → stop expanding
                else if (mpp.size() > k)
                    break;
            }
        }
        return maxi;
    }
};
