#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
class Solution
{
private:
    // Helper function to generate valid binary strings
    void helper(int n, string curr, vector<string> &result)
    {
        // Base case: if length reaches n, store the string
        if (curr.size() == n)
        {
            result.push_back(curr);
            return;
        }
        // Always add '0'
        helper(n, curr + "0", result);
        // Add '1' only if last character is not '1' (to avoid "11")
        if (curr.empty() || curr.back() != '1')
            helper(n, curr + "1", result);
    }

public:
    vector<string> generateBinaryStrings(int n)
    {
        vector<string> result;
        helper(n, "", result); // Start recursion with empty string
        return result;
    }
};

// Brute Force
/*
class Solution {
  private:
    // Generate all binary strings of length n
    void generateAll(int n, string curr, vector<string> &all) {
        if (curr.size() == n) {
            all.push_back(curr);
            return;
        }
        generateAll(n, curr + "0", all);
        generateAll(n, curr + "1", all);
    }

    // Check if string is valid (no two consecutive '1's)
    bool isValid(string &s) {
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '1' && s[i + 1] == '1')
                return false;
        }
        return true;
    }

  public:
    vector<string> generateBinaryStrings(int n) {
        vector<string> all;   // Stores all binary strings
        vector<string> valid; // Stores only valid ones

        generateAll(n, "", all); // Generate all possible strings

        // Filter only valid strings
        for (auto& s : all) {
            if (isValid(s))
                valid.push_back(s);
        }
        return valid;
    }
};
*/
