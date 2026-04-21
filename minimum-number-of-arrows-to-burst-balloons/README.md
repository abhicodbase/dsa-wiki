# Minimum Number of Arrows to Burst Balloons

- **Difficulty:** Medium
- **Categories:** Array, Greedy, Sorting
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(1)

---

Shoot arrows vertically to burst all balloons. Find minimum arrows needed. Overlapping balloons can be burst by one arrow.

---

## Approach: Greedy (Sort by End)

Sort balloons by end coordinate. Fire an arrow at each balloon's end. Skip all overlapping balloons that this arrow also bursts. Increment arrow count only when needed for a new balloon.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/minimum-number-of-arrows-to-burst-balloons)
- [LeetCode](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/)
