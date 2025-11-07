#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution ===============
class Solution1
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq; // stores indices, maintains decreasing order of values
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i)
        {

            // Remove index that is out of the current window (i - k)
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            // Maintain decreasing order → remove smaller elements from back
            while (!dq.empty() && nums[i] > nums[dq.back()])
                dq.pop_back();

            // Push current index
            dq.push_back(i);

            // From index k-1 onwards, record window maximum
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]); // front holds the max index
        }

        return ans;
    }
};

// =============== Brute Force ===============
class Solution2
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;

        // For each window, find max by scanning all k elements
        for (int i = 0; i <= n - k; ++i)
        {
            int maxi = nums[i];
            for (int j = i + 1; j < i + k; ++j)
                maxi = max(maxi, nums[j]); // compute max of current window
            ans.push_back(maxi);
        }

        return ans;
    }
};
