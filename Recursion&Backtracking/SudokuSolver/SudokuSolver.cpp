#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Recursive backtracking function to solve the Sudoku
    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                // Find an empty cell (denoted by '.')
                if (board[i][j] == '.')
                {

                    // Try placing digits '1' to '9'
                    for (char c = '1'; c <= '9'; ++c)
                    {
                        if (isValid(board, i, j, c))
                        {
                            // Place digit if it's valid
                            board[i][j] = c;

                            // Recur to solve the rest of the board
                            if (solve(board) == true)
                                return true;

                            // If placing `c` didn't work, backtrack
                            board[i][j] = '.';
                        }
                    }

                    // If no valid digit can be placed, return false
                    return false;
                }
            }
        }
        // If no empty cell is left, Sudoku is solved
        return true;
    }

    // Check if placing `c` at board[row][col] is valid
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            // Check same column
            if (board[i][col] == c)
                return false;
            // Check same row
            if (board[row][i] == c)
                return false;
            // Check 3x3 subgrid
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }

public:
    // Main function to solve Sudoku puzzle
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};
