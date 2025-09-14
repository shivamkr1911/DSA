#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
class Solution
{
private:
    // Helper function to generate valid binary strings
    void helper(int n, string curr, vector<string> &result)
    {
        // Base case: if length reaches n, add to result
        if (curr.size() == n)
        {
            result.push_back(curr);
            return;
        }
        // Place '0' only if last character is not '0' (to avoid "00")
        if (curr.empty() || curr.back() != '0')
            helper(n, curr + "0", result);
        // Always try placing '1'
        helper(n, curr + "1", result);
    }

public:
    vector<string> validStrings(int n)
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
    // Generate all possible binary strings of length n
    void generateAll(int n, string curr, vector<string> &all) {
        if (curr.size() == n) {
            all.push_back(curr);
            return;
        }
        generateAll(n, curr + "0", all);
        generateAll(n, curr + "1", all);
    }

    // Check if string is valid (no two consecutive '0's)
    bool isValid(string &s) {
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0' && s[i + 1] == '0')
                return false;
        }
        return true;
    }

public:
    vector<string> validStrings(int n) {
        vector<string> all;   // Stores all generated strings
        vector<string> valid; // Stores only valid strings

        generateAll(n, "", all); // Generate all binary strings

        // Filter valid strings
        for (auto& s : all) {
            if (isValid(s))
                valid.push_back(s);
        }
        return valid;
    }
};
*/
