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
    // Function to swap every two adjacent nodes in a linked list
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head; // No swap needed if list has 0 or 1 node

        ListNode *first = head;         // points to first node of current pair
        ListNode *second = first->next; // points to second node of current pair
        ListNode *prev = NULL;          // keeps track of previous pair's last node to connect swapped pairs

        while (first != NULL && second != NULL)
        {
            ListNode *third = second->next; // node after current pair (start of next pair)

            // Swap current pair
            second->next = first; // second points to first
            first->next = third;  // first points to the next pair

            // Connect previous pair to current swapped pair
            if (prev != NULL)
                prev->next = second; // previous node points to new head of current pair
            else
                head = second; // update head for the first swap

            // Move prev to the end of the current swapped pair
            prev = first; // first is now at end after swap

            // Move to next pair
            first = third;
            if (third != NULL)
                second = third->next; // second node of next pair
            else
                second = NULL;
        }

        return head; // return new head after all swaps
    }
};
