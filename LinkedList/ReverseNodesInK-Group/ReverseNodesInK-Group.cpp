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
    // Function to get the k-th node from the current head
    ListNode *getKthNode(ListNode *head, int k)
    {
        ListNode *temp = head;
        int cnt = 1;
        // Traverse until the k-th node or end of list
        while (temp != NULL && cnt < k)
        {
            cnt++;
            temp = temp->next;
        }
        // If exactly k nodes are available, return that node
        if (k == cnt)
            return temp;
        return NULL; // Otherwise, return NULL
    }

    // Function to reverse a linked list
    ListNode *reverseLL(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *prev = NULL;
        // Standard iterative reversal
        while (temp != NULL)
        {
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev; // New head after reversal
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        ListNode *prevNode = NULL;

        // Traverse the list in groups of size k
        while (temp != NULL)
        {
            // Find the k-th node from current position
            ListNode *kthNode = getKthNode(temp, k);
            if (kthNode == NULL)
            {
                // If fewer than k nodes remain, just connect and stop
                if (prevNode)
                    prevNode->next = temp;
                break;
            }

            // Store the node after the k-th node
            ListNode *nextNode = kthNode->next;

            // Temporarily cut off the group
            kthNode->next = NULL;

            // Reverse the group starting from temp
            reverseLL(temp);

            // Connect the reversed group to previous part
            if (temp == head)
            {
                head = kthNode; // First group, so update head
            }
            else
            {
                prevNode->next = kthNode;
            }

            // Move prevNode to the end of this reversed group
            prevNode = temp;

            // Continue from the next group
            temp = nextNode;
        }
        return head;
    }
};
