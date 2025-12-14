#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    static const int MOD = 1e9 + 7; // modulo for large answers

public:
    int numberOfWays(string corridor)
    {

        // Count total number of seats
        int totalSeats = 0;
        for (char c : corridor)
        {
            if (c == 'S')
                totalSeats++;
        }

        // Invalid cases: no seats or odd number of seats
        if (totalSeats == 0 || totalSeats % 2 != 0)
            return 0;

        int plants = 0;    // plants between seat pairs
        int seats = 0;     // seats encountered so far
        long long ans = 1; // total number of ways

        for (char c : corridor)
        {
            if (c == 'S')
            {
                seats++;

                // Every new pair after the first contributes (plants + 1) choices
                if (seats > 2 && seats % 2 != 0)
                {
                    ans = (ans * (plants + 1)) % MOD;
                    plants = 0; // reset for next segment
                }
            }
            else
            {
                // Count plants only between completed seat pairs
                if (seats % 2 == 0 && seats > 0)
                    plants++;
            }
        }

        return ans;
    }
};
