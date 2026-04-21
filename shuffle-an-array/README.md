# Shuffle an Array

- **Difficulty:** Medium
- **Categories:** Array, Math, Randomized
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Implement reset() and shuffle() for an array. Shuffle produces a random permutation with equal probability.

---

## Approach: Fisher-Yates Algorithm

For i from n-1 to 1: swap nums[i] with nums[random(0, i)]. Produces uniformly random permutation in O(N).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/shuffle-an-array)
- [LeetCode](https://leetcode.com/problems/shuffle-an-array/)
