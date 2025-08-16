#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximum69Number(int num)
    {
        // Convert number to string
        string s = to_string(num);

        // Change first '6' to '9'
        for (char &c : s)
        {
            if (c == '6')
            {
                c = '9';
                break; // only one change needed
            }
        }

        // Convert back to integer
        return stoi(s);
    }
};
