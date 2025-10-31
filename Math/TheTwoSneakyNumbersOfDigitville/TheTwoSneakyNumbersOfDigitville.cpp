#include <bits/stdc++.h>
using namespace std;

// ================= Optimal Solution (O(N) Time, O(1) Space) =================
// Solution 1 - Using Math (Sum + Sum of Squares)
class Solution1
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        // 'n' is the range of numbers (0...n-1), not the array size
        int n = nums.size() - 2;

        // Calculate expected sum of (0...n-1)
        long long expSum = (long long)(n - 1) * n / 2;
        // Calculate expected sum of squares (0^2... (n-1)^2)
        long long expSqSum = (long long)(n - 1) * n * (2 * n - 1) / 6;

        // Calculate the actual sum and sum of squares from the input array
        long long actualSum = 0, actualSqSum = 0;
        for (int x : nums)
        {
            actualSum += x;
            actualSqSum += (long long)x * x; // Use long long for multiplication
        }

        // S1 is the sum of the two duplicates (a + b)
        long long S1 = actualSum - expSum;
        // S2 is the sum of the squares of the two duplicates (a^2 + b^2)
        long long S2 = actualSqSum - expSqSum;

        // Find the product of the duplicates (a * b) using (a+b)^2 = a^2 + b^2 + 2ab
        long long ab = (S1 * S1 - S2) / 2;

        // Solve the quadratic equation: x^2 - (a+b)x + ab = 0
        // Find the discriminant (D) to use in the quadratic formula
        long long D = sqrt(S1 * S1 - 4 * ab);

        // Calculate the two roots, which are our duplicate numbers
        long long a = (S1 + D) / 2;
        long long b = (S1 - D) / 2;

        return {(int)a, (int)b};
    }
};

// ================= Optimal Solution (O(N) Time, O(1) Space) =================
// Solution 2 - Using In-Place Array Marking
class Solution2
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        // n is the range 0...n-1, NOT the size of nums
        int n = nums.size() - 2;
        vector<int> ans;

        // Iterate through the array
        for (int x : nums)
        {
            // Get the original value (which is also the index to mark)
            // We use % n in case this element has already been marked
            int idx = x % n;

            // Mark the index by adding n. This acts as a counter.
            nums[idx] += n;

            // If we've added n twice, the value will be >= 2*n
            // (value is in range [0, n-1], so 1st add is < 2*n, 2nd add is >= 2*n)
            if (nums[idx] / n == 2)
            {
                ans.push_back(idx);
            }
        }
        return ans;
    }
};

// ================= O(N log N) Solution (Sorting) =================
// Solution 3 - Using Sort
class Solution3
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;

        // Sort the array, which brings duplicates next to each other
        sort(nums.begin(), nums.end());

        // Iterate and find adjacent identical numbers
        for (int i = 1; i < n; ++i)
        {
            if (nums[i - 1] == nums[i])
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

// ================= Standard Solution (O(N) Time, O(N) Space) =================
// Solution 4 - Using Map
class Solution4
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        // Use a map (or unordered_map for O(N) avg) to store frequency
        map<int, int> mpp;
        vector<int> ans;

        // Iterate through all numbers
        for (int i : nums)
        {
            // Increment the count for this number
            mpp[i]++;

            // If the count is exactly 2, we found a duplicate
            if (mpp[i] == 2)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
