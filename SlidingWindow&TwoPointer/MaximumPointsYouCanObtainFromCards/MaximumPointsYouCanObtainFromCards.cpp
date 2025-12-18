#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int lSum = 0, rSum = 0;

        // Take first k cards from the left initially
        for (int i = 0; i < k; ++i)
        {
            lSum += cardPoints[i];
        }

        int maxi = lSum;      // maximum score so far
        int rightInd = n - 1; // pointer for right side cards

        // Gradually replace left cards with right cards
        for (int i = k - 1; i >= 0; --i)
        {
            lSum -= cardPoints[i];        // remove one card from left
            rSum += cardPoints[rightInd]; // add one card from right
            rightInd--;

            // update maximum score
            maxi = max(maxi, lSum + rSum);
        }

        // Alternative loop version (same logic)
        /*
        for (int i = 0; i < k; ++i) {
            lSum -= cardPoints[k - i - 1];
            rSum += cardPoints[n - i - 1];
            maxi = max(maxi, lSum + rSum);
        }
        */

        return maxi;
    }
};
