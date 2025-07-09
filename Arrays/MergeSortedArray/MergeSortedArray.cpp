#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // Optimal Solution - Gap Method (Shell Sort idea)

        int len = m + n;
        int gap = (len / 2) + (len % 2);

        while (gap > 0)
        {
            int left = 0;
            int right = left + gap;

            while (right < len)
            {
                // nums1 - nums1
                if (left < m && right < m)
                {
                    if (nums1[left] > nums1[right])
                        swap(nums1[left], nums1[right]);
                }
                // nums1 - nums2
                else if (left < m && right >= m)
                {
                    if (nums1[left] > nums2[right - m])
                        swap(nums1[left], nums2[right - m]);
                }
                // nums2 - nums2
                else
                {
                    if (nums2[left - m] > nums2[right - m])
                        swap(nums2[left - m], nums2[right - m]);
                }

                left++;
                right++;
            }

            if (gap == 1)
                break;                   // Last pass done
            gap = (gap / 2) + (gap % 2); // Reduce gap
        }

        // Copy nums2 into nums1
        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }
    }
};
