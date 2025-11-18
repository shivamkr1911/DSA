#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution - Two Pointer ===============
class Solution1
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0; // pointer for the last unique element

        // j scans through the array
        for (int j = 1; j < nums.size(); ++j)
        {
            // When a new unique element is found, move it next to the last unique one
            if (nums[j] != nums[i])
            {
                nums[i + 1] = nums[j];
                i++;
            }
        }
        // i + 1 gives the count of unique elements
        return i + 1;
    }
};

// =============== Brute Force ===============
class Solution2
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        set<int> st; // stores unique elements automatically in sorted order

        // Insert all elements into the set to remove duplicates
        for (int i = 0; i < nums.size(); ++i)
        {
            st.insert(nums[i]);
        }

        int ind = 0;
        // Copy back the unique elements into the array
        for (auto it : st)
        {
            nums[ind] = it;
            ind++;
        }

        // Return total count of unique elements
        return ind;
    }
};
