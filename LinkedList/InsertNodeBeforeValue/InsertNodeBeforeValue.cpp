#include <bits/stdc++.h>
using namespace std;

// Linked List Node definition
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to insert node with value x before node with value val
    Node *insertBeforeValue(Node *head, int x, int val)
    {
        // If the head node has value val
        if (head->data == val)
        {
            Node *temp = new Node(x);
            temp->next = head;
            return temp;
        }

        Node *temp = head;
        // Traverse till node before node with value val
        while (temp->next != NULL && temp->next->data != val)
        {
            temp = temp->next;
        }

        // Insert new node between temp and temp->next
        Node *newNode = new Node(x);
        newNode->next = temp->next;
        temp->next = newNode;

        return head;
    }
};
