#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countOperations(int num1, int num2)
    {
        int cnt = 0;

        // Continue until one of the numbers becomes zero
        while (num1 > 0 && num2 > 0)
        {

            // Subtract the smaller from the larger
            if (num1 >= num2)
                num1 -= num2;
            else
                num2 -= num1;

            cnt++; // count each valid operation
        }

        return cnt;
    }
};
