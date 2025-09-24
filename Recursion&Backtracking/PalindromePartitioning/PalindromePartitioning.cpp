#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Recursive function to explore all possible palindrome partitions
    void func(int ind, string &s, vector<string> &path, vector<vector<string>> &res)
    {
        // Base case: if we reach the end of the string, store the current partition
        if (ind == s.size())
        {
            res.push_back(path);
            return;
        }

        // Try partitioning the string from index 'ind' to every possible 'i'
        for (int i = ind; i < s.size(); ++i)
        {
            // If substring s[ind...i] is a palindrome
            if (isPalindrome(s, ind, i))
            {
                // Choose this palindrome substring
                path.push_back(s.substr(ind, i - ind + 1));

                // Recurse for the remaining substring starting from i+1
                func(i + 1, s, path, res);

                // Backtrack: remove the last chosen substring to explore new partitions
                path.pop_back();
            }
        }
    }

    // Utility function to check if substring s[start...end] is a palindrome
    bool isPalindrome(string &s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false; // Not a palindrome
        }
        return true; // Palindrome
    }

public:
    // Main function: returns all palindrome partitioning of string 's'
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res; // Stores all possible partitions
        vector<string> path;        // Stores the current partition being built
        func(0, s, path, res);      // Start recursive exploration from index 0
        return res;
    }
};
