# Count of Smaller Numbers After Self

- **Difficulty:** Hard
- **Categories:** Array, Binary Search, Divide and Conquer, Binary Indexed Tree
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(N)

---

Given an integer array, return a count array where count[i] is the number of elements to the right of nums[i] that are smaller than it.

---

## Approach: Merge Sort (Modified)

During merge sort, when elements from the right half are merged before an element from the left half, increment that left element's count. Track original indices.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/count-of-smaller-numbers-after-self)
- [LeetCode](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)
