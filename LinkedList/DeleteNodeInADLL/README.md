# Delete Node in a Doubly Linked List

Given a Doubly Linked List and a position, the task is to delete a node from the given position (position starts from 1) in the doubly linked list and return the head of the modified doubly linked list.

---

### Example 1:
```
Input:
LinkedList = 1 <--> 3 <--> 4, x = 3
Output:
1 <--> 3

Explanation:
After deleting the node at position 3 (position starts from 1), the linked list will now be 1 <--> 3.
```

### Example 2:
```
Input:
LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
Output:
5 <--> 2 <--> 9
```

---

### Constraints:
- 2 ≤ size of the linked list ≤ 10⁶  
- 1 ≤ x ≤ size of the linked list  
- 1 ≤ node->data ≤ 10⁴
