# Valid Anagram

Given two strings `s` and `t`, determine whether `t` is an anagram of `s`.  
Return **true** if `t` is an anagram of `s`, and **false** otherwise.

---

### Example 1:

```
Input:
s = "anagram", t = "nagaram"

Output:
true
```

### Example 2:

```
Input:
s = "rat", t = "car"

Output:
false
```

---

### Explanation:

Two strings are anagrams if one string can be formed by rearranging the letters of the other.  
For example, `"anagram"` and `"nagaram"` have the same characters with the same frequencies, whereas `"rat"` and `"car"` do not.

---

### Constraints:

- 1 ≤ s.length, t.length ≤ 5 × 10⁴
- `s` and `t` consist of lowercase English letters only.
