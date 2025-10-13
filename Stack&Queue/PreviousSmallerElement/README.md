# Previous Smaller Element

You are given an integer array `arr[ ]`. For every element in the array, your task is to determine its **Previous Smaller Element (PSE)**.

The **Previous Smaller Element (PSE)** of an element `x` is the first element that appears to the left of `x` in the array and is strictly smaller than `x`.

**Note:** If no such element exists, assign `-1` as the PSE for that position.

---

### Example 1:

```
Input: arr[] = [1, 6, 2]
Output: [-1, 1, 1]
```

**Explanation:**

- For 1, there is no element on the left → -1
- For 6, previous smaller element is 1
- For 2, previous smaller element is 1

---

### Example 2:

```
Input: arr[] = [1, 5, 0, 3, 4, 5]
Output: [-1, 1, -1, 0, 3, 4]
```

**Explanation:**

- For 1, no element on the left → -1
- For 5, previous smaller element is 1
- For 0, no element on the left smaller than 0 → -1
- For 3, previous smaller element is 0
- For 4, previous smaller element is 3
- For 5, previous smaller element is 4

---

### Constraints:

- 1 ≤ arr.size() ≤ 10⁵
- 1 ≤ arr[i] ≤ 10⁵
