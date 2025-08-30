#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to reverse elements in range [start, end]
    void reverse(vector<int> &arr, int start, int end)
    {
        while (start <= end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

public:
    void rotateArr(vector<int> &arr, int d)
    {
        // Optimal Approach using extra space
        /*
        int n = arr.size();
        d = d % n;                        // Handle case when d > n
        vector<int> temp;                 // Store first d elements
        for (int i = 0; i < d; ++i) {
            temp.push_back(arr[i]);
        }
        for (int i = d; i < n; ++i) {     // Shift remaining elements left
            arr[i - d] = arr[i];
        }
        for (int i = 0; i < temp.size(); ++i) {
            arr[n - d + i] = temp[i];     // Place stored elements at end
        }
        */

        // Using reversal algorithm (In-place, O(1) space)
        int n = arr.size();
        d = d % n;              // Handle case when d > n
        reverse(arr, 0, d - 1); // Reverse first d elements
        reverse(arr, d, n - 1); // Reverse remaining elements
        reverse(arr, 0, n - 1); // Reverse whole array
    }
};
