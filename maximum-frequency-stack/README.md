# Maximum Frequency Stack

- **Difficulty:** Hard
- **Categories:** Hash Table, Stack, Design, Ordered Set
- **Time Complexity:** O(1) push/pop
- **Space Complexity:** O(N)

---

Design a stack that pushes elements and pops the most frequent element. Ties broken by recency.

---

## Approach: Frequency Map + Group Stack

Map element→frequency and frequency→stack of elements. Track maxFreq. Push: update freq, push to freq group, update maxFreq. Pop: pop from maxFreq group, update freq, decrement maxFreq if group empty.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/maximum-frequency-stack)
- [LeetCode](https://leetcode.com/problems/maximum-frequency-stack/)
