# Jump Game II

**LeetCode #45** · [LeetCode](https://leetcode.com/problems/jump-game-ii/) · [NeetCode](https://neetcode.io/problems/jump-game-ii)

- **Difficulty:** Medium
- **Categories:** Array, Dynamic Programming, Greedy
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

## Problem Statement

You are given a 0-indexed array of integers `nums` of length `n`. You are initially positioned at `nums[0]`.

Each element `nums[i]` represents the maximum length of a forward jump from index `i`. In other words, if you are at `nums[i]`, you can jump to any `nums[i + j]` where:
- `0 <= j <= nums[i]` and
- `i + j < n`

Return the minimum number of jumps to reach `n - 1`. The test cases are generated such that you can always reach the last index.

**Examples:**
```
Input:  nums = [2,3,1,1,4]  →  Output: 2
Input:  nums = [2,3,0,1,4]  →  Output: 2
```

---

## Intuition

This problem can be visualized as finding the shortest path in an unweighted directed graph, where each index is a node and jumps represent edges. Since the edges have uniform weight (each jump costs exactly 1), we can perform a Breadth-First Search (BFS) starting from index 0. By using a DP array to store the minimum jumps to each index, we propagate the shortest distance forward index by index. Because we process nodes in increasing order of index, the first time we visit any forward index, we are guaranteed to have reached it in the minimum number of jumps.

---

## Approach: BFS-Style Dynamic Programming

1. **State Definition**: We define a `dp` array of size $N$, where `dp[i]` represents the minimum jumps to reach index `i`. We initialize all elements to `-1` (unvisited) and set `dp[0] = 0`.
2. **Sequential Propagation**: We iterate through each index `i` from `0` to `N-1`.
3. **Reachability Safeguard**: If `dp[i]` is `-1`, it means index `i` is unreachable, so we skip it.
4. **BFS Jump Expansion**: From index `i`, we can jump forward to any index `i + j` (where $1 \le j \le nums[i]$).
   - If `dp[i + j]` is already set (i.e. `!= -1`), we skip it because it was already reached earlier with a smaller or equal jump count.
   - Otherwise, we set `dp[i + j] = dp[i] + 1`.
5. **Early Exit**: If `i + j` reaches the last index `N-1`, we immediately return `dp[i + j]` since BFS guarantees this is the minimum path.

```cpp
// Simplified iterative BFS-DP logic
int jump(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;

    vector<int> dp(n, -1);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        if (dp[i] == -1) continue; // Skip unreachable nodes
        
        for (int j = 1; j <= nums[i]; j++) {
            if (i + j < n) {
                if (dp[i + j] != -1) continue; // Already visited
                
                dp[i + j] = dp[i] + 1;
                if (i + j == n - 1) return dp[i + j];
            } else {
                break;
            }
        }
    }
    return -1;
}
```

---

## Approach 2: Greedy (BFS Range Extension)

Instead of using a full DP array, we can track the maximum reachable range dynamically. We update the farthest reachable index at each step. When the iteration index reaches the current jump boundary `curEnd`, we increment the jump count and set the boundary to `farthest`.

### Why the loop stops at `N - 2` (not `N - 1`)
We never need to jump from the last index — just reach it. If we included $i = N - 1$ in the loop, we would increment jumps one extra time unnecessarily whenever `curEnd == N - 1`.

### Trace on `[2, 3, 1, 1, 4]`

| $i$ | `nums[i]` | `farthest` | $i ==$ `curEnd`? | `jumps` | `curEnd` |
|---|---|---|---|---|---|
| 0 | 2 | 2 | **yes** | 1 | 2 |
| 1 | 3 | 4 | no | 1 | 2 |
| 2 | 1 | 4 | **yes** | 2 | 4 |
| 3 | 1 | 4 | no | 2 | 4 |

**Loop ends. Answer = 2. ✓**

```cpp
// Simplified greedy range expansion logic
int jump(vector<int>& nums) {
    int jumps = 0, curEnd = 0, farthest = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        if (i == curEnd) {
            jumps++;
            curEnd = farthest;
        }
    }
    return jumps;
}
```

---

## Complexity

### Approach 1: BFS-Style DP
- **Time Complexity:** $O(N^2)$ worst-case. In the worst case (e.g., all values $\ge N$), we might check up to $O(N)$ forward indices for each of the $N$ steps.
- **Space Complexity:** $O(N)$ to allocate the `dp` array.

### Approach 2: Greedy (Optimal)
- **Time Complexity:** $O(N)$ since we perform a single linear pass over the array.
- **Space Complexity:** $O(1)$ auxiliary space.

---

## Edge Cases

| Scenario | Result |
|---|---|
| Single element `nums = [0]` | `0` (already at the end) |
| Max jumps at index 0 `nums = [5, 1, 1, 1, 1, 1]` | `1` (can jump directly to the end) |
| Zero jumps at unreachable locations | Handled by skipping unreachable nodes with `dp[i] == -1` |

---

## Files

| File | Description |
|---|---|
| [`greedy.cpp`](./greedy.cpp) | Optimal O(N) time and O(1) space Greedy solution |
| [`bfs-dp.cpp`](./bfs-dp.cpp) | BFS-style dynamic programming solution |
| [`README.md`](./README.md) | Problem documentation and walkthrough |

---

## Related Problems

- [Jump Game (LC #55)](https://leetcode.com/problems/jump-game/) — The predecessor where we only need to check if reaching the end is possible.
- [Minimum Path Sum (LC #64)](https://leetcode.com/problems/minimum-path-sum/) — Another DP problem focused on minimizing paths.
- [Shortest Path in Binary Matrix (LC #1091)](https://leetcode.com/problems/shortest-path-in-binary-matrix/) — Classic BFS for finding shortest paths.
