#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        // Copy value from next node
        node->val = node->next->val;

        // Store next node to delete it
        ListNode *temp = node->next;

        // Bypass next node
        node->next = node->next->next;

        // Delete the skipped node
        delete temp;
    }
};
