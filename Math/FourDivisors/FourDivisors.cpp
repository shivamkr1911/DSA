#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumFourDivisors(vector<int> &nums)
    {
        int ans = 0; // final sum of divisors for valid numbers

        // Process each number independently
        for (int x : nums)
        {
            int cnt = 0; // count of divisors
            int sum = 0; // sum of divisors

            // Iterate up to sqrt(x) to find divisor pairs
            for (int d = 1; d * d <= x; ++d)
            {
                if (x % d == 0)
                {
                    int other = x / d;

                    // Perfect square case → count only once
                    if (d == other)
                    {
                        cnt++;
                        sum += d;
                    }
                    else
                    {
                        cnt += 2; // d and x/d are two divisors
                        sum += d + other;
                    }
                }
            }

            // Add sum only if number has exactly 4 divisors
            if (cnt == 4)
                ans += sum;
        }

        return ans;
    }
};
