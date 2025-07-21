# Delete Characters to Make Fancy String

A **fancy string** is a string where no **three consecutive characters** are the same.

Given a string `s`, delete the **minimum number of characters** so that the final string becomes fancy.

The result will always be **unique**.

---

### Example 1

Input: s = "leeetcode"  
Output: "leetcode"  
Explanation:  
Remove one 'e' from the group "eee" to get "leetcode".  
Now, no three consecutive characters are the same.

---

### Example 2

Input: s = "aaabaaaa"  
Output: "aabaa"  
Explanation:  
First remove one 'a' from "aaa" → "aabaaaa"  
Then remove two 'a's from "aaaa" → "aabaa"  
Now it's a fancy string.

---

### Example 3

Input: s = "aab"  
Output: "aab"  
Explanation:  
No three consecutive characters are equal, so return the string as is.

---

### Constraints

- 1 ≤ s.length ≤ 100000  
- s contains only lowercase English letters.
