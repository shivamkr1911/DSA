#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int mini = (int)(n / 3) + 1; // Minimum freq needed

        // Moore's Voting Algorithm

        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (cnt1 == 0 && el2 != nums[i])
            {
                cnt1 = 1;
                el1 = nums[i]; // New candidate 1
            }
            else if (cnt2 == 0 && el1 != nums[i])
            {
                cnt2 = 1;
                el2 = nums[i]; // New candidate 2
            }
            else if (el1 == nums[i])
                cnt1++; // Match candidate 1
            else if (el2 == nums[i])
                cnt2++; // Match candidate 2
            else
            {
                cnt1--; // No match, decrease counts
                cnt2--;
            }
        }

        int el1Cnt = 0, el2Cnt = 0;

        // Count actual occurrences
        for (int i = 0; i < n; i++)
        {
            if (el1 == nums[i])
                el1Cnt++;
            if (el2 == nums[i])
                el2Cnt++;
        }

        vector<int> ans;

        if (el1Cnt >= mini)
            ans.push_back(el1);
        if (el2Cnt >= mini)
            ans.push_back(el2);

        sort(ans.begin(), ans.end()); // Optional sort
        return ans;
    }
};
