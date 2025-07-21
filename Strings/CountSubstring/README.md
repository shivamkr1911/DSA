# Count Substring

Given string `s` consisting only a,b,c. Return the number of substrings containing at least one occurrence of all these characters a, b, and c.

---

### Example 1:

**Input:**  
abcabc  
**Output:**  
10  
**Explanation:**  
The required substrings are "abc", "abca", "abcab", "abcabc",  
"bca", "bcab", "bcabc", "cab", "cabc" and "abc".

---

### Example 2:

**Input:**  
aaacb  
**Output:**  
3

---

### Your Task:  
You don't have to read input or print anything. Your task is to complete the function `countSubstring()` which takes the string `s` and returns the count of substrings having at least a, b, c.

---

### Expected Time Complexity:  
O(n)  

### Expected Space Complexity:  
O(1)

---

### Constraints:
- 3 <= s.length <= 5 x 10^4  
- s only contains a, b, c.
