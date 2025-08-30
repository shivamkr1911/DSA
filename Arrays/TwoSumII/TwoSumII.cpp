#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool twoSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        int left = 0, right = n - 1;
        sort(arr.begin(), arr.end()); // sort array first

        while (left < right)
        {
            int sum = arr[left] + arr[right]; // current pair sum

            if (sum == target)
                return true; // pair found
            else if (sum < target)
                left++; // increase sum by moving left pointer
            else
                right--; // decrease sum by moving right pointer
        }

        return false; // no pair found
    }
};
