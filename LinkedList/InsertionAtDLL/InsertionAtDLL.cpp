#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int x)
    {
        data = x;
        next = prev = nullptr;
    }
};

class Solution
{
public:
    Node *addNode(Node *head, int p, int x)
    {
        Node *temp = head;
        int cnt = 0;

        // Traverse to the p-th node
        while (temp != NULL)
        {
            if (cnt == p && temp->next == NULL)
            {
                // Insert at end
                Node *newTail = new Node(x);
                newTail->prev = temp;
                temp->next = newTail;
                return head;
            }
            else if (cnt == p)
            {
                // Insert in middle
                Node *front = temp->next;
                Node *newNode = new Node(x);
                newNode->next = front;
                newNode->prev = temp;
                front->prev = newNode;
                temp->next = newNode;
                return head;
            }
            // Alternate way to handle insertion (combined case)
            // if (cnt == p) {
            //     Node *newNode = new Node(x);
            //     newNode->next = temp->next;
            //     newNode->prev = temp;
            //     if (temp->next != NULL) {
            //         temp->next->prev = newNode;
            //     }
            //     temp->next = newNode;
            //     return head;
            // }
            cnt++;
            temp = temp->next;
        }

        // In case p is invalid (greater than list size)
        return head;
    }
};
