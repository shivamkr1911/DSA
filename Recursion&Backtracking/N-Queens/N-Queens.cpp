#include <bits/stdc++.h>
using namespace std;

// Solution2 - Optimized Solution
class Solution
{
private:
    // Recursive function to place queens column by column
    void solve(int col, vector<string> &board, int n, vector<vector<string>> &res,
               vector<int> &leftRow, vector<int> &lowDiag, vector<int> &upDiag)
    {
        // Base case: all queens placed
        if (col == n)
        {
            res.push_back(board);
            return;
        }

        // Try placing queen in each row of the current column
        for (int row = 0; row < n; row++)
        {
            // Check if placing queen here is safe using helper arrays
            if (leftRow[row] == 0 && lowDiag[row + col] == 0 && upDiag[n - 1 + col - row] == 0)
            {
                // Place queen
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowDiag[row + col] = 1;
                upDiag[n - 1 + col - row] = 1;

                // Recur for next column
                solve(col + 1, board, n, res, leftRow, lowDiag, upDiag);

                // Backtrack: remove queen and reset state
                board[row][col] = '.';
                leftRow[row] = 0;
                lowDiag[row + col] = 0;
                upDiag[n - 1 + col - row] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.')); // Chessboard initialized with '.'
        vector<int> leftRow(n, 0);               // Track queens in each row
        vector<int> upDiag(2 * n - 1, 0);        // Track queens in upper diagonals
        vector<int> lowDiag(2 * n - 1, 0);       // Track queens in lower diagonals

        // Start from column 0
        solve(0, board, n, res, leftRow, lowDiag, upDiag);
        return res;
    }
};
