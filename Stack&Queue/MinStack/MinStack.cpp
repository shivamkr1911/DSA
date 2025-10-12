#include <bits/stdc++.h>
using namespace std;

// ================== Min Stack (Space-Optimized Solution) ==================
// This implementation supports push, pop, top, and getMin in O(1) time
// with **O(1) extra space** (no need for storing a min value with every element).

class MinStack1
{
    stack<long long> st;      // Stack to store modified values
    long long mini = INT_MAX; // Keeps track of the minimum element

public:
    MinStack1()
    {
        // Constructor initializes an empty stack
    }

    void push(int val)
    {
        long long v = val;
        if (st.empty())
        {
            // If stack is empty, push the value and set it as minimum
            st.push(v);
            mini = v;
        }
        else
        {
            if (v > mini)
            {
                // Normal push if value is greater than current minimum
                st.push(v);
            }
            else
            {
                // Store a modified value to encode previous minimum
                st.push(2 * v - mini);
                // Update the minimum
                mini = v;
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        else
        {
            if (st.top() > mini)
            {
                // If top value is normal, just pop it
                st.pop();
            }
            else
            {
                // If top value was modified, retrieve the previous minimum
                mini = 2 * mini - st.top();
                st.pop();
            }
        }
    }

    int top()
    {
        // Returns the top element (decoded if modified)
        if (st.top() > mini)
            return st.top();
        else
            return mini;
    }

    int getMin()
    {
        // Returns the current minimum element in the stack
        return mini;
    }
};

// ================== Alternate Solution (Using Pair Stack) ==================
// This solution is easier to understand but uses O(n) extra space.

class MinStack2
{
    stack<pair<int, int>> st; // Each element stores {value, current_min}

public:
    MinStack2() {}

    void push(int val)
    {
        if (st.empty())
            st.push({val, val});
        else
            st.push({val, min(val, st.top().second)});
    }

    void pop()
    {
        if (!st.empty())
            st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

/**
 * Example usage:
 *
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int topVal = obj->top();
 * int minVal = obj->getMin();
 */
