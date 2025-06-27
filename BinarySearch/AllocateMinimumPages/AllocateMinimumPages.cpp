#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Count students needed for given maxPages
    int cntStudents(vector<int> &arr, int k, int maxPages)
    {
        int studentsRequired = 1;
        int currPages = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (currPages + arr[i] <= maxPages)
            {
                currPages += arr[i]; // Add book to current student
            }
            else
            {
                studentsRequired++; // New student
                currPages = arr[i];
            }
        }

        return studentsRequired;
    }

public:
    int findPages(vector<int> &arr, int k)
    {
        if (k > arr.size())
            return -1; // Not possible

        int low = *max_element(arr.begin(), arr.end());   // Min limit
        int high = accumulate(arr.begin(), arr.end(), 0); // Max limit

        // Binary search for minimum max pages
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (cntStudents(arr, k, mid) > k)
                low = mid + 1; // Too few pages, increase limit
            else
                high = mid - 1; // Possible, try lower
        }

        return low;
    }
};
