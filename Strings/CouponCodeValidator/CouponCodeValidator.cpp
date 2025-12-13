#include <bits/stdc++.h>
using namespace std;

// =============== Optimal Solution (Priority-based Sorting Using Mapping) ===============
class Solution1
{
public:
    vector<string> validateCoupons(vector<string> &code,
                                   vector<string> &businessLine,
                                   vector<bool> &isActive)
    {

        // Assign priority order to each business category
        unordered_map<string, int> priority{
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}};

        vector<pair<int, string>> valid; // {priority, couponCode}

        for (int i = 0; i < code.size(); ++i)
        {

            // Skip inactive coupons or empty codes
            if (!isActive[i] || code[i].empty())
                continue;

            // Skip invalid business categories
            if (!priority.count(businessLine[i]))
                continue;

            // Validate coupon format: alphanumeric or underscore only
            bool ok = true;
            for (char c : code[i])
            {
                if (!isalnum(c) && c != '_')
                {
                    ok = false;
                    break;
                }
            }

            // Store valid coupon with its category priority
            if (ok)
                valid.push_back({priority[businessLine[i]], code[i]});
        }

        // Sort by priority first, then lexicographically by code
        sort(valid.begin(), valid.end());

        vector<string> ans;
        for (auto &p : valid)
            ans.push_back(p.second);

        return ans;
    }
};

// =============== Better Solution (Category-wise / Bucket-based Sorting) ===============
class Solution2
{
public:
    vector<string> validateCoupons(vector<string> &code,
                                   vector<string> &businessLine,
                                   vector<bool> &isActive)
    {

        int n = code.size();

        // Buckets for each business category
        vector<string> electronics, grocery, pharmacy, restaurant;

        for (int i = 0; i < n; ++i)
        {

            // Skip inactive or empty coupons
            if (!isActive[i] || code[i].empty())
                continue;

            // Validate coupon characters
            bool validCode = true;
            for (char c : code[i])
            {
                if (!isalnum(c) && c != '_')
                {
                    validCode = false;
                    break;
                }
            }
            if (!validCode)
                continue;

            // Push coupon into respective category bucket
            if (businessLine[i] == "electronics")
                electronics.push_back(code[i]);
            else if (businessLine[i] == "grocery")
                grocery.push_back(code[i]);
            else if (businessLine[i] == "pharmacy")
                pharmacy.push_back(code[i]);
            else if (businessLine[i] == "restaurant")
                restaurant.push_back(code[i]);
        }

        // Sort each category lexicographically
        sort(electronics.begin(), electronics.end());
        sort(grocery.begin(), grocery.end());
        sort(pharmacy.begin(), pharmacy.end());
        sort(restaurant.begin(), restaurant.end());

        // Merge results in required priority order
        vector<string> ans;
        ans.insert(ans.end(), electronics.begin(), electronics.end());
        ans.insert(ans.end(), grocery.begin(), grocery.end());
        ans.insert(ans.end(), pharmacy.begin(), pharmacy.end());
        ans.insert(ans.end(), restaurant.begin(), restaurant.end());

        return ans;
    }
};