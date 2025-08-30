#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // Optimal solution - Using Hash Map
        int n = nums.size();
        map<int, int> mpp; // stores number -> index

        for (int i = 0; i < n; ++i)
        {
            int num = nums[i];               // current number
            int moreRequired = target - num; // number needed to form target

            // check if required number is already in map
            if (mpp.find(moreRequired) != mpp.end())
            {
                return {mpp[moreRequired], i}; // return indices
            }

            // store current number with its index
            mpp[num] = i;
        }
        return {-1, -1}; // if no pair found

        // Brute force
        /*
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // check every pair
                if (nums[i] + nums[j] == target)
                    return {i, j}; // return indices if sum matches
            }
        }
        return {-1, -1}; // if no pair found
        */
    }
};
