#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string sortedDigits(int num)
    {
        string s = to_string(num); // convert number to string
        sort(s.begin(), s.end());  // sort digits in ascending order
        return s;                  // return sorted digit string
    }

public:
    bool reorderedPowerOf2(int n)
    {
        unordered_set<string> powOf2; // store sorted digits of powers of 2
        int i = 1;                    // start from 2^0
        while (i <= 1e9)
        {                                   // loop until 2^30 (fits in int)
            powOf2.insert(sortedDigits(i)); // insert sorted digits of power of 2
            i *= 2;                         // move to next power of 2
        }
        return powOf2.count(sortedDigits(n)) > 0; // check if n matches any
    }
};
