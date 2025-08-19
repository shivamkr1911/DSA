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
private:
    ListNode *reverseLL(ListNode *head)
    {
        // Reverse linked list
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *temp = head;
        ListNode *prev = NULL;
        while (temp != NULL)
        {
            ListNode *front = temp->next; // Store next node
            temp->next = prev;            // Reverse link
            prev = temp;                  // Move prev forward
            temp = front;                 // Move temp forward
        }
        return prev; // New head after reverse
    }

public:
    bool isPalindrome(ListNode *head)
    {
        // Edge cases
        if (head == NULL || head->next == NULL)
            return true;

        // Find middle using slow-fast pointer
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse 2nd half
        ListNode *newHead = reverseLL(slow->next);

        // Compare both halves
        ListNode *first = head;
        ListNode *second = newHead;
        while (second != NULL)
        {
            if (first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }

        // Restore list
        reverseLL(newHead);
        return true;

        // Brute Force - Using Stack
        /*
        ListNode* temp = head;
        stack<int> st;
        while (temp != NULL) {
            st.push(temp->val); // Push all values
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL) {
            if (temp->val != st.top()) return false;
            temp = temp->next;
            st.pop();
        }
        return true;
        */
    }
};
