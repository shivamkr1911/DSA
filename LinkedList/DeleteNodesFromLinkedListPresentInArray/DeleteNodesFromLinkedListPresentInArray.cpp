#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list (kept uncommented as you prefer)
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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {

        // Store all values to be removed in an unordered_set for quick lookup
        unordered_set<int> st(nums.begin(), nums.end());

        // Dummy node to handle deletion of head node easily
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        // prev points to the previously kept node, curr traverses the list
        ListNode *prev = dummy;
        ListNode *curr = head;

        // Traverse the linked list
        while (curr != nullptr)
        {

            // If current node's value exists in the set, remove this node
            if (st.count(curr->val))
            {
                prev->next = curr->next; // unlink the node
                curr = curr->next;       // move forward
            }
            else
            {
                // Otherwise, keep this node and move both pointers ahead
                prev = prev->next;
                curr = curr->next;
            }
        }

        // Return the updated head
        return dummy->next;
    }
};
