#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class Solution
{
public:
    Node *deleteNode(Node *head, int x)
    {
        Node *temp = head;
        int cnt = 0;

        // Traverse to x-th node
        while (temp != NULL)
        {
            cnt++;
            if (cnt == x)
                break;
            temp = temp->next;
        }

        Node *back = temp->prev;
        Node *front = temp->next;

        // Case 1: Only node in list
        if (back == NULL && front == NULL)
            return NULL;

        // Case 2: Deleting head node
        else if (back == NULL)
        {
            head = head->next;
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
            return head;
        }

        // Case 3: Deleting last node
        else if (front == NULL)
        {
            back->next = NULL;
            temp->prev = NULL;
            delete temp;
            return head;
        }

        // Case 4: Deleting middle node
        back->next = front;
        front->prev = back;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;

        return head;
    }
};
