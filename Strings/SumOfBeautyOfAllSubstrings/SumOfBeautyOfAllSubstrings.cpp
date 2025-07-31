#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int beautySum(string s)
    {
        int n = s.size();
        int totalBeauty = 0;

        // Step 1: Iterate over all substrings
        for (int i = 0; i < n; i++)
        {
            vector<int> freq(26, 0); // Frequency array for characters 'a' to 'z'

            for (int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++; // Increment frequency of current character

                int minFreq = INT_MAX, maxFreq = 0;

                // Step 2: Find max and min frequencies in the current substring
                for (int f : freq)
                {
                    if (f == 0)
                        continue; // Ignore characters not present
                    minFreq = min(minFreq, f);
                    maxFreq = max(maxFreq, f);
                }

                // Step 3: Add beauty (max - min) to total
                totalBeauty += maxFreq - minFreq;
            }
        }

        return totalBeauty;
    }
};
