#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
private:
    int findLen(Node *slow, Node *fast)
    {
        int cnt = 1;       // count starts at 1
        fast = fast->next; // move one step
        while (fast != slow)
        {                      // until meet again
            cnt++;             // increase count
            fast = fast->next; // move forward
        }
        return cnt; // return length
    }

public:
    int lengthOfLoop(Node *head)
    {
        // Optimal: Tortoise & Hare
        Node *slow = head; // slow pointer
        Node *fast = head; // fast pointer
        while (fast && fast->next)
        {
            slow = slow->next;       // move 1 step
            fast = fast->next->next; // move 2 steps
            if (slow == fast)        // loop found
                return findLen(slow, fast);
        }
        return 0; // no loop

        // Brute: Hashing
        /*
        Node* temp = head;              // current node
        unordered_map<Node*, int> mpp;  // visited map
        int cnt = 1;                     // position counter
        while (temp) {
            if (mpp[temp])               // seen before
                return cnt - mpp[temp];  // loop length
            mpp[temp] = cnt;             // mark visited
            cnt++;
            temp = temp->next;           // move next
        }
        return 0; // no loop
        */
    }
};
