# Find Most Frequent Vowel and Consonant

You are given a string `s` consisting of lowercase English letters (`'a'` to `'z'`).

Your task is to:

- Find the **vowel** (`a, e, i, o, u`) with the maximum frequency.
- Find the **consonant** (all other letters excluding vowels) with the maximum frequency.
- Return the **sum** of the two frequencies.

**Note:**

- If multiple vowels or consonants have the same maximum frequency, you may choose any one of them.
- If there are no vowels or no consonants in the string, consider their frequency as `0`.
- The frequency of a letter `x` is the number of times it occurs in the string.

---

### Example 1:

```
Input:
s = "successes"

Output:
6
```

**Explanation:**

- Vowels: `'u'` → 1, `'e'` → 2 → max = 2
- Consonants: `'s'` → 4, `'c'` → 2 → max = 4
- Result = 2 + 4 = 6

---

### Example 2:

```
Input:
s = "aeiaeia"

Output:
3
```

**Explanation:**

- Vowels: `'a'` → 3, `'e'` → 2, `'i'` → 2 → max = 3
- No consonants, so max consonant frequency = 0
- Result = 3 + 0 = 3

---

### Constraints:

- 1 <= s.length <= 100
- s consists of lowercase English letters only
