#include <bits/stdc++.h>
using namespace std;

// Optimal Solution
class Solution
{
public:
    bool checkKthBit(int n, int k)
    {
        // Shift 1 to the kth position and check if that bit is set in n
        return (n & (1 << k));
    }
};

// Brute Force
/*
class Solution {
  public:
    bool checkKthBit(int n, int k) {
        string s = "";
        // Convert number to binary (stored in reverse order: LSB first)
        while (n > 0) {
            s += (n % 2 == 0) ? '0' : '1';
            n /= 2;
        }
        // If k is out of range, return false
        if (k >= s.size()) return false;
        // Check if kth bit (from right) is '1'
        return s[k] == '1';
    }
};
*/
