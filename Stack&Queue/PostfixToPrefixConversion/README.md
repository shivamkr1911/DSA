# Postfix to Prefix Conversion

You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its prefix form.

---

### Example 1:

```
Input: ABC/-AK/L-*
Output: *-A/BC-/AKL

Explanation:
The above output is its valid prefix form.
```

### Example 2:

```
Input: ab+
Output: +ab

Explanation:
The above output is its valid prefix form.
```

---

### Your Task:

Complete the function `string postToPre(string post_exp)`, which takes a postfix string as input and returns its prefix form.

---

### Expected Complexity:

- **Time Complexity**: O(post_exp.length())
- **Auxiliary Space**: O(post_exp.length())

---

### Constraints:

- 3 ≤ post_exp.length() ≤ 16,000
