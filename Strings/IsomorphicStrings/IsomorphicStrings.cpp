#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;

        for (int i = 0; i < s.length(); i++)
        {
            char cs = s[i]; // char from s
            char ct = t[i]; // char from t

            // If s[i] is already mapped, check if it's to the right char in t
            if (sToT.count(cs) && sToT[cs] != ct)
                return false;

            // If t[i] is already used by another char, return false
            if (tToS.count(ct) && tToS[ct] != cs)
                return false;

            // Map s[i] to t[i] and t[i] to s[i]
            sToT[cs] = ct;
            tToS[ct] = cs;
        }

        return true;
    }
};
