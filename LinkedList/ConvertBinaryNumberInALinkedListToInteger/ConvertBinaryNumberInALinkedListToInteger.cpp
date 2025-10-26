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
    int getDecimalValue(ListNode *head)
    {
        int ans = 0;           // Initialize result as 0
        ListNode *temp = head; // Start from the head of the linked list

        while (temp != nullptr)
        {
            ans = (ans << 1) | temp->val; // Shift result left by 1 bit (multiply by 2)
                                          // then add current bit using bitwise OR
            temp = temp->next;            // Move to the next node
        }

        return ans; // Return the computed decimal value
    }
};
