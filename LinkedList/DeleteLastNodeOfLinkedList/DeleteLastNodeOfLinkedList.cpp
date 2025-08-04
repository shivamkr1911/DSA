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
        next = NULL;
    }
};

class Solution
{
public:
    Node *deleteLastNode(Node *head)
    {
        // If list is empty or has only one node
        if (head == NULL || head->next == NULL)
        {
            free(head);
            return NULL;
        }

        Node *temp = head;

        // Traverse to second last node
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        // Delete last node
        free(temp->next);
        temp->next = NULL;

        // Return updated head
        return head;
    }
};
