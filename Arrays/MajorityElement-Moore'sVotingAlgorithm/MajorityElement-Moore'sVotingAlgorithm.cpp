#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // Optimal Solution - Moore's Voting Algorithm
        // Idea: Cancel out different elements, majority element will remain
        int n = nums.size();
        int ele = -1; // potential candidate
        int cnt = 0;  // counter for candidate

        // Step 1: Find candidate element
        for (int i = 0; i < n; i++)
        {
            if (cnt == 0)
            {
                ele = nums[i]; // take new candidate
                cnt++;
            }
            else if (nums[i] == ele)
                cnt++; // same element → increase count
            else
                cnt--; // different element → cancel out
        }

        // Step 2: Verify if candidate is actually majority
        int ele_cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == ele)
                ele_cnt++;
        }
        if (ele_cnt > n / 2)
            return ele; // valid majority
        return -1;      // no majority element

        // Better Solution - Using HashMap
        /*
        // Count frequency of each element using map
        map<int, int> mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;
        }
        // Check if any element occurs more than n/2 times
        for(auto it: mpp)
        {
            if (it.second > n / 2) return it.first;
        }
        return -1; // no majority element
        */

        // Brute Force Solution - Nested Loops
        /*
        // Check frequency of each element by traversing the array
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                if (nums[i] == nums[j])
                    cnt++;
            }
            if (cnt > n / 2)
                return nums[i]; // found majority element
        }
        return -1; // no majority element
        */
    }
};
