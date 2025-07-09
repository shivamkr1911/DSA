# Median in a Row-wise Sorted Matrix

Given a row-wise sorted matrix where the number of rows and columns is always odd, find the median of the matrix.

---

### Examples

**Input:** `mat = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]`  
**Output:** `5`  
**Explanation:** Sorting matrix elements gives us {1, 2, 3, 3, 5, 6, 6, 9, 9}. Hence, 5 is median.

---

**Input:** `mat = [[1], [2], [3]]`  
**Output:** `2`  
**Explanation:** Sorting matrix elements gives us {1, 2, 3}. Hence, 2 is median.

---

**Input:** `mat = [[3], [5], [8]]`  
**Output:** `5`  
**Explanation:** Sorting matrix elements gives us {3, 5, 8}. Hence, 5 is median.

---

### Constraints

- `1 <= mat.size(), mat[0].size() <= 400`
- `1 <= mat[i][j] <= 2000`
