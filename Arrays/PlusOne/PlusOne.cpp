#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        // Traverse from last digit to first
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            // If digit is less than 9, simply increment and return
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            // If digit is 9, it becomes 0 and carry moves left
            digits[i] = 0;
        }
        // If all digits were 9, insert 1 at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
