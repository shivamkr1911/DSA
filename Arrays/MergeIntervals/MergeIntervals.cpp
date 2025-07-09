#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end()); // Sort by start time
        vector<vector<int>> ans;

        // Merge overlapping intervals
        for (int i = 0; i < n; i++)
        {
            if (ans.empty() || intervals[i][0] > ans.back()[1])
            {
                ans.push_back(intervals[i]); // No overlap, add new interval
            }
            else
            {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]); // Merge overlap
            }
        }

        return ans;
    }
};
