#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        if (numBottles < numExchange)
            return numBottles; // not enough bottles to exchange
        int res = 0;           // total bottles drunk
        int full = numBottles, empty = 0;

        while (full > 0)
        {
            res += full;   // drink all full bottles
            empty += full; // move them to empty
            full = 0;

            // keep exchanging empty bottles for new full bottles
            while (empty >= numExchange)
            {
                full++;               // get one new full bottle
                empty -= numExchange; // use required empty bottles
                numExchange++;        // increase exchange requirement
            }
        }
        return res; // total bottles drunk
    }
};
