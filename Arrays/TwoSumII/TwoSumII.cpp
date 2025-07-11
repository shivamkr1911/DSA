#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool twoSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        int left = 0, right = n - 1;
        sort(arr.begin(), arr.end());
        while (left < right)
        {
            int sum = arr[left] + arr[right];
            if (sum == target)
                return true;
            else if (sum < target)
                left++;
            else
                right--;
        }
        return false;
    }
};