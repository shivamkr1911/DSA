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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
            return head;

        // Step 1: Find the length of the list and get the tail node
        ListNode *tail = head;
        int len = 1;
        while (tail->next != NULL)
        {
            len++;
            tail = tail->next;
        }

        // Step 2: Reduce k using modulo
        // (rotating by length of list gives the same list)
        k = k % len;
        if (k == 0)
            return head; // No change if k is multiple of len

        // Step 3: Connect tail to head → form a circular linked list
        tail->next = head;

        // Step 4: Find the new tail (node before new head)
        // The new tail will be at index (len - k - 1)
        int last = len - k - 1;
        ListNode *temp = head;
        while (last > 0)
        {
            last--;
            temp = temp->next;
        }

        // Step 5: Break the circle and set new head
        ListNode *newHead = temp->next;
        temp->next = NULL;

        return newHead;
    }
};
