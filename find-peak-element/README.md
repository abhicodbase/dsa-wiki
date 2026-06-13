# Find Peak Element

**LeetCode #162** · [LeetCode](https://leetcode.com/problems/find-peak-element/) · [NeetCode](https://neetcode.io/problems/find-peak-element)

- **Difficulty:** Medium
- **Categories:** Array, Binary Search
- **Time Complexity:** `O(log N)`
- **Space Complexity:** `O(1)`

---

## Problem Statement

A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array `nums`, find a peak element, and return its index. If the array contains multiple peaks, return the index to **any of the peaks**.

You may imagine that `nums[-1] = nums[n] = -∞`. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in `O(log n)` time.

---

## Intuition

The key constraint is the `O(log n)` time limit, which immediately points to **binary search**. But how do we binary search on an unsorted array?

Think of the array as a mountain range. For any midpoint index `mid`:
- If `nums[mid] < nums[mid + 1]`, we are on an **ascending slope**. Since the values are rising to the right, a peak is guaranteed to exist somewhere to the right (worst case, the rightmost element itself is a peak because `nums[n] = -∞`).
- If `nums[mid] > nums[mid + 1]`, we are on a **descending slope** (or `mid` is a local peak). In either case, a peak is guaranteed to exist at `mid` or somewhere to the left.

By checking the local slope at `mid`, we can discard half of the array in each step, always staying on a path that is guaranteed to hit a peak.

---

## Approach: Binary Search on Slopes

1. Initialize `low = 0` and `high = n - 1`.
2. While `low < high`:
   - Compute `mid = low + (high - low) / 2`.
   - If `nums[mid] < nums[mid + 1]`, the peak must be to the right: `low = mid + 1`.
   - Otherwise, the peak is at `mid` or to the left: `high = mid`.
3. When `low == high`, they have converged on a peak element index. Return it.

---

## Code

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return high;
    }
};
```

---

## Complexity

| | Value | Reason |
| :--- | :--- | :--- |
| **Time** | `O(log N)` | The search space is halved in each step of the binary search. |
| **Space** | `O(1)` | We only allocate constant space for the loop indices. |

---

## Edge Cases

| Scenario | Behavior |
| :--- | :--- |
| Single element array (`[1]`) | Loop condition `low < high` is false immediately; returns index `0` (correct since borders are $-\infty$). |
| Strictly increasing array (`[1,2,3,4]`) | Binary search constantly moves right; returns `3` (value `4` is the peak). |
| Strictly decreasing array (`[4,3,2,1]`) | Binary search constantly moves left; returns `0` (value `4` is the peak). |
| Multiple peaks (e.g. `[1,2,1,3,5,6,4]`) | Returns index `1` (value `2`) or index `5` (value `6`); either is acceptable. |

---

## Files

| File | Description |
| :--- | :--- |
| [`binary-search-peak.cpp`](./binary-search-peak.cpp) | C++ solution using binary search on monotonic slopes |

---

## Related Problems

- [LC #852 — Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/) — simplified version where there is guaranteed to be exactly one peak
- [LC #1095 — Find in Mountain Array](https://leetcode.com/problems/find-in-mountain-array/) — extension requiring peak finding followed by binary searches
- [LC #33 — Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) — binary search requiring slope/sorted-interval checks
