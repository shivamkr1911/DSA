#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {

        int n = colors.size();
        int total = 0; // Total time to remove balloons

        int groupTotalTime = 0; // Sum of times in current same-color group
        int groupMaxTime = 0;   // Max time in current same-color group

        for (int i = 0; i < n; ++i)
        {

            // If color changes, process previous group
            if (i > 0 && colors[i] != colors[i - 1])
            {
                total += groupTotalTime - groupMaxTime;
                // Keep the balloon with max time, remove the rest

                groupTotalTime = 0; // Reset for next group
                groupMaxTime = 0;
            }

            // Add current balloon to the group
            groupTotalTime += neededTime[i];
            groupMaxTime = max(groupMaxTime, neededTime[i]);
        }

        // Process the last group
        total += groupTotalTime - groupMaxTime;

        return total;
    }
};
