# Implement Stack Using Array

Implement a **Stack** using an array, where the size of the array `n` is given.

The Stack must support the following operations:

1. **push(x)**: Insert an element `x` at the top of the stack.
2. **pop()**: Remove the element from the top of the stack.
3. **peek()**: Return the top element if not empty, else -1.
4. **isEmpty()**: Return `true` if the stack is empty, else `false`.
5. **isFull()**: Return `true` if the stack is full, else `false`.

There will be a sequence of queries `queries[][]`. The queries are represented in numeric form:

- `1 x` : Call `push(x)`
- `2` : Call `pop()`
- `3` : Call `peek()`
- `4` : Call `isEmpty()`
- `5` : Call `isFull()`

You just have to implement the functions **push, pop, peek, isEmpty, and isFull**. The driver code will handle the output.

**Note:** All the queries are valid.

---

## Example 1:

Input:  
n = 3, q = 6, queries[][] = [[1, 5], [1, 3], [3], [2], [4], [5]]

Output: [3, false, false]

Explanation:

- push(5) : Insert 5 at the top of the stack.
- push(3) : Insert 3 at the top of the stack.
- peek() : Return the top element i.e. 3.
- pop() : Remove the top element i.e. 3.
- isEmpty(): return false as the stack is not empty.
- isFull() : return false as the stack is not full. Capacity = 3.

---

## Example 2:

Input:  
n = 1, q = 5, queries[][] = [[2], [3], [4], [1, 9], [5]]

Output: [-1, -1, true, true]

Explanation:

- pop(): Stack is empty, nothing is popped.
- peek(): Stack is empty, return -1.
- isEmpty(): Return true as the stack is empty.
- push(9): Insert 9 at the top of the stack. Stack = [9].
- isFull(): Return true as the stack is full. Capacity = 1.

---

## Constraints:

- 1 ≤ n ≤ 10³
- 1 ≤ q ≤ 10³
- 0 ≤ x ≤ 10⁵
