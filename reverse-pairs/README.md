# Reverse Pairs

- **Difficulty:** Hard
- **Categories:** Array, Binary Search, Divide and Conquer, Binary Indexed Tree
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(N)

---

Count the number of important reverse pairs (i, j) where i < j and nums[i] > 2 * nums[j].

---

## Approach: Merge Sort

During merge sort, for each element in left half, binary search the right half for the boundary where nums[left] > 2*nums[right]. Count such elements. Then proceed with standard merge.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/reverse-pairs)
- [LeetCode](https://leetcode.com/problems/reverse-pairs/)
