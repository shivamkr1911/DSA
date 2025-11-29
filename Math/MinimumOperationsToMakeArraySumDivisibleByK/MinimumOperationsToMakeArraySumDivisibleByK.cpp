#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int n = nums.size();
        int sum = 0;

        // Compute total sum modulo k (because only the remainder matters)
        for (int i = 0; i < n; ++i)
            sum = (sum + nums[i]) % k;

        // Minimum operations required = remainder (to make divisible by k)
        return sum;

        // Alternative one-liner:
        // return accumulate(nums.begin(), nums.end(), 0) % k;
    }
};
