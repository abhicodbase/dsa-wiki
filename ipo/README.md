# IPO

- **Difficulty:** Hard
- **Categories:** Array, Greedy, Sorting, Heap, Priority Queue
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(N)

---

Select at most k projects from a list of (profit, capital) to maximize total capital, starting with initial capital w.

---

## Approach: Two Heaps (Greedy)

Min-heap by capital requirement. Max-heap of profits. Push all affordable projects to profit max-heap. Extract max profit project. Repeat k times.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/ipo)
- [LeetCode](https://leetcode.com/problems/ipo/)
