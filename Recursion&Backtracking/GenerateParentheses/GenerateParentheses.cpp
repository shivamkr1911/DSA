#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
class Solution
{
private:
    // Helper function to generate valid parentheses combinations
    void helper(int n, vector<string> &res, string curr, int open, int close)
    {
        // If both open and close parentheses are used up, add to result
        if (open == n && close == n)
        {
            res.push_back(curr);
            return;
        }
        // Add an opening bracket if still available
        if (open < n)
            helper(n, res, curr + "(", open + 1, close);

        // Add a closing bracket if it does not exceed open count
        if (close < open)
            helper(n, res, curr + ")", open, close + 1);
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        // Start recursion with empty string and no parentheses placed
        helper(n, res, "", 0, 0);
        return res;
    }
};

// Brute Force
/*
class Solution {
private:
    // Check if the generated string is a valid parentheses sequence
    bool isValid(string s) {
        int balance = 0;
        for (char c: s) {
            if (c == '(') balance++;
            else balance--;
            if (balance < 0) return false; // More ')' than '(' at some point
        }
        return balance == 0; // Valid if balanced at the end
    }

    // Generate all possible sequences of length 2*n
    void generateAll(int n, string curr, vector<string> &res) {
        if (curr.size() == 2 * n) {
            if (isValid(curr))       // Only add if valid
                res.push_back(curr);
            return;
        }
        // Try adding '('
        generateAll(n, curr + "(", res);
        // Try adding ')'
        generateAll(n, curr + ")", res);
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateAll(n, "", res); // Start generating from empty string
        return res;
    }
};
*/
