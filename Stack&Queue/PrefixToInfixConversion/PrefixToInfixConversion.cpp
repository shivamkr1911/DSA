#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string preToInfix(string pre_exp)
    {
        int n = pre_exp.size();
        stack<string> st; // Stack to store operands/sub-expressions
        int i = n - 1;    // Start from the end of the prefix expression

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

                // Combine into a new infix expression with parentheses
                string updated = "(" + t1 + c + t2 + ")";
                st.push(updated); // Push back the new sub-expression
            }

            i--; // Move to previous character
        }

        // Final element on stack is the full infix expression
        return st.top();
    }
};
