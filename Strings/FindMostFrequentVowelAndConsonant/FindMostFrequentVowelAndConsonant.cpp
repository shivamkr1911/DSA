#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFreqSum(string s)
    {
        // Using hash array (size 26 for lowercase letters)
        vector<int> freq(26, 0);
        for (char c : s)
        {
            freq[c - 'a']++; // Count frequency of each character
        }

        int maxVow = 0, maxCon = 0; // Track max vowel & consonant frequency
        for (int i = 0; i < 26; ++i)
        {
            char c = i + 'a';
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                maxVow = max(maxVow, freq[i]); // Update max vowel freq
            else
                maxCon = max(maxCon, freq[i]); // Update max consonant freq
        }

        return maxVow + maxCon; // Return sum of both

        // Using hashmap
        /*
        unordered_map<char, int> mpp;
        for (char c: s) {
            mpp[c]++; // Count frequency using hashmap
        }

        int maxVow = 0, maxCon = 0;
        for (auto &it: mpp) {
            int c = it.first;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                maxVow = max(maxVow, it.second); // Update max vowel freq
            else
                maxCon = max(maxCon, it.second); // Update max consonant freq
        }

        return maxVow + maxCon;
        */
    }
};
