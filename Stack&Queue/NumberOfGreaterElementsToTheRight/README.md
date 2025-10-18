# Number of Greater Elements to the Right

Given an array `arr[]` and `Q` queries of indices. For each query `indices[i]`, determine the count of elements in `arr` that are strictly greater than `arr[indices[i]]` to its right (after the position `indices[i]`).

---

### Example 1:

```
Input: arr[] = [3, 4, 2, 7, 5, 8, 10, 6], queries = 2, indices[] = [0, 5]
Output: [6, 1]
```

**Explanation:**

- The next greater elements to the right of 3 (index 0) are 4, 7, 5, 8, 10, 6.
- The next greater element to the right of 8 (index 5) is only 10.

---

### Example 2:

```
Input: arr[] = [1, 2, 3, 4, 1], queries = 2, indices[] = [0, 3]
Output: [3, 0]
```

**Explanation:**

- The count of numbers to the right of index 0 which are greater than arr[0] is 3 i.e. (2, 3, 4).
- The count of numbers to the right of index 3 which are greater than arr[3] is 0, since there are no greater elements than 4 to the right of the array.

---

### Constraints:

- 1 ≤ N ≤ 10⁴
- 1 ≤ arr[i] ≤ 10⁵
- 1 ≤ queries ≤ 100
- 0 ≤ indices[i] ≤ N - 1
