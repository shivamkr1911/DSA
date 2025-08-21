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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Optimal Solution
        if (head == NULL || head->next == NULL)
            return NULL; // Single node case

        ListNode *fast = head;
        int i = 0;
        // Move fast pointer n steps ahead
        while (i < n)
        {
            fast = fast->next;
            i++;
        }

        // If fast becomes NULL, remove head
        if (fast == NULL)
        {
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }

        ListNode *slow = head;
        // Move both until fast reaches last node
        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete nth node from end
        ListNode *deletingNode = slow->next;
        slow->next = slow->next->next;
        delete deletingNode;

        return head;

        // Brute Force
        /*
        ListNode* temp = head;
        int totalNodes = 0;

        // Count total nodes
        while (temp != NULL) {
            totalNodes++;
            temp = temp->next;
        }

        // If deleting first node
        if (n == totalNodes) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int m = totalNodes - n;
        temp = head;

        // Reach (total-n)th node
        while (temp != NULL) {
            m--;
            if (m == 0) break;
            temp = temp->next;
        }

        // Delete nth node from end
        ListNode* deletingNode = temp->next;
        temp->next = temp->next->next;
        delete deletingNode;

        return head;
        */
    }
};
