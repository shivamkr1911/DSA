#include <bits/stdc++.h>
using namespace std;

// Node class definition
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
public:
    // Function to search for a key in the linked list
    bool searchKey(int n, Node *head, int key)
    {
        Node *temp = head; // Initialize temp pointer to traverse the list
        while (temp)
        {
            if (temp->data == key)
                return true;   // Key found
            temp = temp->next; // Move to next node
        }
        return false; // Key not found
    }
};
