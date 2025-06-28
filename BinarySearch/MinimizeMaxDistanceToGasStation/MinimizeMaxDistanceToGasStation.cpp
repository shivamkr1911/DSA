/*
Approaches:
1) Brute Force (Greedy Linear Scan)       - O(KN)
2) Better (Greedy + Priority Queue)       - O(K log N)
3) Optimal (Binary Search on Answers)     - O(N log(maxDist/precision))
*/

//---------------- Brute Force: Greedy Linear Scan ----------------
// O(KN)

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double findSmallestMaxDist(vector<int> &stations, int k)
    {
        int n = stations.size();
        vector<int> howMany(n - 1, 0);

        // Add gas stations one by one
        for (int gasStations = 1; gasStations <= k; gasStations++)
        {
            long double maxSection = -1;
            int maxInd = -1;

            // Find segment with largest distance
            for (int i = 0; i < n - 1; i++)
            {
                long double diff = stations[i + 1] - stations[i];
                long double sectionLength = diff / (long double)(howMany[i] + 1);
                if (sectionLength > maxSection)
                {
                    maxSection = sectionLength;
                    maxInd = i;
                }
            }

            howMany[maxInd]++; // Add station to that segment
        }

        // Find final max distance
        long double maxAns = -1;
        for (int i = 0; i < n - 1; i++)
        {
            long double diff = stations[i + 1] - stations[i];
            long double sectionLength = diff / (long double)(howMany[i] + 1);
            maxAns = max(maxAns, sectionLength);
        }
        return maxAns;
    }
};

//---------------- Better: Greedy + Priority Queue ----------------
// O(K log N)

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double findSmallestMaxDist(vector<int> &stations, int k)
    {
        int n = stations.size();
        vector<int> howMany(n - 1, 0);
        priority_queue<pair<long double, int>> pq;

        // Push all segments to max heap
        for (int i = 0; i < n - 1; i++)
        {
            pq.push({stations[i + 1] - stations[i], i});
        }

        // Add stations greedily
        for (int gasStations = 1; gasStations <= k; gasStations++)
        {
            auto tp = pq.top();
            pq.pop();
            int secInd = tp.second;
            howMany[secInd]++;

            long double iniDiff = stations[secInd + 1] - stations[secInd];
            long double newSecLen = iniDiff / (long double)(howMany[secInd] + 1);
            pq.push({newSecLen, secInd});
        }

        return pq.top().first; // Max distance after placing k stations
    }
};

//---------------- Optimal: Binary Search on Answers ----------------
// O(N log(maxDist/precision))

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    // Count gas stations needed for given max distance
    int numberOfGasStationsRequired(long double dist, vector<int> &arr)
    {
        int cnt = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            int numInBetween = ((arr[i] - arr[i - 1]) / dist);
            if ((arr[i] - arr[i - 1]) == (dist * numInBetween))
                numInBetween--;
            cnt += numInBetween;
        }
        return cnt;
    }

public:
    double findSmallestMaxDist(vector<int> &stations, int k)
    {
        int n = stations.size();
        long double low = 0, high = 0;

        // Find initial max distance between stations
        for (int i = 0; i < n - 1; i++)
        {
            high = max(high, (long double)(stations[i + 1] - stations[i]));
        }

        // Binary search for minimum possible max distance
        long double diff = 1e-6;
        while (high - low > diff)
        {
            long double mid = (low + high) / 2.0;
            int cnt = numberOfGasStationsRequired(mid, stations);

            if (cnt > k)
                low = mid; // Need more stations, increase dist
            else
                high = mid; // Possible, try smaller dist
        }

        return high;
    }
};