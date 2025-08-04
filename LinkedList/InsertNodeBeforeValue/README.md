# Insert Node Before Value

You are given the `head` of a singly linked list with unique integer elements.

Also, two integers `x` and `val` are provided.

Your task is to insert a node with value `x` immediately **before** the node with value `val` in the linked list.

**Note:**  
The linked list is guaranteed to always contain a node with the value `val`.

---

### Example:
```
Input:
Linked List: 1 -> 3 -> 5 -> 7
x: 4
val: 5

Output:
1 -> 3 -> 4 -> 5 -> 7

Explanation:
In the provided linked list, we insert '4' immediately before '5'.
```

---

### Expected Time Complexity:
- O(n)

### Expected Auxiliary Space:
- O(1)

---

### Constraints:
- 1 ≤ n ≤ 10⁴  
- 1 ≤ x, val, linked list node values ≤ 10⁴  
- The linked list is guaranteed to contain a node with the value `val`.
