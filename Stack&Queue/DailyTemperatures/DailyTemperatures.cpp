#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function to compute Next Greater Element distances
    vector<int> findNGE(vector<int> &temp)
    {

        int n = temp.size();
        vector<int> nge(n); // nge[i] will store days until a warmer temperature
        stack<int> st;      // Monotonic stack storing indices

        // Traverse from right to left
        for (int i = n - 1; i >= 0; --i)
        {

            // Pop all smaller or equal temperatures
            while (!st.empty() && temp[i] >= temp[st.top()])
            {
                st.pop();
            }

            // If stack empty → no warmer day ahead
            // Otherwise → top index - current index gives distance
            nge[i] = st.empty() ? 0 : st.top() - i;

            // Push current index to maintain decreasing stack
            st.push(i);
        }

        return nge;
    }

public:
    // Main function returning number of days to wait for warmer temperature
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> nge = findNGE(temperatures);
        return nge;
    }
};
