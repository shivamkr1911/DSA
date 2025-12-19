#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Check whether a character is a lowercase vowel
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }

    // Reverse a word in-place using two pointers
    string reverse(string &word)
    {
        int l = 0, r = word.size() - 1;
        while (l < r)
        {
            swap(word[l++], word[r--]);
        }
        return word;
    }

public:
    string reverseWords(string s)
    {
        int n = s.size();
        int refVowel = 0; // vowel count of the first word
        int i = 0;

        // Count vowels in the first word
        while (i < n && s[i] != ' ')
        {
            if (isVowel(s[i]))
                refVowel++;
            i++;
        }

        // First word is added as-is
        string ans = s.substr(0, i);
        i++; // skip space

        // Process remaining words
        while (i < n)
        {
            int start = i;
            int cnt = 0; // vowel count for current word

            // Traverse current word and count vowels
            while (i < n && s[i] != ' ')
            {
                if (isVowel(s[i]))
                    cnt++;
                i++;
            }

            string word = s.substr(start, i - start);
            ans += " ";

            // Reverse word only if vowel count matches first word
            if (cnt == refVowel)
                ans += reverse(word);
            else
                ans += word;

            i++; // move past space
        }

        return ans;
    }
};
