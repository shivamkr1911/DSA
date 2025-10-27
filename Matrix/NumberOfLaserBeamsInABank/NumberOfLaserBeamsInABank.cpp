#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function to count number of '1's (devices) in a given row
    int cntDevices(string s)
    {
        int cnt = 0;
        for (char c : s)
        {
            if (c == '1')
                cnt++; // Increment count for each device
        }
        return cnt; // Return total devices in this row
    }

public:
    int numberOfBeams(vector<string> &bank)
    {
        int prev = 0; // Stores number of devices in previous non-empty row
        int ans = 0;  // Stores total number of beams

        // Iterate through each row in the bank
        for (string &row : bank)
        {
            int devices = cntDevices(row); // Count devices in current row

            if (devices == 0)
                continue; // Skip rows without devices

            // Beams = devices in current row × devices in previous non-empty row
            ans += prev * devices;

            // Update previous row device count
            prev = devices;
        }

        return ans; // Return total number of beams
    }
};
