#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {

        // Create a grid where:
        // ' ' = empty cell
        // 'g' = guard
        // 'w' = wall
        // 's' = cell secured/guarded by a guard
        vector<vector<char>> grid(m, vector<char>(n, ' '));

        // Mark all guards
        for (auto &g : guards)
            grid[g[0]][g[1]] = 'g';

        // Mark all walls
        for (auto &w : walls)
            grid[w[0]][w[1]] = 'w';

        // For each guard, mark the cells they can see in 4 directions
        for (auto &g : guards)
        {

            int r = g[0], c = g[1];

            // Guard looks UP
            for (int i = r - 1; i >= 0; --i)
            {
                if (grid[i][c] == 'g' || grid[i][c] == 'w')
                    break;        // Blocked
                grid[i][c] = 's'; // Mark as seen
            }

            // Guard looks DOWN
            for (int i = r + 1; i < m; ++i)
            {
                if (grid[i][c] == 'g' || grid[i][c] == 'w')
                    break;
                grid[i][c] = 's';
            }

            // Guard looks LEFT
            for (int i = c - 1; i >= 0; --i)
            {
                if (grid[r][i] == 'g' || grid[r][i] == 'w')
                    break;
                grid[r][i] = 's';
            }

            // Guard looks RIGHT
            for (int i = c + 1; i < n; ++i)
            {
                if (grid[r][i] == 'g' || grid[r][i] == 'w')
                    break;
                grid[r][i] = 's';
            }
        }

        // Count all unguarded (empty) cells
        int cnt = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == ' ')
                    cnt++;
            }
        }

        return cnt;
    }
};
