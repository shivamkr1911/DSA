#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function to check if a character is a vowel
    bool isVowel(char c)
    {
        c = tolower(c); // convert to lowercase for uniform check
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }

public:
    string sortVowels(string s)
    {
        vector<char> vowels;

        // Collect all vowels from the string
        for (char c : s)
        {
            if (isVowel(c))
                vowels.push_back(c);
        }

        // Sort the collected vowels
        sort(vowels.begin(), vowels.end());

        // Replace vowels in original string with sorted vowels
        int j = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (isVowel(s[i]))
                s[i] = vowels[j++];
        }

        return s; // return final string with sorted vowels
    }
};
