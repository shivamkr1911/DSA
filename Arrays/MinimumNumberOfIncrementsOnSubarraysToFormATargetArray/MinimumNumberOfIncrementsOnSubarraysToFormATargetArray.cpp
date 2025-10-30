#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minNumberOperations(vector<int> &target)
    {
        int n = target.size();

        // Start with the cost of building the first element
        int ans = target[0];

        for (int i = 1; i < n; ++i)
        {
            // If current value is greater than previous,
            // we need extra (target[i] - target[i-1]) operations
            if (target[i - 1] < target[i])
                ans += target[i] - target[i - 1];
        }

        // Total minimal operations required
        return ans;
    }
};
