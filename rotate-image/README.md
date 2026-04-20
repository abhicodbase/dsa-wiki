# Rotate Image

Given an `n x n` 2D matrix representing an image, rotate the image by 90 degrees clockwise in-place.

### Complexity
- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)

---
### Approach
Two-step in-place transformation:
1. **Transpose** the matrix: swap `matrix[i][j]` with `matrix[j][i]` for all `i < j`.
2. **Reverse each row**: reverse the elements of every row.

These two steps together achieve a 90-degree clockwise rotation.
