# Count of Range Sum

- **Difficulty:** Hard
- **Categories:** Array, Binary Search, Divide and Conquer, Binary Indexed Tree, Merge Sort, Segment Tree, Ordered Set
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(N)

---

Count the number of range sums in [lower, upper] inclusive.

---

## Approach: Merge Sort on Prefix Sums

Compute prefix sums. During merge sort, count pairs (i,j) where prefix[j] - prefix[i] is in [lower, upper]. Use two-pointer merge counting.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/count-of-range-sum)
- [LeetCode](https://leetcode.com/problems/count-of-range-sum/)
