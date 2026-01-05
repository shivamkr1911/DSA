#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long total = 0;  // sum of absolute values
        int minAbs = INT_MAX; // smallest absolute value in matrix
        int negCnt = 0;       // count of negative elements

        // Traverse matrix to gather required information
        for (auto &row : matrix)
        {
            for (int x : row)
            {
                if (x < 0)
                    negCnt++; // count negatives

                total += abs(x);              // add absolute value
                minAbs = min(minAbs, abs(x)); // track minimum absolute value
            }
        }

        // If negatives are even, all can be made positive
        if (negCnt % 2 == 0)
            return total;

        // Otherwise, one element must remain negative
        return total - 2LL * minAbs;
    }
};
