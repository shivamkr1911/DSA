# Prefix to Infix Conversion

You are given a string `S` of size `N` that represents the prefix form of a valid mathematical expression. The string `S` contains only lowercase and uppercase alphabets as operands and the operators are `+`, `-`, `*`, `/`, `%`, and `^`. Convert it to its infix form.

---

### Example 1:

```
Input: *-A/BC-/AKL
Output: ((A-(B/C))*((A/K)-L))

Explanation:
The above output is its valid infix form.
```

---

### Your Task:

Complete the function `string preToInfix(string pre_exp)`, which takes a prefix string as input and returns its infix form.

---

### Expected Complexity:

- **Time Complexity**: O(N)
- **Auxiliary Space**: O(N)

---

### Constraints:

- 3 ≤ |S| ≤ 10^4
