#include <bits/stdc++.h>
using namespace std;

// ================= Optimal Solution =================
class Solution1
{
public:
    vector<int> nextSmallerEle(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> st;      // Monotonic stack to keep track of smaller elements
        vector<int> ans(n); // Stores next smaller element for each index

        // Traverse from right to left to find the next smaller element
        for (int i = n - 1; i >= 0; --i)
        {
            // Pop all elements greater than or equal to the current element
            // because they cannot be the "next smaller" for this position
            while (!st.empty() && arr[i] <= st.top())
                st.pop();

            // If stack is empty, no smaller element exists to the right
            // else top of stack is the next smaller element
            ans[i] = st.empty() ? -1 : st.top();

            // Push current element for future comparisons
            st.push(arr[i]);
        }

        return ans;
    }
};

// ================= Brute Force Solution =================

class Solution2
{
public:
    vector<int> nextSmallerEle(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, -1); // Default value -1 if no smaller element found

        // For each element, check elements to its right
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                // First smaller element found to the right
                if (arr[i] > arr[j])
                {
                    ans[i] = arr[j];
                    break;
                }
            }
        }

        return ans;
    }
};
