#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *deleteXthNode(Node *head, int x)
    {
        // If head node is to be deleted
        if (x == 1)
        {
            Node *temp = head;
            head = head->next;
            free(temp);
            return head;
        }

        int cnt = 0;
        Node *temp = head;
        Node *prev = NULL;

        // Traverse to the x-th node
        while (temp != NULL)
        {
            cnt++;
            if (cnt == x)
            {
                prev->next = prev->next->next; // Unlink node
                free(temp);                    // Delete node
                break;
            }
            prev = temp;
            temp = temp->next;
        }

        // Return updated head
        return head;
    }
};
