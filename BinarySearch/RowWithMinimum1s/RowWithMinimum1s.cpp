#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minRow(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int minCnt = INT_MAX; // Minimum 1s so far
        int idx = -1;         // Row index with min 1s

        for (int i = 0; i < n; ++i)
        {
            int cnt = 0;
            for (int j = 0; j < m; ++j)
            {
                if (mat[i][j] == 1)
                    cnt++; // Count 1s in row
            }
            if (cnt < minCnt)
            {
                minCnt = cnt; // Update min
                idx = i;      // Update row index
            }
        }
        return idx + 1; // Return 1-based index
    }
};
