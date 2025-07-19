#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = strs[0]; // Start with the first string
        for (int i = 1; i < strs.size(); i++)
        {
            int j = 0;
            // Compare characters while they match
            while (j < ans.size() && j < strs[i].size() && ans[j] == strs[i][j])
                j++;
            ans = ans.substr(0, j); // Trim to the matched prefix
        }
        return ans;
    }
};
