# Sort an Array

- **Difficulty:** Medium
- **Categories:** Array, Divide and Conquer, Sorting, Heap, Merge Sort, Quick Sort

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Description |
| :--- | :--- | :--- | :--- |
| **QuickSort (Lomuto Partition)** | $O(N \log N)$ avg, $O(N^2)$ worst | $O(\log N)$ stack avg, $O(N)$ worst | In-place partition. Picking a fixed end pivot can trigger $O(N^2)$ worst case on sorted arrays. |
| **Merge Sort (Guaranteed $O(N \log N)$)** | $O(N \log N)$ | $O(N)$ | Divide-and-conquer using auxiliary scratch vector. Stable and immune to adversarial input. |

---

Given an array of integers `nums`, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in $O(N \log N)$ time complexity and with the smallest space complexity possible.

**Examples:**
```text
Input: nums = [5,2,3,1]
Output: [1,2,3,5]

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
```

---

## Approach 1: QuickSort (Lomuto Partitioning)

1. **Partitioning**: Choose `pivot = nums[end]`. Maintain boundary index `left = start`.
2. Iterate `i` from `start` to `end - 1`. If `nums[i] < pivot`, swap `nums[i]` with `nums[left]` and increment `left`.
3. Swap `nums[left]` with `nums[end]` to put the pivot in its final sorted position.
4. Recursively sort the sub-arrays `[start, left - 1]` and `[left + 1, end]`.

> **Note on Worst Case**: Deterministic pivot selection (`nums[end]`) can hit $O(N^2)$ TLE on sorted or all-identical inputs. To prevent TLE on LeetCode, randomizing the pivot index (`rand()`) or using 3-way partitioning (Dutch National Flag) is required.

---

## Approach 2: Merge Sort (Optimal & Guaranteed $O(N \log N)$)

1. Recursively divide the array range `[start, end]` into two halves at `mid = start + (end - start) / 2`.
2. Merge the two sorted halves into a temporary buffer using two pointers.
3. Copy elements back from the temporary buffer to `nums`.

---

## Files

| File | Description |
| :--- | :--- |
| [`quick_sort.cpp`](./quick_sort.cpp) | QuickSort implementation using Lomuto partition |
| [`merge_sort.cpp`](./merge_sort.cpp) | Guaranteed $O(N \log N)$ Merge Sort implementation |

---

## Learn More
- [NeetCode](https://neetcode.io/problems/sort-an-array)
- [LeetCode](https://leetcode.com/problems/sort-an-array/)
