# Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element — all in **constant time (O(1))**.

---

### Problem Description:

Implement the `MinStack` class with the following operations:

- `MinStack()` → Initializes the stack object.
- `void push(int val)` → Pushes the element `val` onto the stack.
- `void pop()` → Removes the element on the top of the stack.
- `int top()` → Returns the top element of the stack.
- `int getMin()` → Retrieves the minimum element in the stack.

Each of these operations must run in **O(1)** time complexity.

---

### Example 1:

```
Input:
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output:
[null,null,null,null,-3,null,0,-2]

Explanation:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // returns -3
minStack.pop();
minStack.top();    // returns 0
minStack.getMin(); // returns -2
```

---

### Constraints:

- −2³¹ ≤ val ≤ 2³¹ − 1
- Methods `pop()`, `top()`, and `getMin()` will always be called on non-empty stacks.
- At most 3 × 10⁴ calls will be made to `push()`, `pop()`, `top()`, and `getMin()`.
