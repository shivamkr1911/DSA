#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = INT_MIN;
        unordered_map<int, int> mpp;
        for (int num : nums)
        {
            mpp[num]++;
            maxi = max(maxi, mpp[num]);
        }

        int cnt = 0;
        for (auto it : mpp)
        {
            if (it.second == maxi)
                cnt += it.second;
        }
        return cnt;
    }
};