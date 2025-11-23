#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
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
    // Compute GCD using iterative Euclidean algorithm
    int findGCD(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *temp = head;

        // Traverse the list and insert GCD node between every adjacent pair
        while (temp != NULL && temp->next != NULL)
        {

            ListNode *nextNode = temp->next; // node after current one
            int a = temp->val;
            int b = nextNode->val;

            int gcd = findGCD(a, b); // compute GCD of two values

            // Insert new GCD node between temp and nextNode
            temp->next = new ListNode(gcd, nextNode);

            // Move to the next original node
            temp = temp->next->next;
        }

        return head;
    }
};
