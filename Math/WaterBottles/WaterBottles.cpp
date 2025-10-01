#include <bits/stdc++.h>
using namespace std;

// Optimal Solution
class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int res = numBottles; // start with initial full bottles
        while (numBottles >= numExchange)
        {
            int exchange = numBottles / numExchange;    // bottles gained after exchange
            int bottlesLeft = numBottles % numExchange; // leftover bottles
            res += exchange;                            // add exchanged bottles to total
            numBottles = exchange + bottlesLeft;        // new count for next iteration
        }
        return res; // total bottles drunk
    }
};

// Brute Force
/*
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0;
        int empty = 0; // count of empty bottles
        while (numBottles > 0) {
            res++; // drink one bottle
            empty++; // one more empty bottle
            numBottles--;
            if (empty == numExchange) { // exchange condition
                numBottles++; // get one new bottle
                empty = 0;
            }
        }
        return res;
    }
};
*/
