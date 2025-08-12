#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
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
    ListNode *reverseList(ListNode *head)
    {
        // Recursive Solution
        if (head == NULL || head->next == NULL) // base case: empty list or single node
            return head;
        ListNode *newHead = reverseList(head->next); // reverse rest of the list
        ListNode *front = head->next;                // store next node
        front->next = head;                          // make next node point back to current
        head->next = NULL;                           // break original link
        return newHead;                              // return new head of reversed list

        // Iterative Solution
        /*
        ListNode* temp = head;        // current node
        ListNode* prev = NULL;        // previous node (initially NULL)
        while (temp != NULL) {
            ListNode* front = temp->next; // store next node
            temp->next = prev;           // reverse link
            prev = temp;                 // move prev forward
            temp = front;                // move current forward
        }
        return prev;                    // prev is new head after loop
        */
    }
};
