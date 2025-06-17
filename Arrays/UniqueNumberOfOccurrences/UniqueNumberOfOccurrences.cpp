#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> freq;
        for (int num : arr)
            freq[num]++;

        unordered_set<int> freqSet;
        for (auto it : freq)
            freqSet.insert(it.second);

        return freq.size() == freqSet.size();
    }
};