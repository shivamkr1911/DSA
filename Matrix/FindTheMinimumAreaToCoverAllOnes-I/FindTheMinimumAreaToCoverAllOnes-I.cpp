#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumArea(vector<vector<int>> &grid)
    {
        // Initialize min/max row and col boundaries
        int minRow = grid.size(), maxRow = -1;
        int minCol = grid[0].size(), maxCol = -1;

        // Traverse the grid
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 1)
                {                            // Found a 1
                    minRow = min(minRow, i); // Update min row
                    maxRow = max(maxRow, i); // Update max row
                    minCol = min(minCol, j); // Update min col
                    maxCol = max(maxCol, j); // Update max col
                }
            }
        }

        // Return area of rectangle covering all 1s
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};
