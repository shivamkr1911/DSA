#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countValidSelections(vector<int> &nums)
    {
        int n = nums.size();

        // preSum  = sum of elements to the LEFT of current index
        int preSum = 0;

        // postSum = sum of all elements initially (will decrease as we move)
        int postSum = accumulate(nums.begin(), nums.end(), 0);

        int ans = 0; // Total valid selections

        for (int num : nums)
        {

            // Remove current element from right-side sum
            postSum -= num;

            // Case 1: If current value is 0 and leftSum == rightSum,
            //         then we can take either +1 or -1 → 2 valid selections
            if (num == 0 && preSum == postSum)
                ans += 2;

            // Case 2: If current value is 0 but sums differ by exactly 1,
            //         then only one choice (+1 or -1) works → 1 valid selection
            else if (num == 0 &&
                     (preSum == postSum + 1 || postSum == preSum + 1))
                ans++;

            // Add current num to left sum before moving to next index
            preSum += num;
        }

        return ans; // Return total valid selection count
    }
};
