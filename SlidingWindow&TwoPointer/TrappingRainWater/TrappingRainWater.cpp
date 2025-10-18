#include <bits/stdc++.h>
using namespace std;

// ================= Optimal Solution =================
class Solution1
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int l = 0, r = n - 1;   // Two pointers
        int lMax = 0, rMax = 0; // Track max height from left and right
        int cnt = 0;            // Accumulate trapped water

        while (l <= r)
        {
            if (height[l] <= height[r])
            { // Process smaller side
                if (lMax > height[l])
                    cnt += lMax - height[l]; // Water trapped at current
                else
                    lMax = height[l]; // Update left max
                l++;
            }
            else
            {
                if (rMax > height[r])
                    cnt += rMax - height[r]; // Water trapped at current
                else
                    rMax = height[r]; // Update right max
                r--;
            }
        }
        return cnt;
    }
};

// ================= More Better Solution - Space Optimized =================

class Solution2
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();

        vector<int> suffixMax(n, -1); // Max height to right
        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i)
            suffixMax[i] = max(suffixMax[i + 1], height[i]);

        int cnt = 0;
        int leftMax = 0; // Track max height from left
        for (int i = 0; i < n; ++i)
        {
            leftMax = max(leftMax, height[i]);
            int rightMax = suffixMax[i];
            cnt += min(leftMax, rightMax) - height[i]; // Water trapped at current
        }
        return cnt;
    }
};

// ================= Better Solution =================

class Solution3
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();

        vector<int> prefixMax(n, -1); // Max height to left
        prefixMax[0] = height[0];
        for (int i = 1; i < n; ++i)
            prefixMax[i] = max(prefixMax[i - 1], height[i]);

        vector<int> suffixMax(n, -1); // Max height to right
        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i)
            suffixMax[i] = max(suffixMax[i + 1], height[i]);

        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            int leftMax = prefixMax[i];
            int rightMax = suffixMax[i];
            cnt += min(leftMax, rightMax) - height[i]; // Water trapped at current
        }
        return cnt;
    }
};

// ================= Brute Force Solution =================

class Solution4
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int cnt = 0;

        for (int i = 0; i < n; ++i)
        {
            int j = i;
            int leftMax = 0, rightMax = 0;

            while (j >= 0)
            { // Find max height to left
                leftMax = max(leftMax, height[j]);
                j--;
            }
            j = i;
            while (j < n)
            { // Find max height to right
                rightMax = max(rightMax, height[j]);
                j++;
            }
            cnt += min(leftMax, rightMax) - height[i]; // Water trapped at current
        }
        return cnt;
    }
};