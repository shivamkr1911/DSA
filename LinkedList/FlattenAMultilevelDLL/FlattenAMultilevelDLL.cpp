#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        // If list is empty, return as is
        if (head == NULL)
            return head;

        Node *curr = head;

        // Traverse the list
        while (curr != NULL)
        {
            // If current node has a child, we need to flatten it
            if (curr->child != NULL)
            {
                Node *nextNode = curr->next;       // Store the next node
                curr->next = flatten(curr->child); // Flatten child list and attach
                curr->next->prev = curr;           // Update prev pointer
                curr->child = NULL;                // Remove child pointer

                // Move to the end of the flattened child list
                while (curr->next != NULL)
                {
                    curr = curr->next;
                }

                // Connect the saved next node back
                if (nextNode != NULL)
                {
                    curr->next = nextNode;
                    nextNode->prev = curr;
                }
            }
            // Move forward in the list
            curr = curr->next;
        }

        return head; // Return updated head of the flattened list
    }
};
