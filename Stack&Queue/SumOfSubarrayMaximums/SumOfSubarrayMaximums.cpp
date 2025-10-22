#include <bits/stdc++.h>
using namespace std;

// ================= Optimal Solution =================
class Solution1
{
private:
    // Find index of Next Greater Element (NGE) for each element
    vector<int> findNGE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nge(n); // Stores index of next greater element
        stack<int> st;      // Stack to keep track of indices

        for (int i = n - 1; i >= 0; --i)
        {
            // Pop indices whose elements are smaller or equal to current
            while (!st.empty() && arr[i] >= arr[st.top()])
                st.pop();
            // If stack empty, no NGE exists, else top of stack is NGE index
            nge[i] = st.empty() ? n : st.top();
            st.push(i); // Push current index onto stack
        }
        return nge;
    }

    // Find index of Previous Greater or Equal Element (PGEE) for each element
    vector<int> findPGEE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pgee(n); // Stores index of previous greater or equal element
        stack<int> st;       // Stack to keep track of indices

        for (int i = 0; i < n; ++i)
        {
            // Pop indices whose elements are smaller than current
            while (!st.empty() && arr[i] > arr[st.top()])
                st.pop();
            // If stack empty, no PGEE exists, else top of stack is PGEE index
            pgee[i] = st.empty() ? -1 : st.top();
            st.push(i); // Push current index onto stack
        }
        return pgee;
    }

public:
    // Calculate sum of maximums of all subarrays
    int sumOfMax(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nge = findNGE(arr);   // Next Greater Element indices
        vector<int> pgee = findPGEE(arr); // Previous Greater or Equal Element indices
        int sum = 0;

        for (int i = 0; i < n; ++i)
        {
            // Count of subarrays where arr[i] is maximum
            int left = i - pgee[i];  // Elements to the left including i
            int right = nge[i] - i;  // Elements to the right including i
            int freq = left * right; // Total subarrays containing arr[i] as max
            int val = freq * arr[i]; // Contribution of arr[i] to sum
            sum += val;              // Add to total sum
        }
        return sum;
    }
};

// ================= Brute Force Solution =================

class Solution2
{
public:
    int sumOfMax(vector<int> &arr)
    {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            int maxi = arr[i]; // Track maximum in current subarray
            for (int j = i; j < n; ++j)
            {
                maxi = max(maxi, arr[j]); // Update maximum
                sum += maxi;              // Add maximum to sum
            }
        }
        return sum;
    }
};
