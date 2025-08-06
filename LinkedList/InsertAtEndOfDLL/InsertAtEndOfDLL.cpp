#include <bits/stdc++.h>
using namespace std;

// Definition of doubly linked list node
struct Node
{
    int value;
    Node *prev;
    Node *next;
    Node() : value(0), prev(nullptr), next(nullptr) {}
    Node(int val) : value(val), prev(nullptr), next(nullptr) {}
    Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
};

class Solution
{
public:
    Node *insertAtTail(Node *head, int k)
    {
        // If list is empty, new node becomes head
        if (head == NULL)
            return new Node(k);

        // Traverse to the last node
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        // Create new tail node and link it
        Node *newTail = new Node(k, temp, NULL);
        temp->next = newTail;

        // Return updated head
        return head;
    }
};
