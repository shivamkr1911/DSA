#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int possibleStringCount(string word)
    {
        int n = word.size();
        if (n == 1)
            return 1; // Only 1 possible if single character

        int cnt = 1; // Minimum possible count
        int i = 0, j = 1;

        while (i < n && j < n)
        {
            if (word[i] != word[j])
            {
                cnt += j - i - 1; // Count in-between same chars
                i = j;            // Move i to new char
                j++;
            }
            else
                j++; // Keep moving j if same
        }

        cnt += j - i - 1; // Add remaining
        return cnt;
    }
};