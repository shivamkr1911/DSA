#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    // Merge two sorted halves [low..mid] and [mid+1..high]
    void merge(vector<int> &nums, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (nums[left] <= nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= high)
        {
            temp.push_back(nums[right]);
            right++;
        }

        // Copy back to original array
        for (int i = low; i <= high; i++)
        {
            nums[i] = temp[i - low];
        }
    }

    // Count reverse pairs across [low..mid] and [mid+1..high]
    int countPairs(vector<int> &nums, int low, int mid, int high)
    {
        int cnt = 0;
        int j = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (j <= high && (long long)nums[i] > 2LL * nums[j])
                j++;
            cnt += j - (mid + 1);
        }
        return cnt;
    }

    // Modified merge sort: counts reverse pairs
    int mergeSort(vector<int> &nums, int low, int high)
    {
        int cnt = 0;
        if (low >= high)
            return cnt;

        int mid = (low + high) / 2;

        cnt += mergeSort(nums, low, mid);        // Left half
        cnt += mergeSort(nums, mid + 1, high);   // Right half
        cnt += countPairs(nums, low, mid, high); // Count cross pairs

        merge(nums, low, mid, high); // Merge halves
        return cnt;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};
