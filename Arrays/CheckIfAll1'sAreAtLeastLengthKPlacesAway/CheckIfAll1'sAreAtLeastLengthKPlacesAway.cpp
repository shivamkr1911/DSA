#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution ===============
class Solution1
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int lastOne = -1; // stores index of the last encountered '1'

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                // If a previous '1' exists, check the gap between them
                if (lastOne != -1 && i - lastOne - 1 < k)
                    return false; // not enough gap → condition fails

                // Update last seen '1' position
                lastOne = i;
            }
        }
        return true; // all '1's are at least k apart
    }
};

// =============== Brute Force ===============
class Solution2
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int n = nums.size();

        // For each '1', check next k elements to ensure no other '1' appears
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == 1)
            {
                for (int j = i + 1; j <= i + k && j < n; ++j)
                {
                    if (nums[j] == 1)
                        return false; // found another '1' within k distance
                }
            }
        }
        return true;
    }
};
