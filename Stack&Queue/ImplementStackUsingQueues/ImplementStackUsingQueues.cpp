#include <bits/stdc++.h>
using namespace std;

// ================== Implement Stack Using Single Queue ==================
class MyStack
{
    queue<int> q; // Underlying queue to simulate stack
public:
    MyStack()
    {
        // Constructor: nothing to initialize explicitly
    }

    // Push element x onto stack
    void push(int x)
    {
        int s = q.size(); // Current size of queue
        q.push(x);        // Push x at the back of the queue

        // Rotate the queue to make the newly added element at the front
        for (int i = 0; i < s; i++)
        {
            q.push(q.front()); // Move front element to back
            q.pop();           // Remove it from front
        }
    }

    // Removes the element on top of the stack and returns it
    int pop()
    {
        if (q.empty())
            return -1;          // Stack is empty
        int topVal = q.front(); // Top element is at the front of queue
        q.pop();                // Remove it
        return topVal;
    }

    // Get the top element without removing it
    int top()
    {
        if (q.empty())
            return -1;    // Stack is empty
        return q.front(); // Front of queue is top of stack
    }

    // Returns whether the stack is empty
    bool empty()
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
