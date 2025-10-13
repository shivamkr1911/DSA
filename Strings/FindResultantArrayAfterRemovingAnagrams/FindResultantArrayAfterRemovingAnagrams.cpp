#include <bits/stdc++.h>
using namespace std;

// ================= Optimal Solution =================
class Solution1
{
private:
    // Check if two strings are anagrams
    bool isAnagram(string &a, string &b)
    {
        if (a.size() != b.size())
            return false; // quick length check
        string sa = a, sb = b;
        sort(sa.begin(), sa.end()); // sort first string
        sort(sb.begin(), sb.end()); // sort second string
        return sa == sb;            // compare sorted strings
    }

public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> ans; // store resulting words
        for (string &word : words)
        {
            // if ans is not empty and current word is an anagram of last added word
            if (!ans.empty() && isAnagram(ans.back(), word))
                continue;        // skip it
            ans.push_back(word); // otherwise, add current word
        }
        return ans; // return the filtered list
    }
};

// ================= Brute Force Solution =================

class Solution2
{
private:
    // Check if two strings are anagrams
    bool isAnagram(string a, string b)
    {
        if (a.size() != b.size())
            return false;         // quick length check
        sort(a.begin(), a.end()); // sort first string
        sort(b.begin(), b.end()); // sort second string
        return a == b;            // compare sorted strings
    }

public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        int i = 1;
        // iterate through the words list
        while (i < words.size())
        {
            // if current word is an anagram of previous
            if (isAnagram(words[i - 1], words[i]))
            {
                words.erase(words.begin() + i); // remove current word
            }
            else
            {
                i++; // move to next word
            }
        }
        return words; // return the filtered list
    }
};
