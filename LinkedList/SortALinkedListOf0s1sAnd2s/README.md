# Sort a Linked List of 0s, 1s, and 2s

Given the head of a linked list where nodes can contain values **0**, **1**, and **2** only.  
Your task is to rearrange the list so that all **0s** appear at the beginning, followed by all **1s**, and all **2s** are placed at the end.

---

## Examples

**Example 1:**

**Input:**  
1 → 2 → 2 → 1 → 2 → 0 → 2 → 2  

**Output:**  
0 → 1 → 1 → 2 → 2 → 2 → 2 → 2  

**Explanation:**  
All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.

---

**Example 2:**

**Input:**  
2 → 2 → 0 → 1  

**Output:**  
0 → 1 → 2 → 2  

**Explanation:**  
After arranging all the 0s, 1s and 2s in the given format, the output will be 0 → 1 → 2 → 2.

---

## Constraints

- 1 ≤ number of nodes ≤ 10⁶  
- 0 ≤ node->data ≤ 2
