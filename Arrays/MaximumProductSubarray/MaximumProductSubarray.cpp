#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {

        int maxi = INT_MIN;
        int n = nums.size();
        int pre = 1, suff = 1;

        for (int i = 0; i < n; i++)
        {
            if (pre == 0)
                pre = 1; // Reset prefix if zero
            if (suff == 0)
                suff = 1; // Reset suffix if zero

            pre = pre * nums[i];           // Prefix product
            suff = suff * nums[n - i - 1]; // Suffix product

            maxi = max(maxi, max(pre, suff)); // Update max
        }

        return maxi;
    }
};
