#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // -------------------- Optimal Solution --------------------

        // Step 1: Insert copy nodes next to original nodes
        Node *temp = head;
        while (temp != NULL)
        {
            Node *copyNode = new Node(temp->val); // create a copy of current node
            copyNode->next = temp->next;          // link copy node to next
            temp->next = copyNode;                // insert copy node after original
            temp = temp->next->next;              // move to next original node
        }

        // Step 2: Assign random pointers for copied nodes
        temp = head;
        while (temp != NULL)
        {
            Node *copyNode = temp->next;
            if (temp->random != NULL)
                copyNode->random = temp->random->next; // set random for copy
            else
                copyNode->random = NULL; // no random link
            temp = temp->next->next;     // move to next original node
        }

        // Step 3: Separate original list and copied list
        temp = head;
        Node *dummyNode = new Node(-1); // dummy node for new list
        Node *res = dummyNode;          // pointer to build copied list

        while (temp != NULL)
        {
            res->next = temp->next;        // attach copied node to result
            temp->next = temp->next->next; // restore original list
            res = res->next;               // move result pointer
            temp = temp->next;             // move original pointer
        }

        Node *newHead = dummyNode->next; // head of copied list
        delete dummyNode;                // free dummy node
        return newHead;

        // -------------------- Brute Force Solution --------------------
        /*
        // Step 1: Create a mapping from original to copied nodes
        Node* temp = head;
        map<Node*, Node*> mpp;
        while (temp != NULL) {
            Node* newNode = new Node(temp->val); // create copy node
            mpp[temp] = newNode;                 // store mapping
            temp = temp->next;
        }

        // Step 2: Connect next and random pointers using map
        temp = head;
        while (temp != NULL) {
            Node* copyNode = mpp[temp];
            copyNode->next = mpp[temp->next];     // set next
            copyNode->random = mpp[temp->random]; // set random
            temp = temp->next;
        }

        // Return head of copied list
        return mpp[head];
        */
    }
};
