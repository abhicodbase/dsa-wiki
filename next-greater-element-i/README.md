# Next Greater Element I

- **Difficulty:** Easy
- **Categories:** Array, Hash Table, Stack, Monotonic Stack
- **Time Complexity:** O(M+N)
- **Space Complexity:** O(N)

---

Find the next greater element for each element of nums1 in nums2. Next greater = first greater to the right in nums2.

---

## Approach: Monotonic Stack + Hash Map

Process nums2 with a monotonic stack to precompute the next greater element for every value. Look up nums1 values in the map.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/next-greater-element-i)
- [LeetCode](https://leetcode.com/problems/next-greater-element-i/)
