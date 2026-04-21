# Target Sum

- **Difficulty:** Medium
- **Categories:** Array, Dynamic Programming, Backtracking
- **Time Complexity:** O(N×Sum)
- **Space Complexity:** O(Sum)

---

Assign + or - to each number. Count ways to reach the target sum.

---

## Approach: DP (Subset Sum Reduction)

Let P = set of positives, N = set of negatives. P - N = target, P + N = total → P = (target + total)/2. Count subsets summing to P using DP.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/target-sum)
- [LeetCode](https://leetcode.com/problems/target-sum/)
