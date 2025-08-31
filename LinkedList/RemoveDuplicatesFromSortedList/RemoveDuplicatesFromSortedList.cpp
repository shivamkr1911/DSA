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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *temp = head;

        // Traverse the list
        while (temp != NULL && temp->next != NULL)
        {
            ListNode *nextNode = temp->next;

            // Skip and delete duplicate nodes with same value
            while (nextNode != NULL && temp->val == nextNode->val)
            {
                ListNode *duplicate = nextNode;
                nextNode = nextNode->next; // move to next distinct node
                delete duplicate;          // free memory of duplicate node
            }

            // Connect current node to next distinct node
            temp->next = nextNode;

            // Move forward
            temp = temp->next;
        }
        return head; // return updated head pointer
    }
};
