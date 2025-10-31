#include <bits/stdc++.h>
using namespace std;

// ================= Optimal Solution - Using Math (Sum + Sum of Squares) =================
class Solution1
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {

        int n = nums.size() - 2; // array contains 0..n-1 with 2 numbers repeated

        long long actualSum = 0, actualSqSum = 0;

        long long expSum = 1LL * (n - 1) * n / 2;                 // expected sum of 0..n-1
        long long expSqSum = 1LL * (n - 1) * n * (2 * n - 1) / 6; // expected square sum

        for (int x : nums)
        { // compute actual sums
            actualSum += x;
            actualSqSum += 1LL * x * x;
        }

        long long S1 = actualSum - expSum;     // a + b
        long long S2 = actualSqSum - expSqSum; // a^2 + b^2

        long long ab = (S1 * S1 - S2) / 2; // ab using identity

        long long D = sqrt(S1 * S1 - 4 * ab); // discriminant

        long long a = (S1 + D) / 2; // repeated number 1
        long long b = (S1 - D) / 2; // repeated number 2

        return {(int)a, (int)b};
    }
};

// ================= Optimal Solution (Alternative) - Using Sign Marking =================
class Solution2
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        int n = nums.size() - 2;
        vector<int> ans;

        for (int x : nums)
        {
            int idx = x % n; // map number to index
            nums[idx] += n;  // mark occurrence

            if (nums[idx] >= 2 * n) // seen twice
                ans.push_back(idx);
        }
        return ans;
    }
};

// ================= Brute Force Solution - Using Sort =================

class Solution3
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> ans;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1]) // duplicate found
                ans.push_back(nums[i]);
        }
        return ans;
    }
};

// ================= Brute Force Solution - Using Map =================
class Solution4
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        map<int, int> mpp;
        vector<int> ans;

        for (int x : nums)
        {
            if (mpp[x] > 0) // already seen → duplicate
                ans.push_back(x);
            else
                mpp[x]++;
        }
        return ans;
    }
};
