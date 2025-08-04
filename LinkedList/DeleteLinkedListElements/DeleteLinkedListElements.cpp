#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteElements(ListNode *head, int val)
    {
        // Skip initial nodes with value == val
        while (head != NULL && head->val == val)
        {
            head = head->next;
        }

        ListNode *temp = head;
        ListNode *prev = NULL;

        // Traverse and remove nodes with value == val
        while (temp != NULL)
        {
            if (temp->val == val)
            {
                prev->next = temp->next; // Delete current node
                temp = temp->next;       // Move temp ahead, keep prev same
            }
            else
            {
                prev = temp;       // Move prev ahead
                temp = temp->next; // Move temp ahead
            }
        }

        return head; // Return updated head
    }
};
