#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    // Default constructor
    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    // Parameterized constructor
    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

class Solution
{
public:
    Node *constructDLL(vector<int> &arr)
    {
        // Initialize head node
        Node *head = new Node(arr[0]);
        Node *prev = head;

        // Build the remaining list
        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i]);
            temp->prev = prev; // Link backward
            prev->next = temp; // Link forward
            prev = temp;       // Move to next node
        }

        // Return head of DLL
        return head;
    }
};
