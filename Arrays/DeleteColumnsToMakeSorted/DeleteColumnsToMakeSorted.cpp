#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs.size();    // number of strings (rows)
        int m = strs[0].size(); // length of each string (columns)
        int cnt = 0;            // count of columns to delete

        // Check each column independently
        for (int i = 0; i < m; ++i)
        {

            // Compare characters row-wise in the current column
            for (int j = 0; j < n - 1; ++j)
            {
                if (strs[j][i] > strs[j + 1][i])
                {
                    cnt++; // column is not sorted → delete it
                    break; // no need to check further rows
                }
            }
        }

        return cnt;
    }
};
