# Delete All Occurrences of a Given Key in a Doubly Linked List

You are given the head_ref of a doubly Linked List and a key. Your task is to delete all occurrences of the given key if it is present and return the new DLL.

---

### Example 1:

```
Input: 2<->2<->10<->8<->4<->2<->5<->2
Key: 2
Output: 10<->8<->4<->5
Explanation: All occurrences of 2 have been deleted.
```

### Example 2:

```
Input: 9<->1<->3<->4<->5<->1<->8<->4
Key: 9
Output: 1<->3<->4<->5<->1<->8<->4
Explanation: All occurrences of 9 have been deleted.
```

---

### Your Task:

Complete the function `void deleteAllOccurOfX(struct Node** head_ref, int key)`, which takes the reference of the head pointer and an integer value `key`. Delete all occurrences of the key from the given DLL.

- **Expected Time Complexity:** O(N)
- **Expected Auxiliary Space:** O(1)

---

### Constraints:

- 1 <= Number of Nodes <= 10⁵
- 0 <= Node Value <= 10⁹
