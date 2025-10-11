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
        return -1; // Non-operator
    }

    // Function to reverse a string and swap parentheses
    string reverse(string &s)
    {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j)
        {
            swap(s[i], s[j]); // Reverse the string
            i++;
            j--;
        }

        // Swap '(' with ')' and vice versa
        for (char &c : s)
        {
            if (c == '(')
                c = ')';
            else if (c == ')')
                c = '(';
        }
        return s;
    }

public:
    string infixToPrefix(string &s)
    {
        int n = s.size();
        int i = 0;
        stack<char> st; // Stack to store operators and parentheses
        string ans;     // Resultant prefix expression

        reverse(s); // Reverse infix expression and swap parentheses

        while (i < n)
        {
            if (isalnum(s[i]))
            {
                // If operand, add to output
                ans += s[i];
            }
            else if (s[i] == '(')
            {
                // Push '(' to stack
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                // Pop until '(' is found
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
                       ((s[i] != '^' && priority(s[i]) < priority(st.top())) ||
                        (s[i] == '^' && priority(s[i]) <= priority(st.top()))))
                {
                    // Pop operators with higher or equal precedence (handle '^' as right-associative)
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

        reverse(ans); // Reverse the result to get correct prefix expression
        return ans;
    }
};
