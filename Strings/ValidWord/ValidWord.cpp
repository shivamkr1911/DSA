#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string word)
    {
        // Word must have at least 3 characters
        if (word.length() < 3)
            return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (char c : word)
        {
            // Word must contain only alphanumeric characters
            if (!isalnum(c))
                return false;

            if (isalpha(c))
            {
                char low = tolower(c);
                // Check for vowels
                if (low == 'a' || low == 'e' || low == 'i' || low == 'o' || low == 'u')
                    hasVowel = true;
                else
                    hasConsonant = true; // All other letters are consonants
            }
        }

        // Valid only if it has at least one vowel and one consonant
        return hasVowel && hasConsonant;
    }
};
