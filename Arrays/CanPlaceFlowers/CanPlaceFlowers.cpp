#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution ===============
class Solution1
{
public:
    // Function to check if n flowers can be planted
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int f = flowerbed.size();
        int curr = 0; // current plot index
        int cnt = 0;  // flowers planted so far

        while (curr < f)
        {
            // Check if current plot is empty and adjacent plots are empty or out of bounds
            if (flowerbed[curr] == 0 &&
                (curr == 0 || flowerbed[curr - 1] == 0) &&
                (curr == f - 1 || flowerbed[curr + 1] == 0))
            {
                cnt++;               // Plant a flower
                flowerbed[curr] = 1; // Mark plot as planted
                curr += 2;           // Skip next plot
            }
            else
            {
                curr++; // move to next plot
            }
        }

        return (cnt >= n); // check if enough flowers were planted
    }
};
