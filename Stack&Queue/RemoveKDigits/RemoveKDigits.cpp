#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        stack<char> st;

        // Traverse each digit of the number
        for (int i = 0; i < n; ++i)
        {
            // Remove digits from stack while:
            // 1. We still have digits to remove (k > 0)
            // 2. Current digit is smaller than top of stack (to form a smaller number)
            while (!st.empty() && k > 0 && num[i] < st.top())
            {
                st.pop();
                k--;
            }
            // Push current digit to stack
            st.push(num[i]);
        }

        // If there are still digits left to remove, pop from the end
        while (k > 0 && !st.empty())
        {
            st.pop();
            k--;
        }

        // If stack becomes empty, the smallest number is 0
        if (st.empty())
            return "0";

        // Build the result string from stack (reverse order)
        string ans = "";
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        // Remove leading zeros (which are at the back before reversing)
        while (!ans.empty() && ans.back() == '0')
            ans.pop_back();

        // Reverse to get the correct order
        reverse(ans.begin(), ans.end());

        // If string becomes empty after removing zeros, return "0"
        if (ans.empty())
            return "0";

        return ans;
    }
};
