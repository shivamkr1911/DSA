# Queue using Linked List

Implement a **Queue** using a Linked List. This queue has no fixed capacity and can grow dynamically until memory is available.

The Queue must support the following operations:

1. **enqueue(x)**: Insert an element `x` at the rear of the queue.
2. **dequeue()**: Remove the element from the front of the queue.
3. **getFront()**: Return the front element if not empty, else -1.
4. **isEmpty()**: Return `true` if the queue is empty, else `false`.
5. **size()**: Return the number of elements currently in the queue.

There will be a sequence of queries `queries[][]`. The queries are represented in numeric form:

- `1 x` : Call `enqueue(x)`
- `2` : Call `dequeue()`
- `3` : Call `getFront()`
- `4` : Call `isEmpty()`
- `5` : Call `size()`

You just have to implement the functions **enqueue, dequeue, getFront, isEmpty, and size**. The driver code will handle the input and output.

---

## Example 1:

Input:  
q = 7, queries[][] = [[1, 5], [1, 3], [1, 4], [3], [2], [5], [4]]

Output: [5, 2, false]

Explanation:

- enqueue(5): Insert 5 at the rear of the queue.
- enqueue(3): Insert 3 at the rear of the queue.
- enqueue(4): Insert 4 at the rear of the queue.
- getFront(): Return the front element i.e 5.
- dequeue(): Remove the front element 5 from the queue.
- size(): Queue now has 2 elements.
- isEmpty(): Queue is not empty, return false.

---

## Example 2:

Input:  
q = 4, queries[][] = [[4], [3], [1, 10], [5]]

Output: [true, -1, 1]

Explanation:

- isEmpty(): Queue is empty, return true.
- getFront(): Queue is empty, return -1.
- enqueue(10): Insert 10 at the rear of the queue.
- size(): Queue contains 1 element, return 1.

---

## Constraints:

- 1 ≤ number of queries ≤ 10³
- 0 ≤ x ≤ 10⁵
