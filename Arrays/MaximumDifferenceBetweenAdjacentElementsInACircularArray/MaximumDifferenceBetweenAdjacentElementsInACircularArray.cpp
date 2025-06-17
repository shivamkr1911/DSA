#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxAdjacentDistance(vector<int> &nums)
    {
        int maxi = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int diff = (abs(nums[i] - nums[(i + 1) % n]));
            maxi = max(diff, maxi);
        }
        return maxi;
    }
};