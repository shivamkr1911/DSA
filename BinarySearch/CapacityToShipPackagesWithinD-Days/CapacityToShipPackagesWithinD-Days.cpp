#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Calculate total sum of all weights (upper bound for binary search)
    int total(vector<int> &weights)
    {
        int t = 0;
        for (int i = 0; i < weights.size(); i++)
            t += weights[i];
        return t;
    }

    // Calculate how many days required if ship capacity = capacity
    int calcDays(vector<int> &weights, int capacity)
    {
        int days = 1; // start with day 1
        int load = 0; // current load for the day

        for (int i = 0; i < weights.size(); i++)
        {
            // If adding current weight exceeds capacity → next day
            if (load + weights[i] > capacity)
            {
                days++;
                load = weights[i]; // start new day with this package
            }
            else
            {
                load += weights[i]; // add to current day's load
            }
        }
        return days;
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        // Minimum possible capacity = heaviest package
        int low = *max_element(weights.begin(), weights.end());

        // Maximum possible capacity = sum of all weights
        int high = total(weights);

        // Binary search for minimum valid ship capacity
        while (low <= high)
        {
            int mid = (low + high) / 2; // capacity guess

            int daysReq = calcDays(weights, mid); // days needed at this capacity

            if (daysReq <= days)
                high = mid - 1; // capacity is sufficient → try smaller
            else
                low = mid + 1; // capacity insufficient → increase
        }

        return low; // lowest valid capacity
    }
};
