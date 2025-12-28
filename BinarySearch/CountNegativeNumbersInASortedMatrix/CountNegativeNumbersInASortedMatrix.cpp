#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution (Top-Right Traversal) ===============
class Solution1
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int i = 0, j = n - 1; // start from top-right corner
        int cnt = 0;

        while (i < m && j >= 0)
        {
            // If current element is negative,
            // all elements below it in this column are also negative
            if (grid[i][j] < 0)
            {
                cnt += m - i; // count negatives in this column
                j--;          // move left
            }
            else
            {
                i++; // move down if value is non-negative
            }
        }

        return cnt;
    }
};

// =============== Better Solution (Binary Search on Each Row) ===============
class Solution2
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        // For each row, find the first negative element
        for (int i = 0; i < m; ++i)
        {
            int low = 0, high = n - 1;
            int firstNeg = n;

            while (low <= high)
            {
                int mid = (low + high) / 2;

                if (grid[i][mid] < 0)
                {
                    firstNeg = mid;
                    high = mid - 1; // search left half
                }
                else
                {
                    low = mid + 1; // search right half
                }
            }

            // All elements after firstNeg are negative
            cnt += n - firstNeg;
        }

        return cnt;
    }
};

// =============== Brute Force ===============
class Solution3
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        // Check every element in the matrix
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] < 0)
                    cnt++;
            }
        }

        return cnt;
    }
};
