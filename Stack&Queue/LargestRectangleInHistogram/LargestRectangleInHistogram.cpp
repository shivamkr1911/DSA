#include <bits/stdc++.h>
using namespace std;

// ================= Optimal Solution =================
class Solution1
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st; // stores indices of increasing height bars

        for (int i = 0; i < n; ++i)
        {

            // Pop while current bar is smaller → found NSE for popped bars
            while (!st.empty() && heights[i] <= heights[st.top()])
            {

                int idx = st.top(); // index of bar being processed
                st.pop();

                int nse = i;                          // next smaller element index
                int pse = st.empty() ? -1 : st.top(); // previous smaller element index

                // Calculate width = (nse - pse - 1)
                maxArea = max(maxArea, heights[idx] * (nse - pse - 1));
            }

            st.push(i); // push current index
        }

        // Process remaining bars (their NSE = n)
        while (!st.empty())
        {
            int idx = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, heights[idx] * (nse - pse - 1));
        }

        return maxArea;
    }
};

// ================= Brute Force Solution =================
class Solution2
{
private:
    // Find Previous Smaller Element for each bar
    vector<int> findPSE(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && heights[i] <= heights[st.top()])
                st.pop();

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    // Find Next Smaller Element for each bar
    vector<int> findNSE(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && heights[i] <= heights[st.top()])
                st.pop();

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> pse = findPSE(heights);
        vector<int> nse = findNSE(heights);

        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i)
        {
            int height = heights[i];

            // Width between previous smaller and next smaller
            int width = (nse[i] - pse[i] - 1);

            maxArea = max(maxArea, height * width);
        }
        return maxArea;
    }
};
