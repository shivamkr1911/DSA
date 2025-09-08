#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function to check if a number has no zero digit
    bool isNonZero(int num)
    {
        while (num > 0)
        {
            if (num % 10 == 0)
                return false; // If any digit is 0 → invalid
            num /= 10;        // Remove last digit
        }
        return true; // All digits are non-zero
    }

public:
    vector<int> getNoZeroIntegers(int n)
    {
        int first = 1;      // Start with the smallest possible number
        int second = n - 1; // Complementary number so that first + second = n

        // Iterate until first ≤ second
        while (first <= second)
        {
            // If both numbers have no zero digits → return the pair
            if (isNonZero(first) && isNonZero(second))
                return {first, second};

            // Otherwise, move to the next candidate
            first++;
            second = n - first; // Update second accordingly
        }

        // Fallback (though problem guarantees a valid answer exists)
        return {-1, -1};
    }
};
