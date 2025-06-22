#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        // Pad with fill char to make length divisible by k
        int rem = s.size() % k;
        if (rem != 0)
        {
            s.append(k - rem, fill);
        }

        // Divide the string into chunks of size k
        vector<string> ans;
        for (int i = 0; i < s.size(); i += k)
        {
            ans.push_back(s.substr(i, k));
        }

        return ans;
    }
};