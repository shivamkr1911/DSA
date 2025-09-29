#include <bits/stdc++.h>
using namespace std;

// Optimal Solution
class Solution
{
public:
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return 0;    // Edge case: empty array
        int longest = 1; // Stores the length of the longest sequence

        unordered_set<int> st; // HashSet to store unique elements for O(1) lookup
        for (int i = 0; i < n; ++i)
        {
            st.insert(arr[i]);
        }

        // Iterate through each unique number in the set
        for (auto it : st)
        {
            // Check if 'it' is the starting number of a sequence
            // (i.e., it-1 does not exist in the set)
            if (st.find(it - 1) == st.end())
            {
                int cnt = 1; // Current sequence length
                int x = it;  // Current number

                // Keep moving forward while next consecutive number exists
                while (st.find(x + 1) != st.end())
                {
                    x = x + 1;
                    cnt++;
                }

                // Update longest sequence length
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};

// Better Solution
/*
class Solution {
  public:
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        sort(arr.begin(), arr.end()); // Sorting helps identify consecutive numbers
        int n = arr.size();
        if (n == 0) return 0;
        int longest = 1;      // Stores longest length
        int lastSmaller = INT_MIN; // Tracks previous element
        int currCnt = 0;      // Current sequence length

        for (int i = 0; i < n; i++) {
            if (arr[i] - 1 == lastSmaller) {
                // Consecutive element found
                currCnt++;
                lastSmaller = arr[i];
            }
            else if (arr[i] != lastSmaller) {
                // Reset count for new sequence
                currCnt = 1;
                lastSmaller = arr[i];
            }
            longest = max(longest, currCnt);
        }
        return longest;
    }
};
*/

// Brute Force
/*
class Solution {
  private:
    // Helper function to check if num exists in arr (O(n) search)
    bool linear(vector<int> &arr, int num) {
        for (int i = 0; i < arr.size(); i++) {
           if (arr[i] == num) return true;
        }
        return false;
    }

  public:
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        int longest = 1;

        for (int i = 0; i < n; ++i) {
            int cnt = 1;    // Current sequence length
            int x = arr[i]; // Starting number

            // Keep checking next numbers linearly
            while (linear(arr, x + 1)) {
                x++;
                cnt++;
            }

            longest = max(longest, cnt);
        }
        return longest;
    }
};
*/
