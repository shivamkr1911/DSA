# Queue Using Array

Implement a **Queue** using an array, where the size of the array `n` is given.

The Queue must support the following operations:

1. **enqueue(x)**: Insert an element `x` at the rear of the queue.
2. **dequeue()**: Remove the element from the front of the queue.
3. **getFront()**: Return the front element if not empty, else -1.
4. **getRear()**: Return the rear element if not empty, else -1.
5. **isEmpty()**: Return `true` if the queue is empty, else `false`.
6. **isFull()**: Return `true` if the queue is full, else `false`.

There will be a sequence of queries `queries[][]`. The queries are represented in numeric form:

- `1 x` : Call `enqueue(x)`
- `2` : Call `dequeue()`
- `3` : Call `getFront()`
- `4` : Call `getRear()`
- `5` : Call `isEmpty()`
- `6` : Call `isFull()`

You just have to implement the functions **enqueue, dequeue, getFront, getRear, isEmpty, and isFull**. The driver code will handle the output.

---

## Example 1:

Input:  
n = 3, q = 7, queries[][] = [[1, 5], [1, 3], [1, 4], [3], [2], [5], [4]]

Output: [5, false, 4]

Explanation:

- enqueue(5): Insert 5 at the rear of the queue.
- enqueue(3): Insert 3 at the rear of the queue.
- enqueue(4): Insert 4 at the rear of the queue.
- getFront(): Return the front element i.e 5.
- dequeue(): Remove the front element 5 from the queue.
- isEmpty(): Return false as the queue is not empty.
- getRear(): Return the rear element i.e 4.

---

## Example 2:

Input:  
n = 2, q = 4, queries[][] = [[4], [1, 3], [1, 7], [6]]

Output: [-1, true]

Explanation:

- getRear(): As the queue is empty return -1.
- enqueue(3): Insert 3 at the rear of the queue.
- enqueue(7): Insert 7 at the rear of the queue.
- isFull(): Return true as the queue is full i.e containing 2 elements.

---

## Constraints:

- 1 ≤ n ≤ 10³
- 1 ≤ number of queries ≤ 10³
- 0 ≤ x ≤ 10⁵
