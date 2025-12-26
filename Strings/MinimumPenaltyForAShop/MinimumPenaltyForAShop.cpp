#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int curPenalty = 0;

        // Initial penalty if shop closes at hour 0 (all 'Y' are missed)
        for (char c : customers)
        {
            if (c == 'Y')
            {
                curPenalty++;
            }
        }

        int minPenalty = curPenalty; // minimum penalty observed so far
        int ans = 0;                 // best closing hour

        // Try closing after each hour (moving closing time from i to i+1)
        for (int i = 0; i < customers.size(); ++i)
        {

            // If current char is 'Y', we are now OPEN for it, so penalty decreases
            if (customers[i] == 'Y')
            {
                curPenalty--;
            }
            // If current char is 'N', we are now OPEN for it, so penalty increases
            else
            {
                curPenalty++;
            }

            // Update answer if better penalty found
            if (curPenalty < minPenalty)
            {
                minPenalty = curPenalty;
                ans = i + 1; // close after hour i
            }
        }

        return ans;
    }
};