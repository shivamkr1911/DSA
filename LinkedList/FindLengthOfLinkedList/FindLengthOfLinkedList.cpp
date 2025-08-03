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
public:
    int getCount(Node *head)
    {
        // Initialize a temp pointer to traverse the list
        Node *temp = head;
        int cnt = 0;

        // Traverse till end and count nodes
        while (temp)
        {
            cnt++;
            temp = temp->next;
        }

        // Return total count of nodes
        return cnt;
    }
};
