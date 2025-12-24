#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        int total = 0;

        // Calculate total number of apples
        for (int x : apple)
            total += x;

        // Sort box capacities in descending order to use largest boxes first
        sort(capacity.begin(), capacity.end(), greater<int>());

        int cap = 0;   // total capacity used so far
        int boxes = 0; // number of boxes used

        // Keep adding boxes until capacity can hold all apples
        for (int c : capacity)
        {
            cap += c;
            boxes++;

            if (cap >= total)
                break;
        }

        return boxes;
    }
};
