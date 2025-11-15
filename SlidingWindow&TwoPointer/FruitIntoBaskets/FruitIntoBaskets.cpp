#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution ===============
class Solution1
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        unordered_map<int, int> mpp; // stores fruit type → count in current window
        int l = 0, r = 0;
        int maxi = 0;

        while (r < n)
        {
            mpp[fruits[r]]++; // add current fruit to basket

            // If more than 2 fruit types, shrink window from left
            if (mpp.size() > 2)
            {
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0)
                    mpp.erase(fruits[l]); // remove type with zero count
                l++;
            }

            // Update max window size (valid basket size)
            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }
};

// =============== Better Solution ===============
class Solution2
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        int l = 0, r = 0;
        int maxi = 0;
        unordered_map<int, int> mpp; // fruit type → count

        while (r < n)
        {
            mpp[fruits[r]]++; // include rightmost fruit

            // While more than 2 types, shrink from left
            if (mpp.size() > 2)
            {
                while (mpp.size() > 2)
                {
                    mpp[fruits[l]]--;
                    if (mpp[fruits[l]] == 0)
                        mpp.erase(fruits[l]);
                    l++;
                }
            }

            // Track longest valid window
            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }
};

// =============== Brute Force ===============
class Solution3
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        int maxi = 0;

        // Try every possible subarray and check number of unique fruit types
        for (int i = 0; i < n; ++i)
        {
            set<int> st; // to store distinct fruit types
            for (int j = i; j < n; ++j)
            {
                st.insert(fruits[j]);
                if (st.size() > 2) // more than 2 types → stop
                    break;
                maxi = max(maxi, j - i + 1);
            }
        }
        return maxi;
    }
};
