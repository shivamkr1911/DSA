#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        int n = dimensions.size();   // Number of rectangles
        int ansLen = 0, ansWid = 0;  // Store dimensions of rectangle with max diagonal
        double maxDiagLen = INT_MIN; // Track maximum diagonal length found so far

        for (int i = 0; i < n; ++i)
        {
            int len = dimensions[i][0]; // Current rectangle length
            int wid = dimensions[i][1]; // Current rectangle width

            // Calculate diagonal length using Pythagoras theorem
            double diagLen = sqrt(len * len + wid * wid);

            // Update if current diagonal is larger
            if (diagLen > maxDiagLen)
            {
                ansLen = dimensions[i][0];
                ansWid = dimensions[i][1];
                maxDiagLen = diagLen;
            }
            // If diagonal length is same, prefer rectangle with larger area
            else if (diagLen == maxDiagLen)
            {
                if (len * wid > ansLen * ansWid)
                {
                    ansLen = len;
                    ansWid = wid;
                }
            }
        }
        return (ansLen * ansWid); // Return area of rectangle with max diagonal
    }
};
