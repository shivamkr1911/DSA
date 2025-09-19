# Subset Sums

Given an array `arr` of integers, return the sums of all subsets in the list.  
Return the sums in any order.

---

## Example 1

**Input:**  
arr = [2, 3]

**Output:**  
[0, 2, 3, 5]

**Explanation:**

- When no elements are taken → Sum = 0
- When only 2 is taken → Sum = 2
- When only 3 is taken → Sum = 3
- When elements 2 and 3 are taken → Sum = 2 + 3 = 5

---

## Example 2

**Input:**  
arr = [1, 2, 1]

**Output:**  
[0, 1, 1, 2, 2, 3, 3, 4]

**Explanation:**  
The possible subset sums are:

- 0 (no elements)
- 1 (either of the 1's)
- 2 (the element 2)
- Combinations leading to sums 2, 3, and 4.

---

## Example 3

**Input:**  
arr = [5, 6, 7]

**Output:**  
[0, 5, 6, 7, 11, 12, 13, 18]

**Explanation:**  
The possible subset sums are:

- 0 (no elements)
- 5, 6, 7 individually
- 5 + 6 = 11, 6 + 7 = 13, 5 + 7 = 12
- 5 + 6 + 7 = 18

---

## Constraints

- 1 ≤ arr.length ≤ 15
- 0 ≤ arr[i] ≤ 10⁴
