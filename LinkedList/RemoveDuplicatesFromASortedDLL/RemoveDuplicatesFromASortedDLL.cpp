#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution
{
public:
    Node *removeDuplicates(struct Node *head)
    {
        Node *temp = head;

        // Traverse the list
        while (temp != NULL && temp->next != NULL)
        {
            Node *nextNode = temp->next;

            // Skip and delete all duplicate nodes of current data
            while (nextNode != NULL && temp->data == nextNode->data)
            {
                Node *duplicate = nextNode;
                nextNode = nextNode->next; // move to next distinct node
                delete duplicate;          // free memory of duplicate
            }

            // Connect current node to next distinct node
            temp->next = nextNode;
            if (nextNode)
                nextNode->prev = temp;

            // Move forward
            temp = temp->next;
        }
        return head; // return updated head
    }
};
