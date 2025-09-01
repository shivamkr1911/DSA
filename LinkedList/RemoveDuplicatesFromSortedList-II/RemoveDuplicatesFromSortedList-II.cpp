#include <bits/stdc++.h>
using namespace std;

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        // Base case: if list is empty or has only one node, return as it is
        if (head == NULL || head->next == NULL)
            return head;

        // Dummy node to handle cases where head itself gets deleted
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy; // Pointer to track last confirmed unique node
        ListNode *curr = head;  // Pointer to traverse the list
        prev->next = curr;

        // Traverse the list
        while (curr != NULL && curr->next != NULL)
        {
            // If current node and next node have the same value
            if (curr != NULL && curr->val == curr->next->val)
            {
                int duplicateVal = curr->val; // Store the duplicate value

                // Delete all nodes with this duplicate value
                while (curr != NULL && curr->val == duplicateVal)
                {
                    ListNode *duplicate = curr;
                    curr = curr->next;
                    delete duplicate; // Free memory
                }
                prev->next = curr; // Link last unique node to the next unique node
            }
            else
            {
                // If no duplicate, move prev and curr one step forward
                prev = curr;
                curr = curr->next;
            }
        }

        // Get the new head (may have changed if original head was duplicate)
        ListNode *newHead = dummy->next;
        delete dummy; // Free dummy node
        return newHead;
    }
};
