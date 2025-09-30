# Check K-th Bit

Given two positive integers `n` and `k`, check if the k-th index bit of `n` is set or not.

**Note:** A bit is called set if it is `1`.

---

## Example 1:

**Input:**  
n = 4, k = 0  
**Output:**  
false  
**Explanation:**  
Binary representation of 4 is `100`, in which 0th index bit from LSB is not set. So, return false.

---

## Example 2:

**Input:**  
n = 4, k = 2  
**Output:**  
true  
**Explanation:**  
Binary representation of 4 is `100`, in which 2nd index bit from LSB is set. So, return true.

---

## Example 3:

**Input:**  
n = 500, k = 3  
**Output:**  
false  
**Explanation:**  
Binary representation of 500 is `111110100`, in which 3rd index bit from LSB is not set. So, return false.

---

## Constraints:

- 1 ≤ n ≤ 10^9
- 0 ≤ k ≤ 31
