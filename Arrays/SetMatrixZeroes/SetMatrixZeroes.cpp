#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        // row = [..][0] = [i][0]
        // col = [0][..] = [0][j]

        int col0 = 1; // Flag for first column

        // Mark rows and columns that need to be zeroed
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0; // Mark row
                    if (j != 0)
                        matrix[0][j] = 0; // Mark column
                    else
                        col0 = 0; // Mark first column
                }
            }
        }

        // Set zeroes based on marks (excluding first row and col)
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] != 0)
                {
                    if (matrix[0][j] == 0 || matrix[i][0] == 0)
                        matrix[i][j] = 0;
                }
            }
        }

        // Set first row to zero if needed
        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < m; j++)
                matrix[0][j] = 0;
        }

        // Set first column to zero if needed
        if (col0 == 0)
        {
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
        }
    }
};
