#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to compute X-Sum for the subarray nums[l...r]
    int xSum(vector<int> &nums, int l, int r, int x)
    {

        int n = nums.size();

        // Frequency array for values 1 to 50
        vector<int> freq(51, 0);

        // Count frequencies in the current window
        for (int i = l; i <= r; ++i)
            freq[nums[i]]++;

        // Store (value, frequency) pairs
        vector<pair<int, int>> items;
        for (int val = 1; val <= 50; ++val)
        {
            if (freq[val] > 0)
            {
                items.push_back({val, freq[val]});
            }
        }

        // Sort by:
        // 1) Higher frequency first
        // 2) If frequencies equal → higher value first
        sort(items.begin(), items.end(), [&](auto &a, auto &b)
             {
            if (a.second != b.second)
                return a.second > b.second;
            return a.first > b.first; });

        int sum = 0;

        // Take the top 'x' most frequent elements
        for (auto &p : items)
        {
            if (x == 0)
                break;
            sum += p.first * p.second; // Add total contribution: value * frequency
            x--;
        }
        return sum;
    }

public:
    // Main function to compute X-Sum for every window of size k
    vector<int> findXSum(vector<int> &nums, int k, int x)
    {

        int n = nums.size();
        vector<int> ans;

        int l = 0, r = k - 1;

        // Slide window across array
        while (r < n)
        {

            // Compute xSum for current window
            int sum = xSum(nums, l, r, x);
            ans.push_back(sum);

            // Move window forward
            l++;
            r++;
        }
        return ans;
    }
};
