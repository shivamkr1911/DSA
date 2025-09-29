#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(vector<int> &arr)
    {
        // ---------- Optimal Solution ----------
        int n = arr.size();
        int maxi = -1;   // Keeps track of the maximum element seen so far (from right)
        vector<int> ans; // Stores all leaders

        // Traverse array from right to left
        for (int i = n - 1; i >= 0; --i)
        {
            // If current element is greater than or equal to all elements to its right
            if (arr[i] >= maxi)
            {
                maxi = arr[i];         // Update the maximum
                ans.push_back(arr[i]); // Current element is a leader
            }
        }

        // Reverse the result since we collected leaders from right to left
        reverse(ans.begin(), ans.end());
        return ans;

        // ---------- Brute Force Solution ----------
        /*
        int n = arr.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            bool isLeader = true;

            // Check if arr[i] is greater than or equal to all elements to its right
            for (int j = i + 1; j < n; ++j) {
                if (arr[i] < arr[j]) {
                    isLeader = false;
                    break;
                }
            }

            // If true, add to result
            if (isLeader) ans.push_back(arr[i]);
        }
        return ans;
        */
    }
};
