#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution (Prefix Accumulation from Left & Right) ===============
class Solution1
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();

        vector<int> left(n, 0), right(n, 0);
        int balls = 0, ops = 0;

        // Left to right pass:
        // left[i] = operations needed to bring all balls from left side to index i
        for (int i = 0; i < n; ++i)
        {
            left[i] = ops;
            if (boxes[i] == '1')
                balls++;  // found a ball
            ops += balls; // each ball moves one step further
        }

        balls = 0;
        ops = 0;

        // Right to left pass:
        // right[i] = operations needed to bring all balls from right side to index i
        for (int i = n - 1; i >= 0; --i)
        {
            right[i] = ops;
            if (boxes[i] == '1')
                balls++;
            ops += balls;
        }

        // Combine left and right costs
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            ans[i] = left[i] + right[i];
        }

        return ans;
    }
};

// =============== Brute Force ===============
class Solution2
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        vector<int> ans;

        // For each box, calculate distance to every other ball
        for (int i = 0; i < n; ++i)
        {
            int cnt = 0;
            for (int j = 0; j < n; ++j)
            {
                if (boxes[j] == '1')
                {
                    cnt += abs(i - j); // cost to move ball j to box i
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
