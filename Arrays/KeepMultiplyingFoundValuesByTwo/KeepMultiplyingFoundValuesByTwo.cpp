#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findFinalValue(vector<int> &nums, int original)
    {
        unordered_set<int> st; // store all numbers for O(1) lookup
        int ans = original;

        // Insert all elements into the set
        for (int i = 0; i < nums.size(); ++i)
            st.insert(nums[i]);

        // Keep doubling the value while it exists in the set
        while (st.find(ans) != st.end())
        {
            ans *= 2;
        }

        return ans; // final doubled value not present in array
    }
};
