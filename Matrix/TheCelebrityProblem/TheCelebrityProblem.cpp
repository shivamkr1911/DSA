#include <bits/stdc++.h>
using namespace std;

// ================= Optimal Solution =================
class Solution1
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int top = 0, down = n - 1;

        // Step 1: Find potential celebrity using elimination
        while (top < down)
        {
            if (mat[top][down] == 1)
                top++; // top knows down → top cannot be celebrity
            else if (mat[down][top] == 1)
                down--; // down knows top → down cannot be celebrity
            else
            {
                top++; // both don't know each other → eliminate both
                down--;
            }
        }

        if (top > down)
            return -1; // no potential celebrity

        // Step 2: Verify the potential celebrity
        for (int i = 0; i < n; ++i)
        {
            if (i == top)
                continue; // skip self-check

            // Celebrity must not know anyone, and everyone must know them
            if (mat[top][i] == 1 || mat[i][top] == 0)
                return -1; // fails condition
        }

        return top; // valid celebrity found
    }
};

// ================= Brute Force Solution =================
class Solution2
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();
        vector<int> knowMe(n, 0); // how many know me
        vector<int> iKnow(n, 0);  // how many I know

        // Count in and out degrees for each person
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j] == 1)
                {
                    iKnow[i]++;  // i knows j
                    knowMe[j]++; // j is known by i
                }
            }
        }

        // Celebrity → known by everyone else, knows no one
        for (int i = 0; i < n; ++i)
        {
            if (knowMe[i] == n - 1 && iKnow[i] == 0)
                return i;
        }

        return -1; // no celebrity found
    }
};
