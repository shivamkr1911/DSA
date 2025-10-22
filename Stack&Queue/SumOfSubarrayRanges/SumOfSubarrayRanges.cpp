#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Find Previous Smaller or Equal Element Index for each element
    vector<int> findPSEE(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> psee(n); // Stores previous smaller element indices
        stack<int> st;       // Stack to track indices

        for (int i = 0; i < n; ++i)
        {
            // Pop indices whose elements are strictly greater than current element
            while (!st.empty() && nums[i] < nums[st.top()])
                st.pop();
            // If stack empty, no previous smaller exists
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    // Find Next Smaller Element Index for each element
    vector<int> findNSE(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nse(n); // Stores next smaller element indices
        stack<int> st;      // Stack to track indices

        for (int i = n - 1; i >= 0; --i)
        {
            // Pop indices whose elements are greater than or equal to current element
            while (!st.empty() && nums[i] <= nums[st.top()])
                st.pop();
            // If stack empty, no next smaller exists
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    // Compute sum of minimums of all subarrays
    long long findSumOfSubarrayMinimums(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> psee = findPSEE(nums); // Previous smaller indices
        vector<int> nse = findNSE(nums);   // Next smaller indices
        long long sum = 0;

        for (int i = 0; i < n; ++i)
        {
            int left = i - psee[i];                       // Number of valid starting points for subarrays ending at i
            int right = nse[i] - i;                       // Number of valid ending points for subarrays starting at i
            long long val = 1LL * nums[i] * left * right; // Contribution of nums[i] to total sum
            sum += val;
        }
        return sum;
    }

    // Find Previous Greater or Equal Element Index for each element
    vector<int> findPGEE(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pgee(n);
        stack<int> st;

        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && nums[i] > nums[st.top()])
                st.pop();
            pgee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pgee;
    }

    // Find Next Greater Element Index for each element
    vector<int> findNGE(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && nums[i] >= nums[st.top()])
                st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    // Compute sum of maximums of all subarrays
    long long findSumOfSubarrayMaximums(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pgee = findPGEE(nums); // Previous greater indices
        vector<int> nge = findNGE(nums);   // Next greater indices
        long long sum = 0;

        for (int i = 0; i < n; ++i)
        {
            int left = i - pgee[i];                       // Number of valid starting points for subarrays ending at i
            int right = nge[i] - i;                       // Number of valid ending points for subarrays starting at i
            long long val = 1LL * nums[i] * left * right; // Contribution of nums[i] to total sum
            sum += val;
        }
        return sum;
    }

public:
    // Compute the sum of ranges of all subarrays
    long long subArrayRanges(vector<int> &nums)
    {
        long long sumSubMin = findSumOfSubarrayMinimums(nums); // Sum of subarray minimums
        long long sumSubMax = findSumOfSubarrayMaximums(nums); // Sum of subarray maximums
        return sumSubMax - sumSubMin;                          // Range = max - min
    }
};
