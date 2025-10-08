#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

// =============== Stack Implementation Using Linked List ===============
class myStack
{
    Node *top; // Pointer to top element of stack
    int cnt;   // Current size of stack

public:
    // Constructor to initialize stack
    myStack()
    {
        top = NULL; // Stack is initially empty
        cnt = 0;    // Size is 0
    }

    // Check if stack is empty
    bool isEmpty()
    {
        return top == NULL;
    }

    // Push element onto stack
    void push(int x)
    {
        cnt++;                       // Increase size
        Node *newNode = new Node(x); // Create new node
        newNode->next = top;         // Point new node to current top
        top = newNode;               // Update top pointer
    }

    // Pop element from stack
    void pop()
    {
        if (isEmpty())
            return;       // Do nothing if stack is empty
        cnt--;            // Decrease size
        Node *temp = top; // Store current top
        top = top->next;  // Move top pointer
        delete temp;      // Free memory
    }

    // Get the top element of the stack
    int peek()
    {
        if (!isEmpty())
            return top->data; // Return top data if stack not empty
        return -1;            // Return -1 if stack is empty
    }

    // Get current size of stack
    int size()
    {
        return cnt;
    }
};
