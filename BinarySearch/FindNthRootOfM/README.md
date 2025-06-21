# Find nth root of m

You are given 2 numbers `n` and `m`, the task is to find `n√m` (nth root of m). If the root is not integer then return `-1`.

---

### Examples:

```
Input: n = 2, m = 9  
Output: 3  
Explanation: 3² = 9
```

```
Input: n = 3, m = 9  
Output: -1  
Explanation: 3rd root of 9 is not integer.
```

```
Input: n = 1, m = 14  
Output: 14
```

---

### Constraints:
- `1 <= n <= 30`
- `1 <= m <= 10⁹`

---

### Expected Complexities:
- **Time Complexity**: O(n log m)
- **Auxiliary Space**: O(1)