#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to compute the largest rectangle in a histogram (classic stack-based approach)
    int larRec(vector<int> &arr)
    {
        int n = arr.size();
        int maxi = 0;
        stack<int> st;

        for (int i = 0; i < n; ++i)
        {
            // Pop while current bar is smaller/equal → found NSE (Next Smaller Element)
            while (!st.empty() && arr[i] <= arr[st.top()])
            {
                int nse = i;                // next smaller element index
                int height = arr[st.top()]; // height of bar to evaluate
                st.pop();
                int pse = st.empty() ? -1 : st.top();       // previous smaller element index
                maxi = max(maxi, height * (nse - pse - 1)); // width = nse - pse - 1
            }
            st.push(i);
        }

        // Remaining bars in stack have NSE = n
        while (!st.empty())
        {
            int height = arr[st.top()];
            st.pop();
            int nse = n;                          // no smaller element to the right
            int pse = st.empty() ? -1 : st.top(); // previous smaller
            maxi = max(maxi, height * (nse - pse - 1));
        }

        return maxi;
    }

    // Preprocess matrix to convert each column into "height of consecutive 1s up to that row"
    vector<vector<int>> preSum(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> pre(n, vector<int>(m, 0));

        for (int j = 0; j < m; ++j)
        {
            int sum = 0;
            for (int i = 0; i < n; ++i)
            {
                sum += matrix[i][j] - '0'; // add 1 if '1'
                if (matrix[i][j] == '0')
                    sum = 0;     // reset on '0'
                pre[i][j] = sum; // height of consecutive 1s
            }
        }
        return pre;
    }

public:
    // Main function to compute maximal rectangle in a binary matrix
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        vector<vector<int>> preSumMat = preSum(matrix); // convert to histogram-like heights
        int n = preSumMat.size();
        int maxi = 0;

        // For each row, treat it as a histogram and compute max rectangle
        for (int i = 0; i < n; ++i)
        {
            maxi = max(maxi, larRec(preSumMat[i]));
        }

        return maxi;
    }
};
