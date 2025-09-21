#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Recursive helper function to generate all combinations
    void solve(int ind, string &digits, vector<string> &res, string &ds, vector<string> &map)
    {
        // Base case: if we have formed a combination equal to the length of digits
        if (ind == digits.size())
        {
            res.push_back(ds); // Store the formed combination
            return;
        }

        // Convert the current digit character to integer (e.g., '2' → 2)
        int number = digits[ind] - '0';

        // Get the string of letters mapped to this digit
        string letters = map[number];

        // Try each letter corresponding to this digit
        for (int i = 0; i < letters.size(); ++i)
        {
            // Choose the current letter
            ds.push_back(letters[i]);

            // Recurse for the next digit
            solve(ind + 1, digits, res, ds, map);

            // Backtrack: remove the last added character before trying the next option
            ds.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res; // Stores the final list of combinations

        // Edge case: if no digits are given, return empty result
        if (digits.size() == 0)
            return res;

        string ds = ""; // Temporary string to build current combination

        // Mapping digits (0-9) → corresponding letters on phone keypad
        vector<string> map = {
            "",     // 0 → no letters
            "",     // 1 → no letters
            "abc",  // 2 → a,b,c
            "def",  // 3 → d,e,f
            "ghi",  // 4 → g,h,i
            "jkl",  // 5 → j,k,l
            "mno",  // 6 → m,n,o
            "pqrs", // 7 → p,q,r,s
            "tuv",  // 8 → t,u,v
            "wxyz"  // 9 → w,x,y,z
        };

        // Start backtracking from index 0
        solve(0, digits, res, ds, map);

        return res;
    }
};
