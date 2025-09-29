#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to convert a decimal number to its binary representation
    string decToBinary(int n)
    {
        string res = ""; // String to store binary digits

        // Keep dividing the number by 2 until it becomes 0
        while (n >= 1)
        {
            if (n % 2 != 0)
                res += "1"; // If remainder is 1 → add '1'
            else
                res += "0"; // If remainder is 0 → add '0'

            n /= 2; // Divide the number by 2 for next iteration
        }

        // Since we constructed binary in reverse (LSB first),
        // we need to reverse the string to get the correct order
        reverse(res.begin(), res.end());

        return res; // Return the final binary string
    }
};
