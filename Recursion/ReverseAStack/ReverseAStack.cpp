#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function to insert element at the bottom of stack
    void insert(stack<int> &St, int x)
    {
        if (St.empty())
        { // if stack empty, push element
            St.push(x);
            return;
        }
        int top = St.top(); // store top
        St.pop();
        insert(St, x); // recurse until bottom
        St.push(top);  // restore top
    }

public:
    // Function to reverse the stack using recursion
    void reverse(stack<int> &St)
    {
        // Recursive Solution
        if (St.empty())
            return;         // base case
        int top = St.top(); // remove top
        St.pop();
        reverse(St);     // reverse remaining stack
        insert(St, top); // insert top at bottom

        // Brute Force
        /*
        vector<int> arr;
        while(!St.empty()) {
            arr.push_back(St.top());
            St.pop();
        }
        for (int i: arr) {
            St.push(i);
        }
        */
    }
};
