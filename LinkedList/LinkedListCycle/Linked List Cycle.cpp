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
    bool hasCycle(ListNode *head)
    {
        // Using Tortoise & Hare Algorithm
        ListNode *slow = head;
        ListNode *fast = head;

        // Move slow by 1 and fast by 2 steps
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            // Cycle detected if pointers meet
            if (fast == slow)
                return true;
        }
        return false; // No cycle found

        // Brute Force - Using Hashing
        /*
        ListNode* temp = head;
        unordered_map<ListNode*, int> mpp;

        // Check if node already visited
        while (temp != NULL) {
            if (mpp[temp] == 1)
                return true;
            mpp[temp] = 1;
            temp = temp->next;
        }
        return false; // No cycle found
        */
    }
};
