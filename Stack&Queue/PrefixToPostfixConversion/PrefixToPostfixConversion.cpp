#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string preToPost(string pre_exp)
    {
        int n = pre_exp.size();
        int i = n - 1;    // Start from the end of the prefix expression
        stack<string> st; // Stack to store operands/sub-expressions

        while (i >= 0)
        {
            char c = pre_exp[i];

            if (isalnum(c))
            {
                // If operand, push it as a string onto the stack
                st.push(string(1, c));
            }
            else
            {
                // If operator, pop two operands from stack
                string t1 = st.top();
                st.pop(); // Left operand
                string t2 = st.top();
                st.pop(); // Right operand

                // Combine into a new postfix expression
                string updated = t1 + t2 + c;
                st.push(updated); // Push back the new sub-expression
            }

            --i; // Move to the previous character
        }

        // Final element on stack is the full postfix expression
        return st.top();
    }
};
