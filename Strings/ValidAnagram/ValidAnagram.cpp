#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // Create a frequency array to count occurrences of each character
        // Assuming only lowercase English letters
        vector<int> freq(26, 0);

        // If lengths are different, they cannot be anagrams
        if (s.size() != t.size())
            return false;

        // Traverse both strings simultaneously
        for (int i = 0; i < s.size(); i++)
        {
            // Increment frequency for character in string s
            freq[s[i] - 'a']++;

            // Decrement frequency for character in string t
            freq[t[i] - 'a']--;
        }

        // After processing both strings,
        // all counts should be zero if they are anagrams
        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i] != 0)
                return false; // Mismatch found
        }

        // If all counts are zero, the strings are anagrams
        return true;
    }
};
