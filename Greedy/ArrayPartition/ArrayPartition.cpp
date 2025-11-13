#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        // Sort the array to pair smallest with next smallest
        sort(nums.begin(), nums.end());

        int ans = 0;
        // Take every alternate element (the smaller one in each sorted pair)
        for (int i = 0; i < nums.size(); i += 2)
            ans += nums[i];

        // Sum of minimums of pairs gives the maximum possible total
        return ans;
    }
};
