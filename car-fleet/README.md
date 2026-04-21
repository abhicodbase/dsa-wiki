# Car Fleet

- **Difficulty:** Medium
- **Categories:** Array, Stack, Sorting, Monotonic Stack
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(N)

---

n cars drive to target. If a faster car catches a slower one, they form a fleet. Count number of fleets.

---

## Approach: Sort + Monotonic Stack (Arrival Time)

Sort by position descending. Compute time for each car to reach target. Use a stack: if next car's time ≤ stack top, it joins the fleet (don't push). Each stack entry = one fleet.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/car-fleet)
- [LeetCode](https://leetcode.com/problems/car-fleet/)
