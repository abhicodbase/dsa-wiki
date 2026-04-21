# Minimum Number of Refueling Stops

- **Difficulty:** Hard
- **Categories:** Array, Dynamic Programming, Greedy, Heap
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(N)

---

A car starts with a fuel tank. At each stop you can refuel. Find minimum stops to reach the target.

---

## Approach: Greedy Max-Heap

Greedily travel as far as possible. When out of fuel, refuel from the largest tank seen so far (max-heap). Count refuels. If no more options and cannot reach target, return -1.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/minimum-number-of-refueling-stops)
- [LeetCode](https://leetcode.com/problems/minimum-number-of-refueling-stops/)
