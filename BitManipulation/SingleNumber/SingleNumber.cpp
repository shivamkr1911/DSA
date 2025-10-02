#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        // Optimal Solution: use XOR (a ^ a = 0, a ^ 0 = a)
        int xor1 = 0;
        for (int i = 0; i < n; ++i)
        {
            xor1 ^= nums[i]; // cancel out duplicates, only single element remains
        }
        return xor1;

        // Better Solution: use frequency map
        /*
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; ++i) {
            mpp[nums[i]]++;  // count frequency
        }
        for (auto it : mpp) {
            if (it.second == 1)  // element with frequency 1 is the answer
                return it.first;
        }
        return -1;
        */

        // Brute Force: count frequency by nested loop
        /*
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (nums[i] == nums[j])
                    cnt++;
            }
            if (cnt == 1)  // element appears only once
                return nums[i];
        }
        return -1;
        */
    }
};
