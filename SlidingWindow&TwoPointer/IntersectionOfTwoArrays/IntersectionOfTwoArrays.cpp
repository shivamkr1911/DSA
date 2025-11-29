#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;

        // Sort both arrays to use two-pointer scanning
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;

        // Traverse both arrays together
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {

                // Push only if it's not a duplicate in the answer
                if (ans.empty() || nums1[i] != ans.back())
                    ans.push_back(nums1[i]);

                i++;
                j++;
            }
            // Move pointer of smaller element
            else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }

        return ans;
    }
};
