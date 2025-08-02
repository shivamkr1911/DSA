#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int maxi = INT_MIN; // Store maximum palindrome length
        int start = -1;     // Store starting index of longest palindrome

        for (int i = 0; i < n; i++)
        {
            // Case 1: Odd length palindrome centered at i
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right])
            {
                left--;
                right++;
            }
            int len = right - left - 1;
            if (len > maxi)
            {
                maxi = len;
                start = left + 1;
            }

            // Case 2: Even length palindrome centered between i and i+1
            left = i, right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right])
            {
                left--;
                right++;
            }
            len = right - left - 1;
            if (len > maxi)
            {
                maxi = len;
                start = left + 1;
            }
        }
        return s.substr(start, maxi); // Return longest palindromic substring
    }
};
