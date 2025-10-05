#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution (Diagonal Traversal) ===============
class Solution1
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int m = mat.size();    // number of rows
        int n = mat[0].size(); // number of columns
        vector<int> res;       // result array
        int row = 0, col = 0;  // starting indices
        bool up = true;        // direction flag: true -> up-right, false -> down-left

        while (res.size() < m * n)
        {
            res.push_back(mat[row][col]); // add current element

            if (up) // moving up-right
            {
                if (col == n - 1)
                {               // reached last column
                    row++;      // move down
                    up = false; // change direction
                }
                else if (row == 0)
                {               // reached first row
                    col++;      // move right
                    up = false; // change direction
                }
                else
                { // normal move up-right
                    row--;
                    col++;
                }
            }
            else // moving down-left
            {
                if (row == m - 1)
                {              // reached last row
                    col++;     // move right
                    up = true; // change direction
                }
                else if (col == 0)
                {              // reached first column
                    row++;     // move down
                    up = true; // change direction
                }
                else
                { // normal move down-left
                    row++;
                    col--;
                }
            }
        }
        return res; // return diagonal traversal
    }
};
