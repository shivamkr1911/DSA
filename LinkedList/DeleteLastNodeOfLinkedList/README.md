# Delete Last Node of Linked List

Given a singly linked list, your task is to delete the **last node** of the linked list and return the head of the modified linked list.

If the linked list is empty or has only one node, the function should return `NULL`.

---

### Example 1:
```
Input:
LinkedList: 1->2->3->4->5
Output: 1->2->3->4
Explanation: The last node (5) is deleted.
```

### Example 2:
```
Input:
LinkedList: 10->20
Output: 10
Explanation: The last node (20) is deleted.
```

### Example 3:
```
Input:
LinkedList: 50
Output: NULL
Explanation: Only one node present, so after deletion, the list becomes empty.
```

---

### Your Task:
You need to complete the function `deleteLastNode()` which takes the head of the linked list as input and returns the head of the modified linked list after deleting the last node.

---

### Expected Time Complexity:
- O(n)

### Expected Auxiliary Space:
- O(1)

---

### Constraints:
- 0 ≤ Number of nodes ≤ 10⁴  
- 1 ≤ Node->data ≤ 10⁵
