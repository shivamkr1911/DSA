#include <bits/stdc++.h>
using namespace std;

// =============== Stack Implementation Using Array ===============
class myStack
{
    int *arr;     // Array to store stack elements
    int top;      // Index of the top element
    int capacity; // Maximum capacity of stack

public:
    // Constructor to initialize stack
    myStack(int n)
    {
        capacity = n;     // Set stack capacity
        arr = new int[n]; // Allocate array
        top = -1;         // Initialize top as -1 (empty stack)
    }

    // Check if stack is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // Check if stack is full
    bool isFull()
    {
        return top == capacity - 1;
    }

    // Push element onto stack
    void push(int x)
    {
        if (!isFull()) // Only push if stack is not full
        {
            top++;        // Increment top index
            arr[top] = x; // Add element at top
        }
    }

    // Pop element from stack
    void pop()
    {
        if (!isEmpty()) // Only pop if stack is not empty
        {
            top--; // Decrement top index
        }
    }

    // Get the top element of the stack
    int peek()
    {
        if (!isEmpty())
        {
            return arr[top]; // Return element at top
        }
        return -1; // Return -1 if stack is empty
    }
};
