# Furthest Building You Can Reach

- **Difficulty:** Medium
- **Categories:** Array, Greedy, Heap, Priority Queue
- **Time Complexity:** O(N log K)
- **Space Complexity:** O(K)

---

Given building heights, ladders, and bricks, travel as far as possible. Use bricks for small climbs, ladders for large ones.

---

## Approach: Greedy Min-Heap (Replace Bricks with Ladders)

Use a min-heap to track the k largest climbs (where ladders are used). For each upward jump, add to heap. If heap > ladders, pop smallest (use bricks instead). If bricks run out, stop.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/furthest-building-you-can-reach)
- [LeetCode](https://leetcode.com/problems/furthest-building-you-can-reach/)
