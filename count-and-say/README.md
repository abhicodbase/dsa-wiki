# Count and Say

- **Difficulty:** Medium
- **Categories:** String
- **Time Complexity:** O(2^N)
- **Space Complexity:** O(2^N)

---

The count-and-say sequence: 1 → '1', 2 → '11', 3 → '21', etc. Return the n-th term.

---

## Approach: Iterative RLE Simulation

Start from '1'. For each iteration, scan the current string and run-length encode it: count consecutive identical digits and write count+digit.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/count-and-say)
- [LeetCode](https://leetcode.com/problems/count-and-say/)
