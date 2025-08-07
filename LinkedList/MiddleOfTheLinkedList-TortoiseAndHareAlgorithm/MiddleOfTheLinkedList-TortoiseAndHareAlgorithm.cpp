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
    ListNode *middleNode(ListNode *head)
    {
        // Tortoise And Hare Algorithm
        // Optimal - TC = O(n/2)

        ListNode *slow = head; // moves one step
        ListNode *fast = head; // moves two steps
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;       // move slow by 1
            fast = fast->next->next; // move fast by 2
        }
        return slow; // slow will be at middle

        /*
        TC = O(n + n/2)

        int cnt = 0;
        ListNode* temp = head;  // to count total nodes
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        int mid = (cnt / 2) + 1;  // find middle position
        temp = head;
        while (temp != NULL) {
            mid--;              // move to mid-th node
            if (mid == 0)
                break;
            temp = temp->next;
        }
        return temp;  // return mid node
        */
    }
};
