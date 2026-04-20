# Pacific Atlantic Water Flow

Given an `m x n` island matrix where `heights[r][c]` represents the height at cell `(r, c)`, water can flow to neighboring cells with equal or lower height. Return all cells from which water can flow to both the Pacific and Atlantic oceans.

### Complexity
- **Time Complexity**: O(m × n)
- **Space Complexity**: O(m × n)

---
### Approach
Instead of simulating water flowing downward from each cell (expensive), reverse the problem: do a BFS/DFS from all Pacific border cells and all Atlantic border cells, moving to neighbors with equal or greater height. The answer is the intersection of the two reachable sets.
