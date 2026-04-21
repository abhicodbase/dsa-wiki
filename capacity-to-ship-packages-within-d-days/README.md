# Capacity To Ship Packages Within D Days

- **Difficulty:** Medium
- **Categories:** Array, Binary Search
- **Time Complexity:** O(N log(sum))
- **Space Complexity:** O(1)

---

Find the minimum ship capacity to ship all packages within d days, maintaining order.

---

## Approach: Binary Search on Capacity

Binary search capacity in [max(weights), sum(weights)]. For each capacity, simulate greedily: count days needed. If ≤ d, it's a valid capacity.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/capacity-to-ship-packages-within-d-days)
- [LeetCode](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)
