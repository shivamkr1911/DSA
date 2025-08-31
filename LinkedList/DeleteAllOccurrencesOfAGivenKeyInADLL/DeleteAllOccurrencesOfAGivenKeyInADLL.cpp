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
        // Start traversing from head
        Node *temp = (*head_ref);

        while (temp != NULL)
        {
            if (temp->data == x)
            { // Found node to delete
                Node *nextNode = temp->next;
                Node *prevNode = temp->prev;

                // Update links of previous and next nodes
                if (nextNode != NULL)
                    nextNode->prev = prevNode;
                if (prevNode != NULL)
                    prevNode->next = nextNode;

                // If deleting head, update head pointer
                if (temp == (*head_ref))
                {
                    (*head_ref) = nextNode;
                }

                // Free memory and move to next node
                delete temp;
                temp = nextNode;
            }
            else
            {
                // Move forward if no deletion
                temp = temp->next;
            }
        }
    }
};
