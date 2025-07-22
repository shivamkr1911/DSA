#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to find the first occurrence of target
    int firstOccurence(vector<int> &arr, int target)
    {
        int first = -1;
        int low = 0, high = arr.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (arr[mid] == target)
            {
                first = mid;    // Possible first occurrence found
                high = mid - 1; // Keep searching in left half
            }
            else if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return first;
    }

    // Function to find the last occurrence of target
    int lastOccurence(vector<int> &arr, int target)
    {
        int last = -1;
        int low = 0, high = arr.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (arr[mid] == target)
            {
                last = mid;    // Possible last occurrence found
                low = mid + 1; // Keep searching in right half
            }
            else if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return last;
    }

public:
    // Function to return the frequency of target in the array
    int countFreq(vector<int> &arr, int target)
    {
        int first = firstOccurence(arr, target);
        int last = lastOccurence(arr, target);

        if (first == -1)
            return 0;            // Element not found
        return last - first + 1; // Frequency = last - first + 1
    }
};
