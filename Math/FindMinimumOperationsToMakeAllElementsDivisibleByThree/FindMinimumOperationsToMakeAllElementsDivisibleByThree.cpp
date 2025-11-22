#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int ans = 0;

        // For each number, compute minimum steps to make it divisible by 3
        // Either add (3 - num%3) or subtract (num%3)
        for (int num : nums)
            ans += min(num % 3, 3 - (num % 3));

        return ans; // total minimum operations
    }
};
