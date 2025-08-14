#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestGoodInteger(string num)
    {
        int i = 0, j = 1, k = 2; // 3-pointer window to check consecutive triplets
        char res = 0;            // stores the largest digit found in a valid triplet

        while (k < num.size())
        { // loop until the end of the string
            // check if all three chars are same and greater than current largest
            if (num[i] == num[j] && num[j] == num[k] && num[i] > res)
            {
                res = num[i];
            }
            i++;
            j++;
            k++; // slide the window forward
        }

        if (res == 0)
            return "";               // no valid triplet found
        return string(3, char(res)); // construct string with 3 same chars
    }
};
