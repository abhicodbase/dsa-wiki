# Range Sum Query 2D - Immutable

- **Difficulty:** Medium
- **Categories:** Array, Design, Matrix, Prefix Sum
- **Time Complexity:** O(1) query, O(MxN) build
- **Space Complexity:** O(MxN)

---

Implement NumMatrix class: constructor takes 2D matrix, sumRegion(r1,c1,r2,c2) returns sum of elements in the rectangle.

---

## Approach: 2D Prefix Sum

prefix[i][j] = sum of rectangle from (0,0) to (i-1,j-1). sumRegion = prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1] (inclusion-exclusion).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/range-sum-query-2d-immutable)
- [LeetCode](https://leetcode.com/problems/range-sum-query-2d-immutable/)
