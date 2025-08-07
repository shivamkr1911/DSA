#include <bits/stdc++.h>
using namespace std;

// Definition for a doubly linked list node
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution
{
public:
    // Function to reverse a doubly linked list
    DLLNode *reverseDLL(DLLNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        DLLNode *curr = head;
        DLLNode *last = nullptr;

        // Swap next and prev for each node to reverse the list
        while (curr != nullptr)
        {
            last = curr->prev;
            curr->prev = curr->next;
            curr->next = last;
            curr = curr->prev;
        }

        // After loop, last points to the node before new head
        return last->prev;
    }
};
