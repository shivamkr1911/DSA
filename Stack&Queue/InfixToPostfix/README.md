# Infix to Postfix

You are given a string `s` representing an infix expression. Convert this infix expression to a postfix expression.

- **Infix expression**: The expression of the form `a op b`, where an operator is between every pair of operands.
- **Postfix expression**: The expression of the form `a b op`, where an operator follows every pair of operands.

**Note**: The precedence order is as follows:

- `^` has the highest precedence and is evaluated from **right to left**.
- `*` and `/` come next with **left to right** associativity.
- `+` and `-` have the lowest precedence with **left to right** associativity.

---

### Example 1:

```
Input: s = "a*(b+c)/d"
Output: abc+*d/

Explanation:
The expression is a*(b+c)/d. First, inside the brackets, b+c becomes bc+.
Now the expression looks like a*(bc+)/d. Next, multiply a with (bc+), so it becomes abc+*.
Finally, divide this result by d, so it becomes abc+*d/.
```

### Example 2:

```
Input: s = "a+b*c+d"
Output: abc*+d+

Explanation:
The expression a+b*c+d is converted by first doing b*c -> bc*,
then adding a -> abc*+, and finally adding d -> abc*+d+.
```

### Example 3:

```
Input: s = "(a+b)*(c+d)"
Output: ab+cd+*

Explanation:
The expression (a+b)*(c+d) is converted by first doing (a+b) -> ab+,
then doing (c+d) -> cd+, and finally the expression ab+*cd+ becomes ab+cd+*.
```

---

### Constraints:

- 1 ≤ s.length ≤ 5 \* 10^3
- s[i] can be an operand (`a–z`, `A–Z`, `0–9`), an operator (`+`, `-`, `*`, `/`, `^`) or a parenthesis (`(`, `)`).
