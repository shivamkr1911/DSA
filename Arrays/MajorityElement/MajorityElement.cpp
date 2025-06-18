#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // Moore's Voting Algorithm
        int n = nums.size();
        int ele = -1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (cnt == 0)
            {
                ele = nums[i];
                cnt++;
            }
            else if (nums[i] == ele)
                cnt++;
            else
                cnt--;
        }
        int ele_cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == ele)
                ele_cnt++;
        }
        if (ele_cnt > n / 2)
            return ele;
        return -1;
    }
};