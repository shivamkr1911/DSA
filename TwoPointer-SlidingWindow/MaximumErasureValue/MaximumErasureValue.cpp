#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int score = 0, maxScore = 0;
        int left = 0, right = 0;

        while (right < n)
        {
            // If current number is not in the window
            if (mpp[nums[right]] == 0)
            {
                mpp[nums[right]] = 1;            // Mark number as seen
                score += nums[right];            // Add to current score
                maxScore = max(score, maxScore); // Update max score
                right++;
            }
            else
            {
                mpp[nums[left]]--;   // Remove leftmost element
                score -= nums[left]; // Subtract from score
                left++;
            }
        }
        return maxScore;
    }
};
