# Infix To Prefix Notation

You are given a string `s` representing an infix expression. Convert this infix expression to a prefix expression.

- **Infix expression**: The expression of the form `a op b`, where an operator is between every pair of operands.
- **Prefix expression**: The expression of the form `op a b`, where an operator comes before its two operands.

**Note**: The precedence order is as follows:

- `^` has the highest precedence and is evaluated from **right to left**.
- `*` and `/` come next with **left to right** associativity.
- `+` and `-` have the lowest precedence with **left to right** associativity.

---

### Example 1:

```
Input: s = "a*(b+c)/d"
Output: /*a+bcd

Explanation:
The infix expression is a*(b+c)/d. First, inside the brackets, b + c becomes +bc.
Now the expression looks like a*(+bc)/d. Next, multiply a with (+bc), so it becomes *a+bc.
Finally, divide this result by d, so it becomes /*a+bcd.
```

### Example 2:

```
Input: s = "(a-b/c)*(a/k-l)"
Output: *-a/bc-/akl

Explanation:
The infix expression is (a-b/c)*(a/k-l). First, inside the brackets, b/c becomes /bc and a/k becomes /ak.
Now the expression looks like (a-/bc) * (/ak-l). Next, handle the subtractions: a-/bc becomes -a/bc, and /ak-l becomes -/akl.
Finally, multiply the two results: (-a/bc * -/akl) becomes *-a/bc-/akl.
```

---

### Constraints:

- 3 ≤ s.length() ≤ 5 \* 10^3
- s[i] can be an operand (`a–z`, `A–Z`, `0–9`), an operator (`+`, `-`, `*`, `/`, `^`) or a parenthesis (`(`, `)`).
