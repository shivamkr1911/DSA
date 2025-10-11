#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st; // Stack to keep track of opening brackets

        for (auto it : s)
        {
            // If current character is an opening bracket, push to stack
            if (it == '(' || it == '[' || it == '{')
                st.push(it);
            else
            {
                // If stack is empty, there's no matching opening bracket
                if (st.empty())
                    return false;

                char c = st.top(); // Top of stack
                st.pop();          // Pop the opening bracket

                // Check if the popped bracket matches current closing bracket
                if ((it == ')' && c == '(') ||
                    (it == ']' && c == '[') ||
                    (it == '}' && c == '{'))
                    continue; // Match found, continue
                else
                    return false; // Mismatch
            }
        }

        // If stack is empty at the end, all brackets matched
        return st.empty();
    }
};
