#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();

        // Treat the 2D matrix as a sorted 1D array (virtual indexing)
        int low = 0, high = m * n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            // Convert 1D index back to 2D (row, col)
            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target)
                return true; // target found

            else if (matrix[row][col] < target)
                low = mid + 1; // search in right half

            else
                high = mid - 1; // search in left half
        }

        return false; // target not found
    }
};
