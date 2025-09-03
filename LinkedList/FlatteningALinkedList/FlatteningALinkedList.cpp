#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution
{
private:
    // Function to merge two sorted linked lists (using bottom pointer)
    Node *mergeTwoLists(Node *list1, Node *list2)
    {
        Node *dummyNode = new Node(-1); // dummy node for simplicity
        Node *mover = dummyNode;

        // Merge two sorted lists like in merge sort
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->data < list2->data)
            {
                mover->bottom = list1; // attach list1 node
                mover = list1;
                list1 = list1->bottom;
            }
            else
            {
                mover->bottom = list2; // attach list2 node
                mover = list2;
                list2 = list2->bottom;
            }
            mover->next = NULL; // ensure 'next' is not used
        }

        // Attach the remaining part of whichever list is not empty
        if (list1)
            mover->bottom = list1;
        else if (list2)
            mover->bottom = list2;

        Node *mergedHead = dummyNode->bottom;
        delete dummyNode; // free dummy node
        return mergedHead;
    }

    // Helper function to build a bottom-linked list from an array
    Node *convert(vector<int> arr)
    {
        if (arr.size() == 0)
            return NULL;
        Node *head = new Node(arr[0]);
        Node *temp = head;
        for (int i = 1; i < arr.size(); ++i)
        {
            Node *newNode = new Node(arr[i]);
            temp->bottom = newNode;
            temp = newNode;
        }
        return head;
    }

public:
    Node *flatten(Node *root)
    {
        // ✅ Optimal Solution: recursive + merge
        if (root == NULL || root->next == NULL)
            return root;

        // Recursively flatten the right list
        Node *mergedRoot = flatten(root->next);

        // Merge current list with the flattened right list
        return mergeTwoLists(root, mergedRoot);

        // ✅ Brute Force Solution
        /*
        // Collect all values in a vector
        vector<int> arr;
        Node* temp1 = root;
        while (temp1 != NULL) {
            Node* temp2 = temp1;
            while (temp2 != NULL) {
                arr.push_back(temp2->data);
                temp2 = temp2->bottom;
            }
            temp1 = temp1->next;
        }

        // Sort all values
        sort(arr.begin(), arr.end());

        // Convert sorted array into a bottom-linked list
        root = convert(arr);
        return root;
        */
    }
};
