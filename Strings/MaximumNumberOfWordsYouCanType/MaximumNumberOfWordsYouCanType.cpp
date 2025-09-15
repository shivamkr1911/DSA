#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        // Store broken letters in a set for quick lookup
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());

        stringstream ss(text); // Split text into words
        string word;
        int cnt = 0; // Count of words that can be typed

        // Process each word in the text
        while (ss >> word)
        {
            bool isBroken = false;

            // Check if the word contains any broken letter
            for (char c : word)
            {
                if (broken.count(c))
                {
                    isBroken = true;
                    break; // No need to check further if one broken letter is found
                }
            }

            // If word has no broken letter, it can be typed
            if (!isBroken)
                cnt++;
        }

        return cnt; // Return total words that can be typed
    }
};
