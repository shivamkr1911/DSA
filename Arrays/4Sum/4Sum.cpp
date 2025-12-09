#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution ===============
class Solution1
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end()); // sort for two-pointer + duplicate handling

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) // skip duplicate for index i
                continue;

            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) // skip duplicate for index j
                    continue;

                int k = j + 1;
                int l = n - 1;

                // classic 2-pointer for remaining two values
                while (k < l)
                {
                    long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;

                        // skip duplicates on both sides
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < target)
                        k++; // need larger sum
                    else
                        l--; // need smaller sum
                }
            }
        }
        return ans;
    }
};

// =============== Better Solution ===============
class Solution2
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        set<vector<int>> st; // to avoid duplicates automatically

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                set<long long> hashset; // stores seen third elements

                for (int k = j + 1; k < n; k++)
                {
                    long long sum = nums[i] + nums[j] + nums[k];
                    long long fourth = target - sum; // required fourth value

                    // if we already saw fourth earlier → valid quadruple
                    if (hashset.find(fourth) != hashset.end())
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }

                    hashset.insert(nums[k]); // mark current number as seen
                }
            }
        }

        // convert set to vector result
        return vector<vector<int>>(st.begin(), st.end());
    }
};
