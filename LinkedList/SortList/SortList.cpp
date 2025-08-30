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
private:
    // Function to find the middle node of the linked list
    ListNode *findMiddle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *slow = head;       // moves one step
        ListNode *fast = head->next; // moves two steps
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // middle node
    }

    // Function to merge two sorted linked lists
    ListNode *mergeSortedLL(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(-1); // dummy node
        ListNode *temp = dummy;
        ListNode *t1 = list1;
        ListNode *t2 = list2;

        // Merge nodes in sorted order
        while (t1 != NULL && t2 != NULL)
        {
            if (t1->val <= t2->val)
            {
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else
            {
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }

        // Attach remaining nodes
        if (t1)
            temp->next = t1;
        else if (t2)
            temp->next = t2;

        ListNode *head = dummy->next;
        delete dummy; // free dummy node
        return head;
    }

public:
    // Main function to sort the linked list using Merge Sort
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        // Split list into two halves
        ListNode *middle = findMiddle(head);
        ListNode *leftHead = head;
        ListNode *rightHead = middle->next;
        middle->next = NULL;

        // Recursively sort both halves
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        // Merge sorted halves
        return mergeSortedLL(leftHead, rightHead);

        // Brute Force Approach (convert to array, sort, and assign back)
        /*
        vector<int> ele;
        ListNode* temp = head;
        while (temp != NULL) {
            ele.push_back(temp->val);
            temp = temp->next;
        }
        sort(ele.begin(), ele.end());
        int i = 0;
        temp = head;
        while (temp != NULL) {
            temp->val = ele[i];
            temp = temp->next;
            i++;
        }
        return head;
        */
    }
};
