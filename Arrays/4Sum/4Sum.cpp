#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end()); // Sort array

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // Skip dup i

            for (int j = i + 1; j < n; j++)
            {
                if (j != (i + 1) && nums[j] == nums[j - 1])
                    continue; // Skip dup j

                int k = j + 1;
                int l = n - 1;

                while (k < l)
                {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp); // Found quadruplet

                        k++;
                        l--;

                        while (k < l && nums[k] == nums[k - 1])
                            k++; // Skip dup k
                        while (k < l && nums[l] == nums[l + 1])
                            l--; // Skip dup l
                    }
                    else if (sum < target)
                        k++; // Need bigger sum
                    else
                        l--; // Need smaller sum
                }
            }
        }

        return ans;
    }
};
