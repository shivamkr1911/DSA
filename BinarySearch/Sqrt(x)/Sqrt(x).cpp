#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        int ans = -1;
        int low = 1, high = x;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (1LL * mid * mid <= x)
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};