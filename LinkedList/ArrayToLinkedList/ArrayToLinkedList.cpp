#include <bits/stdc++.h>
using namespace std;

// Node class definition
class Node
{
public:
    int data;
    Node *next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterized constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Solution
{
public:
    Node *constructLL(vector<int> &arr)
    {
        // Create head node with first element
        Node *head = new Node(arr[0]);
        Node *mover = head;

        // Iterate over remaining elements to build the list
        for (int i = 1; i < arr.size(); ++i)
        {
            Node *temp = new Node(arr[i]); // Create new node
            mover->next = temp;            // Link new node to current list
            mover = temp;                  // Move pointer to the new node
        }
        return head; // Return head of the linked list
    }
};
