#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Find index of first element > x
    int upperBound(vector<int> &arr, int x, int n)
    {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] > x)
            {
                ans = mid; // Possible upper bound
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

    // Count elements <= x in matrix
    int countSmallEqual(vector<vector<int>> &mat, int m, int n, int x)
    {
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            cnt += upperBound(mat[i], x, n);
        }
        return cnt;
    }

public:
    int median(vector<vector<int>> &mat)
    {
        int low = INT_MAX, high = INT_MIN;
        int m = mat.size();
        int n = mat[0].size();

        // Find min and max in matrix
        for (int i = 0; i < m; i++)
        {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][n - 1]);
        }

        int req = (n * m) / 2; // Required position for median

        // Binary search for median
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int smallEqual = countSmallEqual(mat, m, n, mid);

            if (smallEqual <= req)
                low = mid + 1; // Median is greater
            else
                high = mid - 1; // Median is smaller
        }

        return low; // Median value
    }
};
