#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string postToPre(string post_exp)
    {
        stack<string> st; // Stack to store operands/sub-expressions

        for (char c : post_exp)
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

                // Combine into a new prefix expression
                string updated = c + t2 + t1;
                st.push(updated); // Push back the new sub-expression
            }
        }

        // Final element on stack is the full prefix expression
        return st.top();
    }
};
