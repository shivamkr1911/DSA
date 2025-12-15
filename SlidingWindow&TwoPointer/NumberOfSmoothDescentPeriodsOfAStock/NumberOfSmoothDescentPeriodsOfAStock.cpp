#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        long long ans = 1; // at least one descent period for the first element
        int len = 1;       // length of current descending sequence

        for (int i = 1; i < prices.size(); ++i)
        {

            // If current price is exactly 1 less than previous → extend descent
            if (prices[i - 1] - prices[i] == 1)
                len++;
            else
                len = 1; // reset if descent breaks

            // Add number of descent subarrays ending at index i
            ans += len;
        }

        return ans; // total number of smooth descent periods
    }
};
