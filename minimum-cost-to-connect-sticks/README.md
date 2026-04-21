# Minimum Cost to Connect Sticks

- **Difficulty:** Medium
- **Categories:** Array, Greedy, Heap, Priority Queue
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(N)

---

Connect n sticks into one. Cost to connect two sticks = their total length. Minimize total cost.

---

## Approach: Huffman Coding (Min-Heap)

Use a min-heap. Repeatedly extract two smallest sticks, merge them (add cost = their sum), push the merged stick back. Repeat until one stick remains.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/minimum-cost-to-connect-sticks)
- [LeetCode](https://leetcode.com/problems/minimum-cost-to-connect-sticks/)
