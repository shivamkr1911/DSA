#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            int moreRequired = target - num;
            if (mpp.find(moreRequired) != mpp.end())
            {
                return {mpp[moreRequired], i};
            }
            mpp[num] = i;
        }
        return {-1, -1};
    }
};