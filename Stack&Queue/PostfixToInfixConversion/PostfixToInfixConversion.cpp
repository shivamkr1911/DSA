#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string postToInfix(string exp)
    {
        int n = exp.size();
        stack<string> st; // Stack to store operands/sub-expressions

        for (char c : exp)
        {
            if (isalnum(c))
            {
                // If operand, push it as a string onto the stack
                st.push(string(1, c));
            }
            else
            {
                // If operator, pop two operands from stack
                string t1 = st.top();
                st.pop(); // Right operand
                string t2 = st.top();
                st.pop(); // Left operand

                // Combine into a new infix expression with parentheses
                string updated = "(" + t2 + c + t1 + ")";
                st.push(updated); // Push back the new sub-expression
            }
        }

        // Final element on stack is the full infix expression
        return st.top();
    }
};
