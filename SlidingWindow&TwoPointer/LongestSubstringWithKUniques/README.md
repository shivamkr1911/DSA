# Longest Substring with K Uniques

You are given a string `s` consisting only of lowercase alphabets and an integer `k`. Your task is to find the length of the longest substring that contains exactly `k` distinct characters.

If no such substring exists, return `-1`.

---

### Example 1:

```
Input: s = "aabacbebebe", k = 3
Output: 7
```

Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.

---

### Example 2:

```
Input: s = "aaaa", k = 2
Output: -1
```

Explanation: There's no substring with 2 distinct characters.

---

### Example 3:

```
Input: s = "aabaaab", k = 2
Output: 7
```

Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.

---

### Constraints:

- 1 ≤ s.size() ≤ 10⁵
- 1 ≤ k ≤ 26
