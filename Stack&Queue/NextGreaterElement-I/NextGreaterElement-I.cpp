#include <bits/stdc++.h>
using namespace std;

// ================= Optimal Solution =================
class Solution1
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int, int> mp; // Stores each element of nums2 and its next greater element
        stack<int> st;              // Monotonic stack to find next greater elements efficiently

        // Traverse nums2 from right to left
        for (int i = n2 - 1; i >= 0; i--)
        {
            // Pop smaller or equal elements as they can't be next greater for any previous element
            while (!st.empty() && nums2[i] >= st.top())
                st.pop();

            // If stack is empty, no greater element exists; otherwise, top of stack is the next greater element
            mp[nums2[i]] = st.empty() ? -1 : st.top();

            // Push current element for future comparisons
            st.push(nums2[i]);
        }

        vector<int> ans;
        // Build answer for elements in nums1 using precomputed map
        for (int num : nums1)
        {
            ans.push_back(mp[num]);
        }

        return ans; // Final result containing next greater elements for nums1
    }
};

// ================= Brute Force Solution =================

class Solution2
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;

        // For each element in nums1, search in nums2
        for (int i = 0; i < n1; ++i)
        {
            bool found = false; // Marks when nums1[i] is found in nums2

            // Traverse nums2 to find next greater element
            for (int j = 0; j < n2; ++j)
            {
                if (nums1[i] == nums2[j])
                    found = true; // Start checking after this element
                if (found && nums1[i] < nums2[j])
                {
                    ans.push_back(nums2[j]); // Found next greater
                    break;
                }
            }

            // If no greater element was found
            if (i == ans.size())
                ans.push_back(-1);
        }

        return ans;
    }
};