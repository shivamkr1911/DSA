#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // Using Tortoise & Hare Algorithm (Floyd’s Cycle Detection)
        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Detect if a cycle exists
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;       // move slow by 1 step
            fast = fast->next->next; // move fast by 2 steps
            if (slow == fast)
            { // cycle detected
                // Step 2: Find entry point of the cycle
                slow = head; // reset slow to head
                while (slow != fast)
                { // move both one step at a time
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // first node of the cycle
            }
        }
        return NULL; // no cycle

        // Brute Force - Using Hashing
        /*
        ListNode* temp = head;
        unordered_map<ListNode*, int> mpp;

        // Traverse list and mark visited nodes
        while (temp != NULL) {
            if (mpp[temp] == 1)
                return temp;   // cycle detected, return node
            mpp[temp] = 1;     // mark node as visited
            temp = temp->next;
        }
        return NULL;  // no cycle
        */
    }
};
