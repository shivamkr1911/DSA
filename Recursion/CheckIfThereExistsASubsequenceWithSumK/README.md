# Check if there exists a subsequence with sum K

Given an array **arr** and a target sum **k**, check whether there exists a subsequence such that the sum of all elements in the subsequence equals the given target sum (**k**).

---

### Example 1:

```
Input:
arr = [10, 1, 2, 7, 6, 1, 5], k = 8

Output:
Yes
```

**Explanation:** Subsequences like `[2, 6]`, `[1, 7]` sum up to **8**.

---

### Example 2:

```
Input:
arr = [2, 3, 5, 7, 9], k = 100

Output:
No
```

**Explanation:** No subsequence can sum up to **100**.

---

### Your Task:

You don't need to read or print anything.  
Your task is to complete the boolean function **checkSubsequenceSum()** which takes **N, arr, and K** as input parameters and returns **true/false** based on whether any subsequence with sum **k** could be found.

---

### Constraints:

- 1 ≤ arr.length ≤ 2000
- 1 ≤ arr[i] ≤ 1000
- 1 ≤ target ≤ 2000
