#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Recursive function to generate all binary strings of length n
    void generateAll(int n, string curr, vector<string> &all)
    {
        if (curr.size() == n)
        {                        // base case: current string has length n
            all.push_back(curr); // store the completed binary string
            return;
        }
        generateAll(n, curr + "0", all); // append '0' and recurse
        generateAll(n, curr + "1", all); // append '1' and recurse
    }

public:
    // Function to return all binary strings of length n
    vector<string> binstr(int n)
    {
        vector<string> all;
        generateAll(n, "", all); // start recursion with empty string
        return all;
    }
};
