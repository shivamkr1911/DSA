#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Find the maximum element in piles (upper bound for binary search)
    int maxi(vector<int> &piles)
    {
        int m = INT_MIN;
        for (int i = 0; i < piles.size(); ++i)
        {
            m = max(m, piles[i]);
        }
        return m;
    }

    // Calculate total time Koko needs at a given eating speed (hourly)
    long long calculateTime(vector<int> &piles, int hourly)
    {
        long long timeRequired = 0;

        // For each pile, compute hours needed (ceil division)
        for (int i = 0; i < piles.size(); ++i)
        {
            // Integer math equivalent of ceil(piles[i] / hourly)
            timeRequired += (piles[i] + (hourly - 1)) / hourly;
        }

        return timeRequired;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {

        // Binary search for the minimum valid eating speed
        int low = 1, high = maxi(piles);

        while (low <= high)
        {
            int mid = low + (high - low) / 2; // Avoid potential overflow
            long long timeRequired = calculateTime(piles, mid);

            // If time fits within h hours → try smaller speed
            if (timeRequired <= h)
                high = mid - 1;
            else // otherwise → increase speed
                low = mid + 1;
        }

        return low; // lowest valid eating speed
    }
};