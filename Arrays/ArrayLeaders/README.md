# Array Leaders

You are given an array `arr` of positive integers. Your task is to find all the leaders in the array. An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.

---

## Example 1:

**Input:**  
arr = [16, 17, 4, 3, 5, 2]  
**Output:**  
[17, 5, 2]  
**Explanation:**  
There is nothing greater on the right side of 17, 5, and 2.

---

## Example 2:

**Input:**  
arr = [10, 4, 2, 4, 1]  
**Output:**  
[10, 4, 4, 1]  
**Explanation:**  
Both of the 4s are leaders, as an equal element is also allowed on the right side.

---

## Example 3:

**Input:**  
arr = [5, 10, 20, 40]  
**Output:**  
[40]  
**Explanation:**  
When an array is sorted in increasing order, only the rightmost element is a leader.

---

## Example 4:

**Input:**  
arr = [30, 10, 10, 5]  
**Output:**  
[30, 10, 10, 5]  
**Explanation:**  
When an array is sorted in non-increasing order, all elements are leaders.

---

## Constraints:

- 1 <= arr.size() <= 10^6
- 0 <= arr[i] <= 10^6
