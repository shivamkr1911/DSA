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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // Optimal Solution - Two pointer
        ListNode *dummy = new ListNode(-1); // dummy node to build merged list
        ListNode *temp = dummy;
        ListNode *t1 = list1;
        ListNode *t2 = list2;

        // merge while both lists have nodes
        while (t1 != NULL && t2 != NULL)
        {
            if (t1->val <= t2->val)
            {
                temp->next = t1; // link smaller node
                temp = t1;       // move pointer
                t1 = t1->next;
            }
            else
            {
                temp->next = t2; // link smaller node
                temp = t2;
                t2 = t2->next;
            }
        }

        // attach remaining nodes
        if (t1)
            temp->next = t1;
        else if (t2)
            temp->next = t2;

        ListNode *head = dummy->next; // head of merged list
        delete dummy;                 // free dummy
        return head;

        // Brute Force
        /*
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        vector<int> arr;

        // collect all values
        while (temp1 != NULL) {
            arr.push_back(temp1->val);
            temp1 = temp1->next;
        }
        while (temp2 != NULL) {
            arr.push_back(temp2->val);
            temp2 = temp2->next;
        }

        // sort values
        sort(arr.begin(), arr.end());
        if (arr.empty()) return NULL;

        // build new list
        ListNode* head = new ListNode(arr[0]);
        ListNode* mover = head;
        for (int i = 1; i < arr.size(); i++) {
            ListNode* temp = new ListNode(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return head;
        */
    }
};
