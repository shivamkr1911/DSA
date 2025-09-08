#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function to check if a number contains any '0' digit
    bool isNonZero(int num)
    {
        while (num > 0)
        {
            if (num % 10 == 0)
                return false; // If digit is 0 → return false
            num /= 10;        // Remove the last digit
        }
        return true; // No zero found → valid number
    }

public:
    vector<int> getNoZeroIntegers(int n)
    {
        int a = 1;     // Start with 1 as the first number
        int b = n - 1; // Second number so that a + b = n

        // Keep checking until both numbers have no zero digits
        while (!isNonZero(a) || !isNonZero(b))
        {
            a++; // Try next possible 'a'
            b--; // Adjust 'b' so sum remains n
        }

        // Return the valid pair
        return {a, b};
    }
};