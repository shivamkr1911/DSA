#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution (Recursive Approach) ===============
class Solution1
{
private:
    // Function to invert a bit ('1' -> '0', '0' -> '1')
    char inverted(char c)
    {
        return c == '1' ? '0' : '1';
    }

public:
    // Function to find the k-th bit in n-th binary string (S_n)
    char findKthBit(int n, int k)
    {
        if (n == 1)
            return '0'; // Base case: S1 = "0"

        int mid = (1 << (n - 1)); // Middle position in Sn (2^(n-1))

        if (k == mid)
            return '1'; // Middle element is always '1'

        if (k < mid)
            return findKthBit(n - 1, k); // Left half is same as S_(n-1)

        // For right half -> inverted(reverse(S_(n-1)))
        // The sum of an index and its mirror is always 2^n.
        int mirror_k = (1 << n) - k; // Mirror position in left half (2^n - k)
        return inverted(findKthBit(n - 1, mirror_k));
    }
};

// =============== Brute Force Solution (String Construction) ===============
class Solution2
{
private:
    // Function to invert and reverse a binary string
    string invertAndReverse(string s)
    {
        // Invert bits
        for (char &c : s)
        {
            c = (c == '0' ? '1' : '0');
        }

        // Reverse the string
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }

public:
    // Function to build S_n and return k-th bit
    char findKthBit(int n, int k)
    {
        string s = "0"; // S1 = "0"

        // Construct strings iteratively:
        // S_i = S_(i-1) + "1" + invert(reverse(S_(i-1)))
        for (int i = 1; i < n; ++i)
        {
            string part3 = invertAndReverse(s); // Create the right half
            s = s + "1" + part3;                // Combine parts
        }

        // Return k-th bit (1-indexed)
        return s[k - 1];
    }
};
