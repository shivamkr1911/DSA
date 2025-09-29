# Longest Consecutive Subsequence

Given an array `arr[]` of non-negative integers. Find the length of the longest subsequence such that elements in the subsequence are consecutive integers. The consecutive numbers can be in any order.

---

## Example 1:

**Input:**  
arr[] = [2, 6, 1, 9, 4, 5, 3]  
**Output:**  
6  
**Explanation:**  
The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsequence.

---

## Example 2:

**Input:**  
arr[] = [1, 9, 3, 10, 4, 20, 2]  
**Output:**  
4  
**Explanation:**  
1, 2, 3, 4 is the longest consecutive subsequence.

---

## Example 3:

**Input:**  
arr[] = [15, 13, 12, 14, 11, 10, 9]  
**Output:**  
7  
**Explanation:**  
The longest consecutive subsequence is 9, 10, 11, 12, 13, 14, 15, which has a length of 7.

---

## Constraints:

- 1 ≤ arr.size() ≤ 10^5
- 0 ≤ arr[i] ≤ 10^5
