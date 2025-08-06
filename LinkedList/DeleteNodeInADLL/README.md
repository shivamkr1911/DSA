# Insertion at Doubly Linked List

Given the head of a doubly-linked list, a position `p`, and an integer `x`, the task is to add a new node with value `x` at the position just after the `p`ᵗʰ node in the doubly linked list and return the head of the updated list.

**Note:**
The position is 0-based indexed.

---

### Example 1:

```
Input:
p = 2, x = 6
Linked List:
2 <-> 4 <-> 5

Output:
2 <-> 4 <-> 5 <-> 6

Explanation:
Insert a node of value 6 after the 2nd node.
```

### Example 2:

```
Input:
p = 0, x = 44
Linked List:
1 <-> 2 <-> 3 <-> 4

Output:
1 <-> 44 <-> 2 <-> 3 <-> 4

Explanation:
Insert a node of value 44 after the 0th node.
```

---

### Constraints:

* 0 ≤ p < list size ≤ 10⁴
* 1 ≤ x ≤ 10⁴
