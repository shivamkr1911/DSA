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
    Node *segregate(Node *head)
    {
        // Create dummy heads and tails for 0s, 1s, and 2s
        Node *zeroHead = new Node(-1);
        Node *zeroTail = zeroHead;
        Node *oneHead = new Node(-1);
        Node *oneTail = oneHead;
        Node *twoHead = new Node(-1);
        Node *twoTail = twoHead;

        Node *temp = head;
        // Distribute nodes into separate lists
        while (temp != NULL)
        {
            if (temp->data == 0)
            {
                zeroTail->next = temp;
                zeroTail = temp;
            }
            else if (temp->data == 1)
            {
                oneTail->next = temp;
                oneTail = temp;
            }
            else
            {
                twoTail->next = temp;
                twoTail = temp;
            }
            temp = temp->next;
        }

        // Connect all lists together
        zeroTail->next = oneHead->next ? oneHead->next : twoHead->next;
        oneTail->next = twoHead->next;
        twoTail->next = NULL;

        // Get new head and delete dummy nodes
        Node *newHead = zeroHead->next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        return newHead;

        // Brute Force - Count and overwrite
        /*
        int cnt0 = 0, cnt1 = 0, cnt2 = 0; // count occurrences
        Node* temp = head;
        // First pass: count 0s, 1s, and 2s
        while (temp != NULL) {
            if (temp->data == 0) cnt0++;
            else if (temp->data == 1) cnt1++;
            else cnt2++;
            temp = temp->next;
        }
        // Second pass: overwrite node values
        temp = head;
        while (temp != NULL) {
            if (cnt0 > 0) {
                cnt0--;
                temp->data = 0;
            }
            else if (cnt1 > 0) {
                cnt1--;
                temp->data = 1;
            }
            else {
                cnt2--;
                temp->data = 2;
            }
            temp = temp->next;
        }
        return head;
        */
    }
};
