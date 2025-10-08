#include <bits/stdc++.h>
using namespace std;

// =============== Queue Implementation Using Circular Array ===============
class myQueue
{
    int *arr;     // Array to store queue elements
    int start;    // Index of front element
    int end;      // Index of rear element
    int capacity; // Maximum capacity of queue
    int currSize; // Current number of elements in queue

public:
    // Constructor to initialize queue
    myQueue(int n)
    {
        capacity = n;     // Set queue capacity
        arr = new int[n]; // Allocate array
        start = -1;       // Initialize start index
        end = -1;         // Initialize end index
        currSize = 0;     // Initialize current size
    }

    // Check if queue is empty
    bool isEmpty()
    {
        return currSize == 0;
    }

    // Check if queue is full
    bool isFull()
    {
        return currSize == capacity;
    }

    // Add element at rear of queue
    void enqueue(int x)
    {
        if (isFull())
            return; // Do nothing if queue is full
        if (start == -1)
            start++;                // Initialize start if queue was empty
        end = (end + 1) % capacity; // Move rear index circularly
        arr[end] = x;               // Insert element at rear
        currSize++;                 // Increase current size
    }

    // Remove element from front of queue
    void dequeue()
    {
        if (isEmpty())
            return;                     // Do nothing if queue is empty
        start = (start + 1) % capacity; // Move front index circularly
        currSize--;                     // Decrease current size
        if (currSize == 0)              // Reset indices if queue becomes empty
        {
            start = -1;
            end = -1;
        }
    }

    // Get the front element of the queue
    int getFront()
    {
        if (!isEmpty())
            return arr[start]; // Return front element
        return -1;             // Return -1 if queue is empty
    }

    // Get the rear element of the queue
    int getRear()
    {
        if (!isEmpty())
            return arr[end]; // Return rear element
        return -1;           // Return -1 if queue is empty
    }
};
