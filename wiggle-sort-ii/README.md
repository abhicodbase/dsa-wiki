# Wiggle Sort II

- **Difficulty:** Medium
- **Categories:** Array, Divide and Conquer, Sorting, Quickselect

---

## Complexity Analysis

### Sorting Approach
- **Time Complexity:** $O(N \log N)$
  - Sorting the copy array `v` takes $O(N \log N)$ time.
  - The final linear pass to re-arrange indices takes $O(N)$ time.
- **Space Complexity:** $O(N)$
  - Requires $O(N)$ auxiliary space to allocate the copy array `v`.

### Quickselect + Virtual Index Mapping (Optimal)
- **Time Complexity:** $O(N)$ on average
  - Using Quickselect to find the median takes $O(N)$ time on average.
  - The virtual index mapping three-way partition takes $O(N)$ time.
- **Space Complexity:** $O(1)$
  - Rearranges the array in-place using virtual index calculations.

---

Given an integer array `nums`, reorder it such that:
`nums[0] < nums[1] > nums[2] < nums[3]...`

You may assume the input array always has a valid answer.

---

## Intuition

If we simply sort the array and place elements in order (e.g. `nums[0] = v[0]`, `nums[1] = v[mid+1]`, `nums[2] = v[1]`, etc.), we might run into the **equal-elements adjacency issue** if the array has duplicates. 

To prevent adjacent elements from sharing the same value (particularly values equal to the median), we split the sorted array into two halves:
- **Smaller half**: `v[0...mid]`
- **Larger half**: `v[mid+1...n-1]`

By placing elements of both halves in **reverse (descending) order**, we ensure that:
1. The largest elements of the smaller half (close to the median) are placed far away from the smallest elements of the larger half (also close to the median).
2. The values are distributed such that strict inequalities `nums[i] < nums[i+1] > nums[i+2]` are preserved.

---

## Approach: Sorting + Re-arrangement

1. **Sort**: Create a sorted duplicate vector `v` of the input array `nums`.
2. **Dividing Index**: Calculate the midpoint index `mid = (n - 1) / 2`.
3. **Placements**:
   - For even positions (`i = 0, 2, 4, ...`), fill them from the end of the smaller half (`v[mid--]`).
   - For odd positions (`i = 1, 3, 5, ...`), fill them from the end of the larger half (`v[end--]`).

---

## Files

| File | Description |
| :--- | :--- |
| [`sorting.cpp`](./sorting.cpp) | C++ solution implementing sorting and index interlace |
| [`wiggle_sort_ii.html`](./wiggle_sort_ii.html) | Interactive step-by-step SVG pointer visualization of the sorting and merging process |
| [`wiggle_sort_2_explainer.html`](./wiggle_sort_2_explainer.html) | Interactive step-by-step colored grid explainer detailing the partition splitting |

### Interactive Demos

We provide two interactive visual guides inside the `dsa-wiki` viewer:
1. **SVG Pointer Guide (`wiggle_sort_ii.html`)**: Focuses on visual pointer transitions and drawing data propagation lines from the sorted array.
2. **Colored Grid Explainer (`wiggle_sort_2_explainer.html`)**: Focuses on showing the step-by-step array partition state and validating final inequality relationships.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/wiggle-sort-ii)
- [LeetCode](https://leetcode.com/problems/wiggle-sort-ii/)
