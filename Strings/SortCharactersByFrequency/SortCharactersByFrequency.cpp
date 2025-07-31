#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freq; // Step 1: Count frequencies of each character

        for (char c : s)
        {
            freq[c]++;
        }

        // Step 2: Use a max heap to sort characters by frequency (descending order)
        priority_queue<pair<int, char>> maxHeap;
        for (auto &[ch, count] : freq)
        {
            maxHeap.push({count, ch});
        }

        // Step 3: Build the result string by appending characters based on their frequency
        string result = "";
        while (!maxHeap.empty())
        {
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();
            result += string(count, ch); // Append character 'ch' 'count' times
        }

        return result;
    }
};
