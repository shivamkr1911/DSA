#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int n = customers.size();

        int totalY = 0;
        // Count total 'Y' (customers arriving after opening)
        for (char c : customers)
            totalY += (c == 'Y');

        // If no customers at all, best to close immediately
        if (totalY == 0)
            return 0;

        int penalty = totalY;    // initial penalty if shop closes at time 0
        int minPenalty = totalY; // minimum penalty observed
        int totalN = 0;          // count of 'N' before current hour
        int ans = 0;             // best closing hour

        // Try closing after each hour
        for (int i = 0; i < n; ++i)
        {

            // Update penalties based on current customer
            if (customers[i] == 'N')
                totalN++; // penalty for staying open with no customers
            else
                totalY--; // fewer customers left after closing

            // Total penalty = customers missed after closing + idle open hours
            penalty = totalY + totalN;

            // Update minimum penalty and closing time
            if (penalty < minPenalty)
            {
                minPenalty = penalty;
                ans = i + 1; // close after hour i
            }
        }

        return ans;
    }
};
