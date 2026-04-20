# Spiral Matrix

Given an `m x n` matrix, return all elements in spiral order (clockwise from the top-left).

### Complexity
- **Time Complexity**: O(m × n)
- **Space Complexity**: O(1) (excluding output)

---
### Approach
Maintain four boundaries: `top`, `bottom`, `left`, `right`. In each iteration, traverse the top row left-to-right, right column top-to-bottom, bottom row right-to-left, and left column bottom-to-top. After each traversal, shrink the respective boundary inward. Repeat until boundaries cross.
