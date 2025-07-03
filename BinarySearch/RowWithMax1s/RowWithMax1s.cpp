#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Find index of first element >= num
    int lowerBound(vector<int> arr, int m, int num)
    {
        int low = 0, high = m - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] >= num)
                high = mid - 1; // Search left half
            else
                low = mid + 1; // Search right half
        }
        return low; // Position of first >= num
    }

public:
    int rowWithMax1s(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int maxCnt = 0; // Max number of 1s so far
        int idx = -1;   // Row index with max 1s

        for (int i = 0; i < n; ++i)
        {
            int cnt = m - lowerBound(mat[i], m, 1); // Count 1s in row
            if (cnt > maxCnt)
            {
                maxCnt = cnt; // Update max
                idx = i;      // Update row index
            }
        }
        return idx;
    }
};
