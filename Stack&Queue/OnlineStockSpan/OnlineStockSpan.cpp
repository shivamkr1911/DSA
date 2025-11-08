#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution ===============
class StockSpanner1
{
public:
    int ind = -1;             // keeps track of current index (day number)
    stack<pair<int, int>> st; // stores {price, index} in a monotonic stack

    StockSpanner1()
    {
        ind = -1;
    }

    int next(int price)
    {
        ind += 1; // move to next day
        int ans = 0;

        // Pop all previous prices <= current price
        // (they cannot contribute to next span as current price is greater/equal)
        while (!st.empty() && price >= st.top().first)
            st.pop();

        // If stack is empty → span extends to beginning (-1)
        // Else → span ends right after previous greater element
        ans += ind - (st.empty() ? -1 : st.top().second);

        // Push current day's price along with index
        st.push({price, ind});
        return ans;
    }
};

// =============== Brute Force ===============
class StockSpanner2
{
public:
    vector<int> prices; // simply store all prices in an array

    StockSpanner2() {}

    int next(int price)
    {
        prices.push_back(price);
        int cnt = 0;

        // Count backwards until a higher price appears
        for (int i = prices.size() - 1; i >= 0; --i)
        {
            if (prices[i] <= price)
                cnt++;
            else
                break; // stop when greater price found
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
