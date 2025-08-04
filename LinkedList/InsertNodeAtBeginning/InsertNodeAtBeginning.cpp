#include <bits/stdc++.h>
using namespace std;

// Linked List Node definition
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to insert node at beginning of linked list
    Node *insertAtBegining(Node *head, int x)
    {
        Node *temp = new Node(x); // Create new node
        temp->next = head;        // Link it to current head
        return temp;              // Return new head
    }
};
