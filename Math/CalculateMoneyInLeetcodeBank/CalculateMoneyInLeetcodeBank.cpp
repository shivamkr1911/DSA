#include <bits/stdc++.h>
using namespace std;

// ================= Cleaner Version - Full weeks + Remaining days =================
class Solution1
{
public:
    int totalMoney(int n)
    {
        int weeks = n / 7; // Count of complete weeks
        int days = n % 7;  // Remaining days after full weeks
        int monStart = 1;  // Monday's starting deposit for first week
        int total = 0;     // Total money saved

        // Calculate total for complete weeks
        for (int i = 0; i < weeks; ++i)
        {
            total += (7 * monStart) + 21; // Sum of week = 7*start + (0+1+2+...+6)=21
            monStart++;                   // Next week starts with +1 more than previous
        }

        // Add remaining days (if any)
        for (int i = 0; i < days; ++i)
        {
            total += monStart + i; // Add daily increasing amount
        }

        return total; // Return total savings
    }
};

// ================= Day-by-day Simulation =================
class Solution2
{
public:
    int totalMoney(int n)
    {
        int bal = 1;    // Total balance
        int cnt = 1;    // Current day's deposit
        int monBal = 1; // Monday's base deposit

        // Simulate each day
        for (int i = 1; i < n; i++)
        {
            if (i % 7 == 0)
            {                  // New week starts
                monBal++;      // Monday deposit increases
                bal += monBal; // Add Monday's deposit
                cnt = monBal;  // Reset count for the new week
            }
            else
            {
                cnt++;      // Daily deposit increases by 1
                bal += cnt; // Add to total balance
            }
        }
        return bal; // Return total money saved
    }
};