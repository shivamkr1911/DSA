#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Count painters needed for given max boards per painter
    int countPainters(vector<int> &arr, int maxBoardsPerPainter)
    {
        int currentPainterLoad = 0;
        int painterCount = 1;

        for (int i = 0; i < arr.size(); i++)
        {
            if (currentPainterLoad + arr[i] <= maxBoardsPerPainter)
                currentPainterLoad += arr[i]; // Add board to current painter
            else
            {
                painterCount++; // Assign new painter
                currentPainterLoad = arr[i];
            }
        }
        return painterCount;
    }

public:
    int minTime(vector<int> &arr, int k)
    {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        // Binary search for minimum possible time
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (countPainters(arr, mid) > k) // Too many painters needed
                low = mid + 1;
            else
                high = mid - 1; // Possible, try lower
        }
        return low; // Minimum time to paint all boards
    }
};
