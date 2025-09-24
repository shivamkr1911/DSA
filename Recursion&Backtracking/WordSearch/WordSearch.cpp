#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Recursive function to search for the word starting from board[row][col]
    bool searchNext(vector<vector<char>> &board, string &word, int row, int col, int index, int m, int n)
    {
        // Base case: if all characters are matched
        if (index == word.size())
            return true;

        // Boundary check + mismatch check + visited check
        if (row < 0 || col < 0 || row == m || col == n || board[row][col] != word[index] || board[row][col] == '!')
            return false;

        // Store current cell and mark it as visited
        char c = board[row][col];
        board[row][col] = '!';

        // Explore all 4 possible directions (top, right, bottom, left)
        bool top = searchNext(board, word, row - 1, col, index + 1, m, n);
        bool right = searchNext(board, word, row, col + 1, index + 1, m, n);
        bool bottom = searchNext(board, word, row + 1, col, index + 1, m, n);
        bool left = searchNext(board, word, row, col - 1, index + 1, m, n);

        // Backtrack: restore the original character
        board[row][col] = c;

        // Return true if any direction leads to a valid solution
        return top || right || bottom || left;
    }

public:
    // Main function to check if word exists in the board
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();    // Number of rows
        int n = board[0].size(); // Number of columns

        // Start DFS from every cell that matches the first character
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == word[0]) // Potential starting point
                    if (searchNext(board, word, i, j, 0, m, n))
                        return true;
            }
        }
        return false; // If no path matches the word
    }
};
