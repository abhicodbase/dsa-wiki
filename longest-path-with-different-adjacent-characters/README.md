# Longest Path with Different Adjacent Characters

**LeetCode #2246** · [LeetCode](https://leetcode.com/problems/longest-path-with-different-adjacent-characters/) · [NeetCode](https://neetcode.io/problems/longest-path-with-different-adjacent-characters)

- **Difficulty:** Hard
- **Categories:** Array, String, Tree, Depth-First Search, Graph
- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(N)`

---

## Problem Statement

You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node `0` consisting of `n` nodes numbered from `0` to `n - 1`. The tree is represented by a 0-indexed array `parent` of size `n`, where `parent[i]` is the parent of node `i`. Since node `0` is the root, `parent[0] == -1`.

You are also given a string `s` of length `n`, where `s[i]` is the character assigned to node `i`.

Return the length of the **longest path** in the tree such that no two adjacent nodes on the path have the same character assigned to them.

---

## Intuition

A path in a tree can be viewed as having a "turning point" (the highest node on the path). For any node, the longest valid path where that node is the highest point is formed by:
1. The longest valid path coming from one of its child subtrees.
2. The second longest valid path coming from another of its child subtrees.
3. The node itself.

Thus, for each node, we want to find the top two longest valid paths among all its children. A path from a child is valid only if `s[child] != s[parent]`. 

We can compute this using a post-order Depth-First Search (DFS):
- The DFS function returns the longest single path extending down from the current node.
- At each node, we update a global maximum (`ans`) with `best1 + best2 + 1`, representing the longest path that "turns" at this node.

---

## Common Pitfalls & Fixes

When implementing this solution in C++, several performance bottlenecks and logic errors can easily lead to Time Limit Exceeded (TLE) or incorrect answers:

### 1. Map Copying on Every Recursive Call
Passing adjacency lists by value in recursive calls triggers full copies at every level of recursion. In a deep tree of $10^5$ nodes, this causes $O(N^2)$ memory copying.
* **Fix:** Pass adjacency structures strictly by reference (`&`).

### 2. Overhead of Hash Maps vs. Arrays
Using `unordered_map<int, vector<int>>` introduces hashing overhead and pointer chasing. Since the tree nodes are numbered from `0` to `n - 1`, we can use a direct-indexed `vector<vector<int>>`.
* **Fix:** Use `vector<vector<int>>` for $O(1)$ lookup with no hash collisions.

### 3. Incorrect `best2` Extraction from Priority Queue
Using a complex `while` loop to extract elements from a priority queue can lead to infinite loops or incorrect extraction of duplicate values.
* **Fix:** Use two separate `if (!pq.empty())` pops, or simply maintain two tracking variables (`best1` and `best2`) on the fly during the loop.

### 4. String Copying on Every DFS Frame
Passing the labels string `s` by value copies the string on every function call.
* **Fix:** Pass the string by reference (`const string& s`).

### Summary of Fixes

| Pitfall / Issue | Naive Code | Optimized Fix |
| :--- | :--- | :--- |
| **Map Copying** | `unordered_map<int, vector<int>> mp` | `const vector<vector<int>>& adj` (passed by reference) |
| **Lookup Overhead** | `unordered_map<...>` | `vector<vector<int>>` (direct index lookup) |
| **Wrong `best2` Extraction** | `while` loop with `if(best1==0)` check | Two tracking variables, or separate `if(!pq.empty())` pops |
| **String Copying** | `string s` (passed by value) | `const string& s` (passed by reference) |

---

## Approach: Post-Order DFS (Single-Pass)

We build the adjacency tree and execute a DFS. To find the top 2 child path lengths efficiently, we update two variables `best1` and `best2` in $O(1)$ time for each child:

```cpp
class Solution {
public:
    int dfs(int source, const vector<vector<int>>& adj, const string& s, int& ans) {
        int best1 = 0; // Longest path from child
        int best2 = 0; // Second longest path from child

        for (int child : adj[source]) {
            int childLen = dfs(child, adj, s, ans);
            
            // Sibling paths are invalid if the labels match
            if (s[source] == s[child]) continue;
            
            // Dynamically maintain the top 2 longest paths
            if (childLen > best1) {
                best2 = best1;
                best1 = childLen;
            } else if (childLen > best2) {
                best2 = childLen;
            }
        }
        
        // Update global path length with the current node as the peak/turning point
        ans = max(ans, best1 + best2 + 1);
        
        // Return the longest single arm extending downwards
        return best1 + 1;
    }   

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                adj[parent[i]].push_back(i);
            }
        }
        
        int ans = 1;
        dfs(0, adj, s, ans);
        return ans;
    }
};
```

---

## Complexity

| | Value | Reason |
| :--- | :--- | :--- |
| **Time** | `O(N)` | We visit every node in the tree exactly once. The work done per node is proportional to its number of children, totaling `O(N)` across all nodes. |
| **Space** | `O(N)` | The recursion stack depth is `O(H)` where `H` is the tree height (`H = N` in the worst case). The adjacency list consumes `O(N)` space. |

---

## Edge Cases

| Scenario | Behavior |
| :--- | :--- |
| Single node tree (`n = 1`) | No children are explored; DFS returns `1`, which is correct. |
| Line tree with all different characters | The path length will equal the total number of nodes `n`. |
| Line tree with all identical characters | Every parent-child link is skipped; the path length will be `1`. |
| Balanced tree where all siblings have same label as parent | All paths are blocked at the parent; return `1`. |

---

## Files

| File | Description |
| :--- | :--- |
| [`optimized-dfs.cpp`](./optimized-dfs.cpp) | Optimized C++ DFS solution with no hashing or copy overhead |

---

## Related Problems

- [LC #124 — Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/) — analogous pattern of using top 2 paths from children to update a global maximum
- [LC #543 — Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/) — similar logic of calculating tree diameter using tree heights
- [LC #687 — Longest Univalue Path](https://leetcode.com/problems/longest-univalue-path/) — matching labels condition along tree paths
