# 4Sum II

- **Difficulty:** Medium
- **Categories:** Array, Hash Table
- **Time Complexity:** O(N^2)
- **Space Complexity:** O(N^2)

---

Given four integer arrays, count tuples (i,j,k,l) such that nums1[i]+nums2[j]+nums3[k]+nums4[l] == 0.

---

## Approach: Two-Sum on Pair Sums

Compute all pairwise sums of nums1+nums2 and store in a hash map. For each pairwise sum of nums3+nums4, check if its negation exists in the map. Sum up counts.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/4sum-ii)
- [LeetCode](https://leetcode.com/problems/4sum-ii/)
