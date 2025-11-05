#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {

        int prev = 0; // index of the previous balloon
        int time = 0; // total time to remove balloons

        // Traverse all balloons starting from the second one
        for (int i = 1; i < colors.size(); ++i)
        {

            // If two adjacent balloons have the same color
            if (colors[i] == colors[prev])
            {

                // Remove the one with smaller removal time
                if (neededTime[prev] < neededTime[i])
                {
                    time += neededTime[prev]; // remove previous
                    prev = i;                 // update to current balloon
                }
                else
                {
                    time += neededTime[i]; // remove current balloon
                }
            }
            else
            {
                prev = i; // move to next different color
            }
        }

        return time; // return total removal cost
    }
};
