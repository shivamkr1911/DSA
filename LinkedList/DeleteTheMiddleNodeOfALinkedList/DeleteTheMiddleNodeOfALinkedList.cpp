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
    ListNode *deleteMiddle(ListNode *head)
    {
        // Optimal Solution - Tortoise & Hare Algorithm

        // If list has 0 or 1 node, return NULL
        if (head == NULL || head->next == NULL)
            return NULL;

        // If list has exactly 2 nodes, delete the second one
        if (head->next->next == NULL)
        {
            ListNode *middle = head->next;
            head->next = head->next->next; // make head->next = NULL
            delete middle;                 // free memory
            return head;
        }

        // Use slow and fast pointers
        ListNode *slow = head;
        ListNode *fast = head;

        // Move fast two steps ahead to start
        fast = fast->next->next;

        // Move slow by 1, fast by 2 until fast reaches end
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Now slow is just before the middle node
        ListNode *middle = slow->next;
        slow->next = slow->next->next; // remove middle
        delete middle;                 // free memory
        return head;

        // Brute Force Solution
        /*
        // If list has 0 or 1 node, return NULL
        if (head == NULL || head->next == NULL) return NULL;

        // Count total number of nodes
        ListNode* temp = head;
        int totalNodes = 0;
        while (temp != NULL) {
            totalNodes++;
            temp = temp->next;
        }

        // Find index of middle node
        temp = head;
        int req = totalNodes / 2;

        // Move to node just before middle
        while (temp != NULL) {
            req--;
            if (req == 0) break;
            temp = temp->next;
        }

        // Delete middle node
        ListNode* middle = temp->next;
        temp->next = temp->next->next;
        delete middle;
        return head;
        */
    }
};
