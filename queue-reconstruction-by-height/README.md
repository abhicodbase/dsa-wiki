# Queue Reconstruction by Height

- **Difficulty:** Medium
- **Categories:** Array, Binary Indexed Tree, Segment Tree, Sorting, Greedy
- **Time Complexity:** O(N^2)
- **Space Complexity:** O(log N)

---

Reconstruct a queue from [height, k] pairs where k = number of people in front with height >= current person.

---

## Approach: Sort + Insert Greedily

Sort by height descending, then by k ascending. Insert each person at index k. Since taller people are inserted first, inserting at index k correctly places them.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/queue-reconstruction-by-height)
- [LeetCode](https://leetcode.com/problems/queue-reconstruction-by-height/)
