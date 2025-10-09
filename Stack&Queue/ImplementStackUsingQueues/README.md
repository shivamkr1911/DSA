# Implement Stack using Queues

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack: **push**, **top**, **pop**, and **empty**.

---

## MyStack Class Functions:

- `void push(int x)` - Pushes element **x** to the top of the stack.
- `int pop()` - Removes the element on the top of the stack and returns it.
- `int top()` - Returns the element on the top of the stack.
- `boolean empty()` - Returns **true** if the stack is empty, **false** otherwise.

**Notes:**

- You must use only standard operations of a queue: push to back, peek/pop from front, size, and is empty operations.
- Depending on your language, the queue may not be natively supported. You may simulate a queue using a list or deque as long as you use only queue operations.

---

## Example:

**Input:**  
`["MyStack", "push", "push", "top", "pop", "empty"]`  
`[[], [1], [2], [], [], []]`

**Output:**  
`[null, null, null, 2, 2, false]`

**Explanation:**

- MyStack myStack = new MyStack();
- myStack.push(1);
- myStack.push(2);
- myStack.top(); // returns 2
- myStack.pop(); // returns 2
- myStack.empty(); // returns false

---

## Constraints:

- 1 <= x <= 9
- At most 100 calls will be made to push, pop, top, and empty.
- All calls to pop and top are valid.

---

## Follow-up:

Can you implement the stack using **only one queue**?
