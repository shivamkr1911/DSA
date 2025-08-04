#include <bits/stdc++.h>
using namespace std;

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

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

class Solution
{
public:
    // Function to insert node at given position
    Node *insert(Node *head, int n, int pos, int val)
    {
        // Insert at head if pos is 0
        if (pos == 0)
        {
            Node *newNode = new Node(val);
            newNode->next = head;
            return newNode;
        }

        // Traverse to pos-1 node
        int cnt = 0;
        Node *temp = head;
        while (cnt != pos - 1)
        {
            temp = temp->next;
            cnt++;
        }

        // Insert new node at position
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        // Return updated head
        return head;
    }
};
