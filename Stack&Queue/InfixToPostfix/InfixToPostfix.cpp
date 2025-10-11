#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to return precedence of operators
    int priority(char c)
    {
        if (c == '^') // Highest precedence
            return 3;
        else if (c == '/' || c == '*') // Medium precedence
            return 2;
        else if (c == '+' || c == '-') // Lowest precedence
            return 1;
        else
            return -1; // Non-operator
    }

public:
    string infixToPostfix(string &s)
    {
        int n = s.size();
        int i = 0;
        stack<char> st; // Stack to store operators and parentheses
        string ans;     // Resultant postfix expression

        while (i < n)
        {
            if (isalnum(s[i]))
            {
                // If operand, add to output
                ans += s[i];
            }
            else if (s[i] == '(')
            {
                // If '(', push to stack
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                // If ')', pop until '(' is found
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop(); // Pop '('
            }
            else
            {
                // Operator encountered
                while (!st.empty() &&
                       (priority(s[i]) < priority(st.top()) ||
                        (priority(s[i]) == priority(st.top()) && s[i] != '^')))
                {
                    // Pop operators with higher or equal precedence (except '^' which is right-associative)
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]); // Push current operator
            }
            i++;
        }

        // Pop remaining operators from stack
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
