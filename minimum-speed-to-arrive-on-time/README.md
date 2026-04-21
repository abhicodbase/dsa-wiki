# Minimum Speed to Arrive on Time

- **Difficulty:** Medium
- **Categories:** Array, Binary Search
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(1)

---

Find minimum integer speed to travel n distances within hour constraint, where each train except the last waits for next integer hour.

---

## Approach: Binary Search on Speed

Binary search speed in [1, 10^7]. For each speed, compute total time: sum ceil(dist/speed) for all but last, add last/speed. Check ≤ hour.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/minimum-speed-to-arrive-on-time)
- [LeetCode](https://leetcode.com/problems/minimum-speed-to-arrive-on-time/)
