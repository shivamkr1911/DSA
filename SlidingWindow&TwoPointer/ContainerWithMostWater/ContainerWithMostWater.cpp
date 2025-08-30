#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        // Optimal Solution - Two pointer
        int n = height.size();
        int maxi = INT_MIN;          // stores max area
        int left = 0, right = n - 1; // two pointers at both ends

        while (left < right)
        {
            // calculate area between lines at left and right
            int area = (right - left) * min(height[left], height[right]);
            maxi = max(maxi, area); // update max area

            // move the pointer with smaller height
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxi; // return maximum area found

        // Brute force
        /*
        int n = height.size();
        int maxi = INT_MIN; // stores max area
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // calculate area between every pair
                int area = (j - i) * min(height[i], height[j]);
                maxi = max(maxi, area); // update max area
            }
        }
        return maxi; // return maximum area found
        */
    }
};
