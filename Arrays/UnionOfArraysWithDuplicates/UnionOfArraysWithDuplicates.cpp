#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        // -------- Approach 1: Sorting + Two Pointers --------

        // Sort both arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i = 0, j = 0; // Pointers for both arrays
        int n = a.size(), m = b.size();
        vector<int> un; // Stores union elements

        // Traverse both arrays
        while (i < n && j < m)
        {
            if (a[i] <= b[j])
            {                                        // If a[i] is smaller or equal
                if (un.empty() || un.back() != a[i]) // Avoid duplicates
                    un.push_back(a[i]);
                i++;
            }
            else
            {                                        // If b[j] is smaller
                if (un.empty() || un.back() != b[j]) // Avoid duplicates
                    un.push_back(b[j]);
                j++;
            }
        }

        // Add remaining elements of a[]
        while (i < n)
        {
            if (un.back() != a[i]) // Avoid duplicates
                un.push_back(a[i]);
            i++;
        }

        // Add remaining elements of b[]
        while (j < m)
        {
            if (un.back() != b[j]) // Avoid duplicates
                un.push_back(b[j]);
            j++;
        }

        return un;

        // -------- Approach 2: Using Set --------
        /*
        set<int> st;                     // Set automatically removes duplicates

        // Insert all elements of a[]
        for (int i = 0; i < a.size(); ++i) {
            st.insert(a[i]);
        }

        // Insert all elements of b[]
        for (int j = 0; j < b.size(); ++j) {
            st.insert(b[j]);
        }

        vector<int> un;
        // Transfer set elements to vector
        for (auto & it : st) {
            un.push_back(it);
        }
        return un;
        */

        // -------- Approach 3: Using Map --------
        /*
        map<int, int> mpp;               // Key = element, Value = frequency
        vector<int> union1;

        // Count elements of a[]
        for (int i = 0; i < a.size(); ++i) {
            mpp[a[i]]++;
        }

        // Count elements of b[]
        for (int j = 0; j < b.size(); ++j) {
            mpp[b[j]]++;
        }

        // Store only unique keys in result
        for (auto & it : mpp) {
            union1.push_back(it.first);
        }
        return union1;
        */
    }
};
