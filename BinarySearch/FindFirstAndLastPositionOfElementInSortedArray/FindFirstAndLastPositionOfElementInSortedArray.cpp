#include <bits/stdc++.h>
using namespace std;

// Using raw BS (Without Lower and Upper Bound)

class Solution
{

private:
    // Find first occurrence of target
    int firstOccurence(vector<int> &nums, int n, int target)
    {
        int low = 0, high = n - 1;
        int first = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                first = mid; // Found, move left
                high = mid - 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1; // Search right part
            }
            else
            {
                high = mid - 1; // Search left part
            }
        }
        return first;
    }

    // Find last occurrence of target
    int lastOccurence(vector<int> &nums, int n, int target)
    {
        int low = 0, high = n - 1;
        int last = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                last = mid; // Found, move right
                low = mid + 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1; // Search right part
            }
            else
            {
                high = mid - 1; // Search left part
            }
        }
        return last;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int first = firstOccurence(nums, n, target);
        if (first == -1)
            return {-1, -1}; // Not found
        int last = lastOccurence(nums, n, target);
        return {first, last};
    }
};

// Using Lower Bound and Upper Bound with BS

/*
class Solution {

private:
    // Custom lower bound
    int lowerBound(vector<int>& nums, int n, int target) {
        int low = 0, high = n - 1, ans = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= target) {
                ans = mid;      // Possible lower bound
                high = mid - 1; // Search left
            }
            else {
                low = mid + 1;  // Search right
            }
        }
        return ans;
    }

    // Custom upper bound
    int upperBound(vector<int>& nums, int n, int target) {
        int low = 0, high = n - 1, ans = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > target) {
                ans = mid;      // Possible upper bound
                high = mid - 1; // Search left
            }
            else {
                low = mid + 1;  // Search right
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = lowerBound(nums, n, target);
        if (first == n || nums[first] != target) return {-1, -1}; // Not found
        int last = upperBound(nums, n, target) - 1;
        return {first, last};
    }
};
*/
