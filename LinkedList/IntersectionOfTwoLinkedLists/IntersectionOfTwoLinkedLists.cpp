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
private:
    // Move tA ahead by diff and then traverse both till they meet
    ListNode *collisionPoint(ListNode *tA, ListNode *tB, int diff)
    {
        while (diff)
        {
            tA = tA->next;
            diff--;
        }
        while (tA != tB)
        {
            tA = tA->next;
            tB = tB->next;
        }
        return tA; // Intersection point
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // Optimal Solution (Two-pointer approach)
        if (!headA || !headB)
            return NULL;
        ListNode *tempA = headA;
        ListNode *tempB = headB;

        while (tempA != tempB)
        {
            // If end reached, switch to other list
            if (tempA == NULL)
            {
                tempA = headB;
            }
            else
            {
                tempA = tempA->next;
            }

            if (tempB == NULL)
            {
                tempB = headA;
            }
            else
            {
                tempB = tempB->next;
            }
        }
        return tempA; // Intersection node or NULL

        // Length Difference Approach
        /*
        if (!headA || !headB) return NULL;
        int nA = 0, nB = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        // Count length of list A
        while (tempA != NULL) {
            nA++;
            tempA = tempA->next;
        }
        // Count length of list B
        while (tempB != NULL) {
            nB++;
            tempB = tempB->next;
        }

        // Reset pointers
        tempA = headA;
        tempB = headB;

        // Move longer list ahead by length diff
        if (nA > nB) return collisionPoint(tempA, tempB, nA - nB);
        else return collisionPoint(tempB, tempA, nB - nA);
        */

        // Using hashing
        /*
        if (!headA || !headB) return NULL;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        unordered_map<ListNode*, int> mpp;

        // Store all nodes of list A
        while (tempA != NULL) {
            mpp[tempA] = 1;
            tempA = tempA->next;
        }

        // Check if any node of B exists in map
        while (tempB != NULL) {
            if (mpp[tempB] == 1) return tempB;
            tempB = tempB->next;
        }
        return NULL; // No intersection
        */
    }
};
