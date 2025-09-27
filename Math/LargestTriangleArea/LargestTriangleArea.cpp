#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        int n = points.size();
        double maxi = INT_MIN; // Store the maximum triangle area

        // Iterate through all triplets of points
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {

                    // Using shoelace formula to calculate area
                    int a = points[i][0] * (points[j][1] - points[k][1]);
                    int b = points[j][0] * (points[k][1] - points[i][1]);
                    int c = points[k][0] * (points[i][1] - points[j][1]);

                    double area = 0.5 * abs(a + b + c); // Area of current triangle

                    maxi = max(maxi, area); // Update maximum area
                }
            }
        }
        return maxi; // Return the largest area
    }
};
