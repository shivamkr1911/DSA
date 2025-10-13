#include <bits/stdc++.h>
using namespace std;

// ================= Optimal Solution =================
class Solution1
{
public:
    vector<int> prevSmaller(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, -1); // store previous smaller elements, default -1
        stack<int> st;          // stack to keep potential previous smaller elements

        for (int i = 0; i < n; ++i)
        {
            // Pop elements from stack that are >= current element
            while (!st.empty() && arr[i] <= st.top())
                st.pop();

            // If stack is empty, no smaller element exists, else top is previous smaller
            ans[i] = st.empty() ? -1 : st.top();

            // Push current element to stack as potential previous smaller for next elements
            st.push(arr[i]);
        }

        return ans; // return the array of previous smaller elements
    }
};

// ================= Brute Force Solution =================

class Solution2
{
public:
    vector<int> prevSmaller(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, -1); // initialize result with -1

        // For each element starting from second element
        for (int i = n - 1; i >= 1; i--)
        {
            // Check all previous elements
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[j] < arr[i])
                { // found previous smaller
                    ans[i] = arr[j];
                    break; // stop at first smaller
                }
            }
        }

        return ans; // return the result array
    }
};
