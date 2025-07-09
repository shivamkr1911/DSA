#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Generate a single row of Pascal's Triangle
    vector<int> generateRow(int row)
    {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1); // First element is always 1

        for (int col = 1; col < row; col++)
        {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans); // Add next element
        }

        return ansRow;
    }

    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;

        // Generate each row
        for (int i = 1; i <= numRows; i++)
        {
            ans.push_back(generateRow(i));
        }

        return ans;
    }
};
