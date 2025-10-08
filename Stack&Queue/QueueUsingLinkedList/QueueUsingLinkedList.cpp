#include <bits/stdc++.h>
using namespace std;

/*
Node definition for linked list based queue
*/
class Node
{
public:
    int data;
    Node *next;

    Node(int new_data)
    {
        data = new_data;
        next = nullptr;
    }
};

// =============== Queue Implementation Using Linked List ===============
class myQueue
{
    Node *start; // Pointer to front of the queue
    Node *end;   // Pointer to rear of the queue
    int cnt;     // Current size of queue

public:
    // Constructor to initialize queue
    myQueue()
    {
        start = NULL; // Queue is initially empty
        end = NULL;
        cnt = 0; // Size is 0
    }

    // Check if queue is empty
    bool isEmpty()
    {
        return cnt == 0;
    }

    // Enqueue element at the rear
    void enqueue(int x)
    {
        Node *newNode = new Node(x); // Create new node
        if (start == NULL)
        {                          // If queue is empty
            start = end = newNode; // Both start and end point to new node
        }
        else
        {
            end->next = newNode; // Link new node at the end
            end = newNode;       // Update end pointer
        }
        cnt++; // Increase size
    }

    // Dequeue element from the front
    void dequeue()
    {
        if (isEmpty())
            return;          // Do nothing if queue is empty
        Node *temp = start;  // Store current front
        start = start->next; // Move front pointer
        delete temp;         // Free memory
        cnt--;               // Decrease size
        if (start == NULL)
            end = NULL; // If queue became empty, reset end pointer
    }

    // Get the front element
    int getFront()
    {
        if (!isEmpty())
            return start->data; // Return front data
        return -1;              // Return -1 if queue is empty
    }

    // Get current size of queue
    int size()
    {
        return cnt;
    }
};
