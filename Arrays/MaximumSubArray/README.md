# Maximum Sub Array

Given an array of integers arr[], find the contiguous subarray with the maximum sum that contains only non-negative numbers. If multiple subarrays have the same sum, return the one with the smallest starting index. If the array contains only negative numbers, return -1.

**Note:** A subarray is a contiguous non-empty sequence of elements within an array.

---

### Example 1:

```
Input: arr[] = [1, 2, 3]
Output: [1, 2, 3]
Explanation: In the given array, every element is non-negative, so the entire array [1, 2, 3] is the valid subarray with the maximum sum.
```

### Example 2:

```
Input: arr[] = [-1, 2]
Output: [2]
Explanation: The only valid non-negative subarray is [2], so the output is [2].
```

### Example 3:

```
Input: arr[] = [1, 2, 5, -7, 2, 6]
Output: [1, 2, 5]
Explanation: The valid non-negative subarrays are [1, 2, 5] and [2, 6]. Both have the same sum of 8, but [1, 2, 5] starts earlier, so it is the preferred subarray.
```

---

### Constraints:

- 1 ≤ arr.size() ≤ 10⁶
- -10⁵ ≤ arr[i] ≤ 10⁵
