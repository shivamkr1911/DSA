#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Optimal Solution
private:
    // Convert string to lowercase
    string makeLower(string s)
    {
        for (char &c : s)
        {
            c = tolower(c);
        }
        return s;
    }

    // Check if character is a vowel
    bool isVowel(char c)
    {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        unordered_set<string> exact;            // Exact word matches
        unordered_map<string, string> caseMap;  // Case-insensitive matches
        unordered_map<string, string> vowelMap; // Vowel-error matches

        // Preprocess wordlist
        for (auto i : wordlist)
        {
            exact.insert(i);                      // Add exact word
            string s = makeLower(i);              // Lowercase version
            if (caseMap.find(s) == caseMap.end()) // Store first occurrence
                caseMap[s] = i;

            string withoutVowels = "";
            for (char c : s)
            { // Replace vowels with '#'
                if (!isVowel(c))
                    withoutVowels += c;
                else
                    withoutVowels += '#';
            }
            if (vowelMap.find(withoutVowels) == vowelMap.end())
                vowelMap[withoutVowels] = i; // Store first occurrence
        }

        vector<string> res; // Result vector
        for (auto s : queries)
        {
            if (exact.find(s) != exact.end()) // 1. Exact match
                res.push_back(s);
            else if (caseMap.find(makeLower(s)) != caseMap.end()) // 2. Case-insensitive match
                res.push_back(caseMap[makeLower(s)]);
            else
            { // 3. Vowel-error match
                string withoutVowels = "";
                string sLower = makeLower(s);
                for (char c : sLower)
                { // Replace vowels with '#'
                    if (!isVowel(c))
                        withoutVowels += c;
                    else
                        withoutVowels += '#';
                }
                if (vowelMap.find(withoutVowels) != vowelMap.end())
                    res.push_back(vowelMap[withoutVowels]);
                else
                    res.push_back(""); // No match found
            }
        }
        return res;
    }
};

// Brute Force Solution
/*
class Solution {
private:
    // Convert string to lowercase
    string makeLower(string s) {
        for (char &c: s) {
            c = tolower(c);
        }
        return s;
    }

    // Check if character is a vowel
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> res;
        for (auto &query : queries) {
            bool found = false;

            // 1. Exact match
            for (auto &word : wordlist) {
                if (word == query) {
                    res.push_back(word);
                    found = true;
                    break;
                }
            }
            if (found) continue;

            // 2. Case-insensitive match
            string queryLower = makeLower(query);
            for (auto &word : wordlist) {
                if (makeLower(word) == queryLower) {
                    res.push_back(word);
                    found = true;
                    break;
                }
            }
            if (found) continue;

            // 3. Vowel-error match
            string queryMask = queryLower;
            for (char &c : queryMask) if (isVowel(c)) c = '#';   // Mask vowels
            for (auto &word : wordlist) {
                string wordMask = makeLower(word);
                for (char &c : wordMask) if (isVowel(c)) c = '#'; // Mask vowels
                if (wordMask == queryMask) {
                    res.push_back(word);
                    found = true;
                    break;
                }
            }
            if (!found) res.push_back("");  // No match
        }
        return res;
    }
};
*/
