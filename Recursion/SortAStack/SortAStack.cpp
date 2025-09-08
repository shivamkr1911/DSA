#include <bits/stdc++.h>
using namespace std;

class SortedStack
{
public:
    stack<int> s;
    void sort();
};

// Helper function to insert element in sorted order
void insertSorted(stack<int> &s, int x)
{
    if (s.empty() || s.top() <= x)
    { // place x if stack empty or correct position found
        s.push(x);
        return;
    }
    int top = s.top(); // store top
    s.pop();
    insertSorted(s, x); // recurse for remaining stack
    s.push(top);        // restore top
}

/* Sorts the stack using recursion */
void SortedStack ::sort()
{
    if (s.empty())
        return; // base case

    int top = s.top(); // remove top
    s.pop();

    sort(); // sort remaining stack

    insertSorted(s, top); // insert top in sorted order

    // Brute Force
    /*
    vector<int> arr;
    while (!s.empty()) { // move stack to array
        arr.push_back(s.top());
        s.pop();
    }
    std::sort(arr.begin(), arr.end()); // sort array
    for (int i = 0; i < arr.size(); ++i) s.push(arr[i]); // push back to stack
    */
}
