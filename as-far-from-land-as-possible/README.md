# As Far From Land As Possible

- **Difficulty:** Medium
- **Categories:** BFS, Brute Force, Grid, Manhattan Distance
- **Time Complexity:**
  - Brute‑Force: `O(W * L)` where `W` is the number of water cells and `L` is the number of land cells (worst‑case `O(N^4)` for an `N×N` grid).
  - BFS: `O(N²)` where `N` is the grid dimension.
- **Space Complexity:** `O(N²)` for the BFS queue (the brute‑force solution uses `O(W + L)` auxiliary space).

---

## Problem Statement
Given an `N × N` grid where `0` represents water and `1` represents land, return the maximum distance from any water cell to the nearest land cell. The distance is the Manhattan distance. If the grid contains only water or only land, return `-1`.

---

## Solutions Overview
### 1️⃣ Brute‑Force (`brute.cpp`)
The brute‑force approach collects coordinates of all water and land cells, then for each water cell computes the Manhattan distance to every land cell, keeping the minimum distance for that water cell. The answer is the maximum of these minima.

**Key Points**
- Straightforward enumeration.
- Easy to understand but inefficient for large grids.

### 2️⃣ BFS (`bfs.cpp`)
Treat all land cells as simultaneous BFS sources. Expand outward level‑by‑level, marking visited water cells. The number of BFS layers processed before the queue empties equals the farthest distance from any water cell to land.

**Key Points**
- Linear time `O(N²)` – each cell is visited at most once.
- Uses the input grid to mark visited water cells (`-1`).

---

## Complexity Analysis
| Approach | Time | Space |
|----------|------|-------|
| Brute‑Force | `O(W·L)` (worst `O(N^4)`) | `O(W+L)` |
| BFS | `O(N²)` | `O(N²)` |

---

## Usage Example (C++)
```cpp
#include "brute.cpp"   // or "bfs.cpp"

int main() {
    vector<vector<int>> grid = {
        {1,0,0},
        {0,0,0},
        {0,0,1}
    };
    Solution sol;
    int ans = sol.maxDistance(grid);
    cout << ans << endl; // Expected output: 2
    return 0;
}
```

---

## Learn More
- [LeetCode – As Far From Land As Possible](https://leetcode.com/problems/as-far-from-land-as-possible/)
- [Discussion & Editorial](https://leetcode.com/problems/as-far-from-land-as-possible/discuss/)
