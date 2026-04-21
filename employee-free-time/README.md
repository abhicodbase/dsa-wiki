# Employee Free Time

- **Difficulty:** Hard
- **Categories:** Array, Sorting, Greedy
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(N)

---

Given a schedule of employee working intervals, find the list of finite intervals representing common free time.

---

## Approach: Merge All Intervals Then Find Gaps

Flatten all schedules, sort by start time. Merge overlapping intervals. Gaps between consecutive merged intervals are the common free time.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/employee-free-time)
- [LeetCode](https://leetcode.com/problems/employee-free-time/)
