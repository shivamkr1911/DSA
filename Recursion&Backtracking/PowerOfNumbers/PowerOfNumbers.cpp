#include <bits/stdc++.h>
using namespace std;

// =============== Recursive Solution ===============
class Solution1
{
private:
    // Function to reverse the digits of a number
    int reverse(int num)
    {
        int ans = 0;
        while (num > 0)
        {
            ans = ans * 10 + num % 10; // build reversed number
            num /= 10;
        }
        return ans;
    }

    // Recursive function to calculate power (base^expo)
    int findPowerRec(int base, int expo)
    {
        if (expo == 0)
            return 1; // base case: anything^0 = 1
        else if (expo % 2 == 0)
        { // if exponent is even
            int half = findPowerRec(base, expo / 2);
            return half * half; // divide and conquer
        }
        else
        { // if exponent is odd
            return base * findPowerRec(base, expo - 1);
        }
    }

public:
    // Function to compute n^(reverse(n))
    int reverseExponentiation(int n)
    {
        int rev = reverse(n);           // reverse the number
        int res = findPowerRec(n, rev); // compute power
        return res;
    }
};

// =============== Iterative Solution ===============

class Solution2
{
private:
    // Function to reverse digits of a number
    int reverse(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            ans = ans * 10 + n % 10;
            n /= 10;
        }
        return ans;
    }

    // Iterative function to calculate power (base^expo)
    int findPower(int base, int expo)
    {
        int ans = 1;
        while (expo > 0)
        {
            if (expo % 2 == 0)
            { // even exponent
                base *= base;
                expo /= 2;
            }
            else
            { // odd exponent
                ans *= base;
                expo--;
            }
        }
        return ans;
    }

public:
    // Function to compute n^(reverse(n))
    int reverseExponentiation(int n)
    {
        int rev = reverse(n);
        int res = findPower(n, rev);
        return res;
    }
};
