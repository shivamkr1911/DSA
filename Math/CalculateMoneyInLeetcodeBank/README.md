# Calculate Money in Leetcode Bank

Hercy wants to save money for his first car. He deposits money into the Leetcode bank every day.

He starts by putting in **$1 on Monday**, the first day.  
Every day from **Tuesday to Sunday**, he will deposit **$1 more than the previous day**.  
On every subsequent **Monday**, he will deposit **$1 more than the previous Monday**.

Given an integer `n`, return the total amount of money he will have in the Leetcode bank at the end of the `n`th day.

---

### Example 1:

```
Input: n = 4
Output: 10
```

**Explanation:**  
After the 4th day, the total is 1 + 2 + 3 + 4 = 10.

---

### Example 2:

```
Input: n = 10
Output: 37
```

**Explanation:**  
After the 10th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37.  
Notice that on the 2nd Monday, Hercy deposits $2.

---

### Example 3:

```
Input: n = 20
Output: 96
```

**Explanation:**  
After the 20th day, the total is  
(1 + 2 + 3 + 4 + 5 + 6 + 7) +  
(2 + 3 + 4 + 5 + 6 + 7 + 8) +  
(3 + 4 + 5 + 6 + 7 + 8) = 96.

---

### Constraints:

- 1 <= n <= 1000
