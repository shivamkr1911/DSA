# Minimum Window Subsequence

You are given two strings `s1` and `s2`. Your task is to find the smallest substring in `s1` such that `s2` appears as a **subsequence** within that substring.

1. The characters of `s2` must appear in the same sequence within the substring of `s1`.

2. If there are multiple valid substrings of the same minimum length, return the one that appears first in `s1`.

3. If no such substring exists, return an empty string.

**Note:** Both strings contain only lowercase English letters.

---

### Example 1:

```
Input: s1 = "geeksforgeeks", s2 = "eksrg"
Output: "eksforg"
```

Explanation: "eksforg" satisfies all required conditions. s2 is its subsequence and it is the smallest and leftmost among all possible valid substrings of s1.

---

### Example 2:

```
Input: s1 = "abcdebdde", s2 = "bde"
Output: "bcde"
```

Explanation: "bcde" and "bdde" are two substrings of s1 where s2 occurs as a subsequence, but "bcde" occurs first, so we return that.

---

### Example 3:

```
Input: s1 = "ad", s2 = "b"
Output: ""
```

Explanation: There is no such substring.

---

### Constraints:

- 1 ≤ s1.length ≤ 10⁴
- 1 ≤ s2.length ≤ 50
