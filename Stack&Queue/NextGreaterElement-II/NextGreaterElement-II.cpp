#include <bits/stdc++.h>
using namespace std;

// ================= Optimal Solution =================
class Solution1
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;      // Monotonic stack to keep track of potential next greater elements
        vector<int> ans(n); // Stores next greater elements for each index

        // Traverse the array twice (circular array → simulate two rounds)
        for (int i = 2 * n - 1; i >= 0; --i)
        {
            int idx = i % n; // Wrap index around using modulo to simulate circular traversal

            // Pop elements smaller or equal to current — they can't be next greater
            while (!st.empty() && nums[idx] >= st.top())
                st.pop();

            // For the first n iterations (original array positions), store result
            if (i < n)
            {
                ans[i] = st.empty() ? -1 : st.top(); // -1 if none greater found
            }

            // Push current element for future comparisons (for earlier elements)
            st.push(nums[idx]);
        }

        return ans; // Return final array of next greater elements
    }
};

// ================= Brute Force Solution =================

class Solution2
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;

        // For each element, check next greater in circular manner
        for (int i = 0; i < n; ++i)
        {
            bool found = false;

            // Look ahead up to 2n - 1 to simulate circular array
            for (int j = i + 1; j < 2 * n; ++j)
            {
                int idx = j % n; // Wrap index using modulo
                if (nums[i] < nums[idx])
                {
                    ans.push_back(nums[idx]); // Found next greater
                    found = true;
                    break;
                }
            }

            // If no greater element found in circular scan
            if (!found)
                ans.push_back(-1);
        }

        return ans;
    }
};
