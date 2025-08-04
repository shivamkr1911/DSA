#include <bits/stdc++.h>
using namespace std;

// Linked List Node definition
class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to insert node at the end of the linked list
    Node *insertAtEnd(Node *head, int x)
    {
        if (head == NULL)
            return new Node(x); // If list is empty, new node becomes head

        Node *temp = head;
        while (temp->next != NULL)
        { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = new Node(x); // Link new node at end
        return head;              // Return head of updated list
    }
};
