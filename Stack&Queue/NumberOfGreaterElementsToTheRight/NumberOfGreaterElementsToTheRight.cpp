#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices)
    {
        int n = arr.size(); // Total number of elements in the array
        vector<int> ans;    // Stores the count of next greater elements for each index

        // Loop through each given index
        for (int idx : indices)
        {
            int cnt = 0; // Counter to count elements greater than arr[idx]

            // Check elements to the right of the current index
            for (int j = idx + 1; j < n; ++j)
            {
                if (arr[j] > arr[idx]) // If element is greater than arr[idx], increment count
                    cnt++;
            }

            ans.push_back(cnt); // Store the count for this index
        }

        return ans; // Return final result
    }
};
