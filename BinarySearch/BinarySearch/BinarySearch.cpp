#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
class Solution1
{
private:
    // Recursive binary search
    int bs(vector<int> &nums, int low, int high, int target)
    {
        if (low > high)
            return -1; // Base case

        int mid = (low + high) / 2;

        if (nums[mid] == target)
            return mid; // Found target
        else if (target > nums[mid])
            return bs(nums, mid + 1, high, target); // Search right
        return bs(nums, low, mid - 1, target);      // Search left
    }

public:
    int search(vector<int> &nums, int target)
    {
        return bs(nums, 0, nums.size() - 1, target);
    }
};

// Iterative Solution
class Solution2
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] == target)
                return mid; // Found target
            else if (target > nums[mid])
                low = mid + 1; // Search right
            else
                high = mid - 1; // Search left
        }
        return -1; // Not found
    }
};
