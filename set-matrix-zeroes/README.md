# Set Matrix Zeroes

Given an `m x n` integer matrix, if an element is `0`, set its entire row and column to `0`. Do it in-place.

### Complexity
- **Time Complexity**: O(m × n)
- **Space Complexity**: O(1)

---
### Approach
Use the first row and first column as marker arrays (instead of extra space). First, record whether the first row/column themselves contain zeros. Then, for each cell `(i, j)` where `i > 0` and `j > 0`, if `matrix[i][j] == 0`, mark `matrix[i][0]` and `matrix[0][j]` as 0. Finally, zero out cells based on markers, and handle the first row/column last.
