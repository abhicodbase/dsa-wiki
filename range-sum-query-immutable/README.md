# Range Sum Query - Immutable

- **Difficulty:** Easy
- **Categories:** Array, Design, Prefix Sum
- **Time Complexity:** O(1) query, O(N) build
- **Space Complexity:** O(N)

---

Implement NumArray class: constructor takes nums array, sumRange(i,j) returns sum of elements between indices i and j inclusive.

---

## Approach: Prefix Sum Array

Precompute prefix[i] = sum of nums[0..i-1]. Then sumRange(i,j) = prefix[j+1] - prefix[i] in O(1).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/range-sum-query-immutable)
- [LeetCode](https://leetcode.com/problems/range-sum-query-immutable/)
