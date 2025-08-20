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
    ListNode *oddEvenList(ListNode *head)
    {
        // Optimal Solution
        if (head == NULL || head->next == NULL)
            return head; // Edge case: list with 0 or 1 node

        ListNode *odd = head;        // Pointer for odd-indexed nodes
        ListNode *even = head->next; // Pointer for even-indexed nodes
        ListNode *evenHead = even;   // Store head of even list to connect later

        // Rearrange nodes by adjusting next pointers
        while (even != NULL && even->next != NULL)
        {
            odd->next = odd->next->next;   // Link next odd node
            odd = odd->next;               // Move odd pointer forward
            even->next = even->next->next; // Link next even node
            even = even->next;             // Move even pointer forward
        }

        odd->next = evenHead; // Connect end of odd list to head of even list
        return head;          // Return rearranged list

        // Brute Force
        /*
        if (head == NULL || head->next == NULL) return head; // Edge case

        vector<int> values;           // To store rearranged values
        ListNode* temp = head;

        // Collect odd-positioned node values
        while (temp != NULL && temp->next != NULL) {
            values.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp) values.push_back(temp->val); // If last odd node exists

        // Collect even-positioned node values
        temp = head->next;
        while (temp != NULL && temp->next != NULL) {
            values.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp) values.push_back(temp->val); // If last even node exists

        // Rewrite linked list with new order
        temp = head;
        int i = 0;
        while (temp != NULL) {
            temp->val = values[i];
            temp = temp->next;
            i++;
        }
        return head;
        */
    }
};
