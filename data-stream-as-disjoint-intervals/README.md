# Data Stream as Disjoint Intervals

- **Difficulty:** Hard
- **Categories:** Binary Search, Design, Ordered Set
- **Time Complexity:** O(log N) add, O(N) getIntervals
- **Space Complexity:** O(N)

---

Design a data structure that adds integers from a stream and returns them as a sorted list of disjoint intervals.

---

## Approach: Sorted Map / TreeMap

Use a sorted structure (ordered map/set). On addNum: find neighbors, merge overlapping intervals. GetIntervals: return all stored intervals in order.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/data-stream-as-disjoint-intervals)
- [LeetCode](https://leetcode.com/problems/data-stream-as-disjoint-intervals/)
