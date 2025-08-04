#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Complete this function
Node *deleteHead(Node *head)
{
    // If list is empty, return NULL
    if (head == NULL)
        return head;

    // Move head to next node
    Node *temp = head;
    head = head->next;

    // Delete old head node
    delete temp;

    // Return new head
    return head;
}
