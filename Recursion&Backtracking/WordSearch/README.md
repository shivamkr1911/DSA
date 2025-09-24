# Word Search

**Problem Statement:**  
Given an m x n grid of characters `board` and a string `word`, return `true` if `word` exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

---

### Example 1:

![Example1](Example1.png)

**Input:**  
board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"

**Output:**  
true

---

### Example 2:

![Example2](Example2.png)

**Input:**  
board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"

**Output:**  
true

---

### Example 3:

![Example3](Example3.png)

**Input:**  
board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"

**Output:**  
false

---

### Constraints:

- m == board.length
- n == board[i].length
- 1 <= m, n <= 6
- 1 <= word.length <= 15
- board and word consist of only lowercase and uppercase English letters.

---

### Follow Up:

Could you use search pruning to make your solution faster with a larger board?
