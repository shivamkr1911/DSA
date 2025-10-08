# Stack using Linked List

Implement a **Stack** using a Linked List. This stack has no fixed capacity and can grow dynamically until memory is available.

The Stack must support the following operations:

1. **push(x)**: Insert an element `x` at the top of the stack.
2. **pop()**: Remove the element from the top of the stack.
3. **peek()**: Return the top element if not empty, else -1.
4. **isEmpty()**: Return `true` if the stack is empty, else `false`.
5. **size()**: Return the number of elements currently in the stack.

There will be a sequence of queries `queries[][]`. The queries are represented in numeric form:

- `1 x` : Call `push(x)`
- `2` : Call `pop()`
- `3` : Call `peek()`
- `4` : Call `isEmpty()`
- `5` : Call `size()`

You just have to implement the functions **push, pop, peek, isEmpty, and size**. The driver code will handle the input and output.

---

## Example 1:

Input:  
q = 7, queries[][] = [[1, 5], [1, 3], [1, 4], [3], [2], [5], [4]]

Output: [4, 2, false]

Explanation:

- push(5): Insert 5 at the top of the stack.
- push(3): Insert 3 at the top of the stack.
- push(4): Insert 4 at the top of the stack.
- peek(): Return the top element i.e 4.
- pop(): Remove the top element 4 from the stack.
- size(): Stack contains 2 elements, return 2.
- isEmpty(): Stack is not empty, return false.

---

## Example 2:

Input:  
q = 4, queries[][] = [[4], [3], [1, 10], [5]]

Output: [true, -1, 1]

Explanation:

- isEmpty(): Stack is empty, return true.
- peek(): Stack is empty, return -1.
- push(10): Insert 10 at the top of the stack.
- size(): Stack contains 1 element, return 1.

---

## Constraints:

- 1 ≤ number of queries ≤ 10³
- 0 ≤ x ≤ 10⁵
