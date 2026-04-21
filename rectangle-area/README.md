# Rectangle Area

- **Difficulty:** Medium
- **Categories:** Math, Geometry
- **Time Complexity:** O(1)
- **Space Complexity:** O(1)

---

Find the total area covered by two rectangles in a 2D plane.

---

## Approach: Inclusion-Exclusion

Total = area1 + area2 - overlap. Overlap width = max(0, min(right1,right2) - max(left1,left2)). Overlap height similar. Total - overlap.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/rectangle-area)
- [LeetCode](https://leetcode.com/problems/rectangle-area/)
