#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node() : data(0), prev(nullptr), next(nullptr) {}
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    Node(int val, Node *p, Node *n) : data(val), prev(p), next(n) {}
};

Node *deleteLastNode(Node *head)
{
    // If list is empty or has one node
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *temp = head;
    // Traverse to last node
    while (temp->next != NULL)
        temp = temp->next;

    Node *newLast = temp->prev; // Node before last
    newLast->next = NULL;       // Break link to last node
    temp->prev = NULL;          // Clean up backward link
    delete temp;                // Delete last node

    return head; // Return updated head
}
