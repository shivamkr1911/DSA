#include <bits/stdc++.h>
using namespace std;

// Solution2 - Optimized Solution
class Solution
{
private:
    void solve(int i, int j, vector<vector<int>> &maze, vector<string> &res, vector<vector<int>> &vis, string move, vector<int> &di, vector<int> &dj, int n)
    {
        // Base case: reached bottom-right cell
        if (i == n - 1 && j == n - 1)
        {
            res.push_back(move);
            return;
        }

        string dir = "DLRU"; // Directions in order: Down, Left, Right, Up
        for (int ind = 0; ind < 4; ind++)
        {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];
            // Check if next cell is valid, not visited, and open (==1)
            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && vis[nexti][nextj] != 1 && maze[nexti][nextj] == 1)
            {
                vis[i][j] = 1;                                                   // Mark current as visited
                solve(nexti, nextj, maze, res, vis, move + dir[ind], di, dj, n); // Recurse
                vis[i][j] = 0;                                                   // Backtrack
            }
        }
    }

public:
    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        int n = maze.size();
        vector<string> res;
        vector<vector<int>> vis(n, vector<int>(n, 0)); // Visited matrix
        string move = "";
        // Arrays for row and column movements: D, L, R, U
        vector<int> di = {1, 0, 0, -1};
        vector<int> dj = {0, -1, 1, 0};
        // Start only if the starting cell is open
        if (maze[0][0] == 1)
            solve(0, 0, maze, res, vis, move, di, dj, n);
        return res;
    }
};

// Solution1 - Not Optimized
/*
class Solution {
  private:
    void solve(int row, int col, vector<string> &res, vector<vector<int>> &vis, string move, vector<vector<int>> &maze, int n) {
        // Base case: reached bottom-right cell
        if (row == n - 1 && col == n - 1) {
            res.push_back(move);
            return;
        }

        // Move Down
        if (row + 1 < n && vis[row + 1][col] != 1 && maze[row + 1][col] == 1) {
            vis[row][col] = 1;
            solve (row + 1, col, res, vis, move + 'D', maze, n);
            vis[row][col] = 0; // Backtrack
        }
        // Move Left
        if (col - 1 >= 0 && vis[row][col - 1] != 1 && maze[row][col - 1] == 1) {
            vis[row][col] = 1;
            solve (row, col - 1, res, vis, move + 'L', maze, n);
            vis[row][col] = 0;
        }
        // Move Right
        if (col + 1 < n && vis[row][col + 1] != 1 && maze[row][col + 1] == 1) {
            vis[row][col] = 1;
            solve (row, col + 1, res, vis, move + 'R', maze, n);
            vis[row][col] = 0;
        }
        // Move Up
        if (row - 1 >= 0 && vis[row - 1][col] != 1 && maze[row - 1][col] == 1) {
            vis[row][col] = 1;
            solve (row - 1, col, res, vis, move + 'U', maze, n);
            vis[row][col] = 0;
        }
    }

  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> res;
        vector<vector<int>> vis(n, vector<int> (n, 0)); // Visited matrix
        string move = "";
        // Start only if the starting cell is open
        if (maze[0][0] == 1) solve(0, 0, res, vis, move, maze, n);
        return res;
    }
};
*/
