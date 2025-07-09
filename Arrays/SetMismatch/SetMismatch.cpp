#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();

        // Optimal Solution - Using XOR

        int xr = 0;
        // Step 1: XOR all nums[i] and numbers 1 to n
        for (int i = 0; i < n; i++)
        {
            xr ^= nums[i];
            xr ^= (i + 1);
        }

        // Step 2: Find rightmost set bit
        int bitNo = 0;
        while ((xr & (1 << bitNo)) == 0)
            bitNo++;

        int zero = 0, one = 0;

        // Step 3: Bucket partitioning for nums[]
        for (int i = 0; i < n; i++)
        {
            if ((nums[i] & (1 << bitNo)) != 0)
                one ^= nums[i];
            else
                zero ^= nums[i];
        }

        // Step 3: Bucket partitioning for 1 to n
        for (int i = 1; i <= n; i++)
        {
            if ((i & (1 << bitNo)) != 0)
                one ^= i;
            else
                zero ^= i;
        }

        // Step 4: Find which is duplicate
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == one)
                cnt++;
        }

        if (cnt == 2)
            return {one, zero}; // one = duplicate, zero = missing
        return {zero, one};     // zero = duplicate, one = missing

        // Optimal Solution - Using Maths

        /*
        long long Sn = (1LL * n * (n + 1)) / 2; // Sum 1 to n
        long long S2n = (1LL * n * (n + 1) * (2 * n + 1)) / 6; // Sum squares 1 to n

        long long S = 0, S2 = 0;
        for (int i = 0; i < n; i++) {
            S += nums[i];
            S2 += 1LL * nums[i] * nums[i];
        }

        long long val1 = S - Sn;          // X - Y
        long long val2 = (S2 - S2n) / val1; // X + Y

        long long x = (val1 + val2) / 2;  // X = duplicate
        long long y = x - val1;           // Y = missing

        return {(int)x, (int)y};
        */
    }
};
