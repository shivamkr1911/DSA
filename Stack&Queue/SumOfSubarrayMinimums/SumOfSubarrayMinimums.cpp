#include <bits/stdc++.h>
using namespace std;

// ================= Optimal Solution =================
class Solution1
{
private:
    // Function to find Next Smaller Element (NSE) index for each element
    vector<int> findNSE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n); // Stores index of next smaller element
        stack<int> st;      // Stack stores indices

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            // Pop elements greater than or equal to current
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            // If stack not empty, top is NSE index; else no NSE → n
            ans[i] = !st.empty() ? st.top() : n;

            // Push current index
            st.push(i);
        }
        return ans;
    }

    // Function to find Previous Smaller or Equal Element (PSEE) index for each element
    vector<int> findPSEE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n); // Stores index of previous smaller or equal element
        stack<int> st;      // Stack stores indices

        // Traverse from left to right
        for (int i = 0; i < n; i++)
        {
            // Pop elements strictly greater than current
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }

            // If stack not empty, top is PSEE index; else no PSEE → -1
            ans[i] = !st.empty() ? st.top() : -1;

            // Push current index
            st.push(i);
        }
        return ans;
    }

public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        int mod = 1e9 + 7;

        // Get indices of Next Smaller and Previous Smaller or Equal Elements
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        long long sum = 0;

        // Calculate contribution of each element as subarray minimum
        for (int i = 0; i < n; i++)
        {
            int left = i - psee[i]; // No. of choices on left including i
            int right = nse[i] - i; // No. of choices on right including i

            long long freq = left * right * 1LL; // Total subarrays where arr[i] is minimum
            int val = (freq * arr[i]) % mod;     // Contribution of arr[i]
            sum = (sum + val) % mod;             // Add to final sum
        }
        return sum;
    }
};

// ================= Brute Force Solution =================

class Solution2
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        int mod = 1e9 + 7;
        int cnt = 0;

        // Generate all subarrays
        for (int i = 0; i < n; ++i)
        {
            int mini = arr[i]; // Track minimum in current subarray

            for (int j = i; j < n; ++j)
            {
                mini = min(mini, arr[j]); // Update minimum
                cnt = (cnt + mini) % mod; // Add to total sum
            }
        }
        return cnt;
    }
};
