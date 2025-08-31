#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {
        // ✅ Using boolean arrays
        // Idea: Track presence in each array to count frequency across arrays
        vector<int> freq(101); // frequency of numbers across arrays

        // Process nums1
        vector<bool> bool1(101, false); // to avoid counting duplicates in same array
        for (int x : nums1)
        {
            if (!bool1[x])
            {
                freq[x]++; // increment count if first occurrence
                bool1[x] = true;
            }
        }

        // Process nums2
        vector<bool> bool2(101, false);
        for (int x : nums2)
        {
            if (!bool2[x])
            {
                freq[x]++;
                bool2[x] = true;
            }
        }

        // Process nums3
        vector<bool> bool3(101, false);
        for (int x : nums3)
        {
            if (!bool3[x])
            {
                freq[x]++;
                bool3[x] = true;
            }
        }

        // Collect elements present in at least 2 arrays
        vector<int> ans;
        for (int i = 1; i <= 100; ++i)
        {
            if (freq[i] > 1)
                ans.push_back(i);
        }
        return ans;

        // ✅ Using sets
        /*
        // Use sets to store unique elements from each array
        set<int> s1, s2, s3;
        for (int i = 0; i < nums1.size(); ++i) s1.insert(nums1[i]);
        for (int j = 0; j < nums2.size(); ++j) s2.insert(nums2[j]);
        for (int k = 0; k < nums3.size(); ++k) s3.insert(nums3[k]);

        // Count frequency across sets
        vector<int> freq(101);
        for (auto it: s1) freq[it]++;
        for (auto it: s2) freq[it]++;
        for (auto it: s3) freq[it]++;

        // Collect elements present in at least 2 arrays
        vector<int> ans;
        for (int i = 1; i <= 100; ++i) {
            if (freq[i] > 1)
                ans.push_back(i);
        }
        return ans;
        */
    }
};
