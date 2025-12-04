#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCollisions(string directions)
    {
        int n = directions.size();
        int l = 0, r = n - 1;

        // Ignore all cars at the left moving only left (they never collide)
        while (l <= r && directions[l] == 'L')
            l++;

        // Ignore all cars at the right moving only right (they never collide)
        while (l <= r && directions[r] == 'R')
            r--;

        int cnt = 0;

        // Count all cars between l and r that are not standing still 'S'
        // Because every 'L' or 'R' inside this range eventually collides
        for (int i = l; i <= r; i++)
        {
            if (directions[i] != 'S')
                cnt++;
        }

        return cnt; // total collisions
    }
};
