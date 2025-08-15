#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
private:
    // Helper function for recursion
    // Traverses to the last node and starts adding 1 while backtracking
    int carryHelper(Node *temp)
    {
        // Base case: when we reach NULL, return carry = 1 (adding one to the last node)
        if (temp == NULL)
            return 1;

        // Recursive call to reach the end of the list
        int carry = carryHelper(temp->next);

        // Add carry to current node's data
        temp->data = temp->data + carry;

        // If no carry is generated after addition, return 0
        if (temp->data < 10)
            return 0;

        // If data >= 10, set current node's value to 0 and pass carry = 1
        temp->data = 0;
        return 1;
    }

    // Helper function to reverse a linked list
    Node *reverseLL(Node *head)
    {
        // Base case: if list is empty or has one node
        if (!head || !head->next)
            return head;

        // Reverse the rest of the list
        Node *newHead = reverseLL(head->next);

        // Rearrange pointers
        Node *front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }

public:
    Node *addOne(Node *head)
    {
        // ********** Recursive Approach **********
        // Carry will store whether we need to insert a new node at the beginning
        int carry = carryHelper(head);

        // If carry is still 1 after processing entire list,
        // it means we need to add a new node with value 1 at the start
        if (carry == 1)
        {
            Node *newHead = new Node(1);
            newHead->next = head;
            return newHead;
        }
        return head;

        // ********** Iterative Approach **********
        /*
        // Step 1: Reverse the linked list to make addition easier (start from least significant digit)
        head = reverseLL(head);

        int carry = 1; // Since we want to add one
        Node* temp = head;

        // Step 2: Traverse and add carry
        while (temp != NULL) {
            temp->data = temp->data + carry;

            if (temp->data < 10) {
                carry = 0; // No further carry needed
                break;
            }
            else {
                temp->data = 0; // Reset current node value to 0
                carry = 1;      // Carry forward
            }

            temp = temp->next;
        }

        // Step 3: If carry remains after the last node, insert a new node
        if (carry) {
            Node* newNode = new Node(1);
            head = reverseLL(head); // Reverse back original list
            newNode->next = head;
            return newNode;
        }

        // Step 4: Reverse the list back to original order and return
        head = reverseLL(head);
        return head;
        */
    }
};
