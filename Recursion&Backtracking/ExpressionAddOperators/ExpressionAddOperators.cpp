#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Backtracking helper function
    void backtrack(string &num, int target, int pos, long eval, long prev, string path, vector<string> &res)
    {
        // Base case: if we have processed the entire string
        if (pos == num.size())
        {
            // If the expression evaluates to the target, add to result
            if (eval == target)
                res.push_back(path);
            return;
        }

        // Try all possible partitions of num[pos...i]
        for (int i = pos; i < num.size(); i++)
        {
            // Avoid numbers with leading zero
            if (i != pos && num[pos] == '0')
                break;

            string currStr = num.substr(pos, i - pos + 1); // current number as string
            long curr = stol(currStr);                     // convert to number

            if (pos == 0)
            {
                // First number, just take it as starting point (no operator before it)
                backtrack(num, target, i + 1, curr, curr, currStr, res);
            }
            else
            {
                // Try addition
                backtrack(num, target, i + 1, eval + curr, curr, path + "+" + currStr, res);

                // Try subtraction
                backtrack(num, target, i + 1, eval - curr, -curr, path + "-" + currStr, res);

                // Try multiplication
                // (handle operator precedence by adjusting previous value)
                backtrack(num, target, i + 1, eval - prev + prev * curr, prev * curr, path + "*" + currStr, res);
            }
        }
    }

public:
    // Main function to generate all expressions that evaluate to target
    vector<string> addOperators(string num, int target)
    {
        vector<string> res;
        backtrack(num, target, 0, 0, 0, "", res);
        return res;
    }
};
