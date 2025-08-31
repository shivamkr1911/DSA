#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

class Solution
{
public:
    void deleteAllOccurOfX(struct Node **head_ref, int x)
    {
        // Pointer to traverse the list
        Node *temp = *head_ref;

        while (temp != NULL)
        {
            if (temp->data == x)
            { // Found node to delete
                if (temp == *head_ref)
                { // Node is head
                    if ((*head_ref)->next == NULL)
                    {
                        // Only one node in list
                        delete head_ref;
                        *head_ref = NULL;
                        return;
                    }
                    else
                    {
                        // Head has next node
                        Node *del = temp;
                        *head_ref = (*head_ref)->next; // move head
                        (*head_ref)->prev = NULL;      // update prev of new head
                        temp = *head_ref;              // move temp
                        delete del;                    // free memory
                        continue;                      // continue with new head
                    }
                }

                // Node is in middle or end
                Node *prevNode = temp->prev;
                Node *nextNode = temp->next;

                if (prevNode)
                    prevNode->next = nextNode; // link previous node to next
                if (nextNode)
                    nextNode->prev = prevNode; // link next node to previous

                temp = nextNode; // move temp forward
            }
            else
            {
                temp = temp->next; // move to next node
            }
        }
    }
};
