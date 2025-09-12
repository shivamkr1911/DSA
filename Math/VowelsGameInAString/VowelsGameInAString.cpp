#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool doesAliceWin(string s)
    {
        int vowelCnt = 0;

        // Count vowels in the string
        for (char c : s)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowelCnt++;
        }

        // Alice wins if there's at least one vowel
        return vowelCnt > 0;
    }
};

// If vowels > 0, Alice always wins because she starts, makes vowels odd,
// and Bob is stuck with odd count where only Alice can finish.
