#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        int left = 0, right = 0;
        unordered_map<int, int> freq; // Store count of fruits in window
        int maxi = 0;

        while (right < n)
        {
            freq[fruits[right]]++; // Add current fruit

            while (freq.size() > 2)
            { // More than 2 types
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0)
                    freq.erase(fruits[left]); // Remove fruit type if count becomes 0
                left++;                       // Shrink window
            }

            maxi = max(maxi, right - left + 1); // Update max size
            right++;                            // Expand window
        }
        return maxi;
    }
};
