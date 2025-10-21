#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();
        vector<int> st; // Acts as a stack to simulate asteroid collisions

        // Traverse each asteroid
        for (int a : asteroids)
        {
            // Case 1: Positive asteroid (moving right) — safe to add
            if (a > 0)
                st.push_back(a);
            else
            {
                // Case 2: Negative asteroid (moving left)
                // Keep checking while collision is possible
                while (!st.empty() && st.back() > 0 && st.back() < abs(a))
                    st.pop_back(); // Smaller right-moving asteroid explodes

                // If both asteroids are equal in size, destroy both
                if (!st.empty() && st.back() == abs(a))
                    st.pop_back();

                // If stack empty or top asteroid is moving left — no collision
                else if (st.empty() || st.back() < 0)
                    st.push_back(a);
            }
        }
        return st; // Remaining asteroids after all collisions
    }
};
