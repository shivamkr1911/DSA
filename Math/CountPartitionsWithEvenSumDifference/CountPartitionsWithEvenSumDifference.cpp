#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution — O(n) ===============
class Solution1
{
public:
    int countPartitions(vector<int> &nums)
    {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0); // total sum of array

        // If total sum is even, every index except the last can be a valid cut
        // because a cut only needs non-empty left & right partitions
        return (total % 2 == 0) ? n - 1 : 0;
    }
};

// =============== Solution O(2n) ===============
class Solution2
{
public:
    int countPartitions(vector<int> &nums)
    {
        int total = accumulate(nums.begin(), nums.end(), 0); // full sum
        int sum = 0;
        int cnt = 0; // count of valid partitions

        // We only iterate until second last element because both parts must be non-empty
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            sum += nums[i];   // left partition prefix sum
            total -= nums[i]; // remaining part becomes right partition

            // Valid if |left - right| is even → both sums have same parity
            if (abs(total - sum) % 2 == 0)
                cnt++;
        }
        return cnt;
    }
};
