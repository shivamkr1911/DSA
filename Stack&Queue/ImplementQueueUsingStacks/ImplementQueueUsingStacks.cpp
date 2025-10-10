#include <bits/stdc++.h>
using namespace std;

// ================== Implement Queue Using Two Stacks ==================
// -------- Approach 2 (Efficient Approach) --------
// Time Complexity:
//   push() -> O(1)
//   pop()  -> Amortized O(1)
//   peek() -> Amortized O(1)
// Space Complexity: O(n)

class MyQueue1
{
    stack<int> s1; // Stack for incoming elements
    stack<int> s2; // Stack for outgoing elements
public:
    MyQueue1()
    {
        // Constructor: nothing special to initialize
    }

    // Push element x to the back of queue
    void push(int x)
    {
        s1.push(x); // Always push into s1
    }

    // Removes the element from the front of queue and returns it
    int pop()
    {
        // If s2 is not empty, its top is the front element
        if (!s2.empty())
        {
            int frontVal = s2.top();
            s2.pop();
            return frontVal;
        }
        // Otherwise, move all elements from s1 to s2 to reverse order
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            int frontVal = s2.top(); // Now s2.top() is the front element
            s2.pop();
            return frontVal;
        }
    }

    // Get the front element without removing it
    int peek()
    {
        // If s2 is not empty, top of s2 is the front element
        if (!s2.empty())
            return s2.top();
        // Otherwise, transfer all elements from s1 to s2
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }

    // Returns whether the queue is empty
    bool empty()
    {
        return (s1.empty() && s2.empty());
    }
};

// -------- Approach 1 (Less Efficient Approach) --------

class MyQueue2
{
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue2()
    {
        // Constructor: nothing special to initialize
    }

    // Push element x to the back of queue
    void push(int x)
    {
        // Move all elements from s1 to s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element into s1
        s1.push(x);

        // Move everything back to s1 to maintain queue order
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Removes the element from the front of queue and returns it
    int pop()
    {
        int frontVal = s1.top();
        s1.pop();
        return frontVal;
    }

    // Get the front element without removing it
    int peek()
    {
        return s1.top();
    }

    // Returns whether the queue is empty
    bool empty()
    {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
