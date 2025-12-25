#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {

        // Sort happiness in descending order to pick highest values first
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long cnt = 0; // total happiness sum

        // Pick first k children
        for (int i = 0; i < k; ++i)
        {
            // Happiness reduces by i for each subsequent pick
            // Add only positive contribution
            cnt += max(happiness[i] - i, 0);
        }

        return cnt;
    }
};
