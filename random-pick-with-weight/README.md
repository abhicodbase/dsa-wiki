# Random Pick with Weight

- **Difficulty:** Medium
- **Categories:** Math, Binary Search, Prefix Sum, Randomized
- **Time Complexity:** O(log N) pick, O(N) build
- **Space Complexity:** O(N)

---

Given weights, implement pickIndex() that returns an index with probability proportional to its weight.

---

## Approach: Prefix Sum + Binary Search

Build prefix sum array. Pick a random float in [0, totalWeight). Binary search for first prefix sum > random value. Return that index.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/random-pick-with-weight)
- [LeetCode](https://leetcode.com/problems/random-pick-with-weight/)
