#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // ✅ Optimal Solution - Two Pointer Technique on DLL
        vector<pair<int, int>> ans;

        // Step 1: Find left (head) and right (tail) pointers
        Node *left = head;
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node *right = temp;

        // Original condition (also correct way to ensure no overlap in DLL traversal)
        // while (left != right && right->next != left) {

        // Simplified check based on data values (since list is sorted)
        while (left->data < right->data)
        {
            int data1 = left->data;
            int data2 = right->data;
            int sum = data1 + data2;

            if (sum == target)
            {
                // Pair found, add to result
                ans.push_back({data1, data2});
                left = left->next;
                right = right->prev;
            }
            else if (sum < target)
            {
                left = left->next; // Need bigger sum → move left forward
            }
            else
            {
                right = right->prev; // Need smaller sum → move right backward
            }
        }
        return ans;

        // ✅ Brute Force Solution - Nested Loops
        /*
        vector<pair<int, int>> ans;
        Node* temp1 = head;

        // Compare each node with all nodes after it
        while (temp1 != NULL) {
            Node* temp2 = temp1->next;
            while (temp2 != NULL) {
                int data1 = temp1->data;
                int data2 = temp2->data;

                // If pair sum matches target, add to result
                if (data1 + data2 == target) {
                    ans.push_back({data1, data2});
                }
                else if (data1 + data2 > target)
                    break;  // Since list is sorted, no need to check further

                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return ans;
        */
    }
};
