#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Check if we can place k cows with at least minDis distance
    bool canWePlace(vector<int> &stalls, int k, int minDis)
    {
        int cowCnt = 1;
        int lastCow = 0;
        for (int i = 1; i < stalls.size(); i++)
        {
            if (stalls[i] - stalls[lastCow] >= minDis)
            {
                cowCnt++;
                lastCow = i;
            }
            if (cowCnt == k)
                return true; // All cows placed
        }
        return false;
    }

public:
    int aggressiveCows(vector<int> &stalls, int k)
    {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end()); // Sort stall positions
        int low = 1, high = stalls[n - 1] - stalls[0];

        // Binary search for the largest minimum distance
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (canWePlace(stalls, k, mid))
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};