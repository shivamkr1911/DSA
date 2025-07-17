#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.size();
        string temp = "", ans = "";
        int left = 0, right = n - 1;

        // Skip leading spaces
        while (left <= right && s[left] == ' ')
            left++;

        // Skip trailing spaces
        while (right >= left && s[right] == ' ')
            right--;

        while (left <= right)
        {
            char c = s[left];

            if (c != ' ')
            {
                temp += c; // Build the current word
            }
            else if (!temp.empty())
            {
                // Add the word at the beginning of ans
                if (!ans.empty())
                    ans = temp + " " + ans;
                else
                    ans = temp;
                temp = "";

                // Skip extra spaces between words
                while (left + 1 <= right && s[left + 1] == ' ')
                    left++;
            }
            left++;
        }

        // Add the last word if exists
        if (!temp.empty())
        {
            if (!ans.empty())
                ans = temp + " " + ans;
            else
                ans = temp;
        }

        return ans;
    }
};
