# Peak Index in a Mountain Array

**LeetCode #852** · [LeetCode](https://leetcode.com/problems/peak-index-in-a-mountain-array/) · [NeetCode](https://neetcode.io/problems/peak-index-in-a-mountain-array)

- **Difficulty:** Medium
- **Categories:** Array, Binary Search
- **Time Complexity:** O(log N)
- **Space Complexity:** O(1)

---

## Problem Statement

An array `arr` is a **mountain** if the following properties hold:
- `arr.length >= 3`
- There exists some `i` with `0 < i < arr.length - 1` such that:
  - `arr[0] < arr[1] < ... < arr[i - 1] < arr[i]`
  - `arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`

Given a mountain array `arr`, return the index `i` such that `arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`.

You must solve it in $O(\log N)$ time complexity.

**Examples:**
```
Input:  arr = [0,1,0]          →  Output: 1
Input:  arr = [0,2,1,0]        →  Output: 1
Input:  arr = [0,10,5,2]       →  Output: 1
```

---

## Intuition

A mountain array consists of two distinct halves: a strictly increasing sequence before the peak, and a strictly decreasing sequence after the peak.

Because the slope property is monotonic (increasing before peak, decreasing after peak), we can perform a **Binary Search** to locate the peak in $O(\log N)$ time:
- If `arr[mid] < arr[mid + 1]`, we are on the rising slope. The peak must be to the right of `mid`, so we shrink our search space to `[mid + 1, end]`.
- If `arr[mid] > arr[mid + 1]`, we are on the falling slope or at the peak itself. The peak must be at `mid` or to its left, so we shrink our search space to `[start, mid]`.

By continuously halving the range, `start` and `end` converge to the exact peak index.

---

## Approach: Binary Search on Slope

To implement this:
1. Initialize two pointers: `start = 0` and `end = arr.size() - 1`.
2. While `start < end`:
   - Calculate midpoint `mid = start + (end - start) / 2`.
   - Optional fast-exit check: If `mid` is greater than both `arr[mid - 1]` and `arr[mid + 1]`, return `mid`.
   - If `arr[mid] < arr[mid + 1]`, update `start = mid + 1` (move right).
   - Otherwise, update `end = mid` (move left).
3. Return `start` (or `mid` when found).

```cpp
int peakIndexInMountainArray(vector<int>& arr) {
    int start = 0, end = arr.size() - 1;
    
    while (start < end) {
        int mid = start + (end - start) / 2;
        
        // Check if mid is the peak
        if (mid > 0 && mid < arr.size() - 1 && arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return mid;
        }
        
        // Ascending slope -> move right
        if (arr[mid] < arr[mid + 1]) {
            start = mid + 1;
        } 
        // Descending slope -> move left
        else {
            end = mid;
        }
    }
    
    return start;
}
```

---

## Complexity

| Operation | Time Complexity | Space Complexity | Reason |
|---|---|---|---|
| **Search** | O(log N) | O(1) | Search space $[0, N-1]$ is halved in each step of the binary search. Memory used is constant. |

---

## Edge Cases

| Scenario | Result |
|---|---|
| Minimum size mountain `arr = [0, 1, 0]` | Returns `1` (peak at center). |
| Peak near start `arr = [0, 10, 5, 2]` | Returns `1`. |
| Peak near end `arr = [0, 1, 2, 10, 0]` | Returns `3`. |
| Large input array size ($N = 10^5$) | Handled efficiently in $\sim 17$ iterations via $O(\log N)$ binary search. |

---

## Files

| File | Description |
|---|---|
| [`binary-search.cpp`](./binary-search.cpp) | Main C++ solution using binary search on slope with full inline comments and test cases. |
| [`README.md`](./README.md) | Problem description, approach documentation, complexity analysis, and edge cases. |

---

## Related Problems

- [Find Peak Element (LC #162)](https://leetcode.com/problems/find-peak-element/) — Generalized peak finding in arrays with multiple peaks.
- [Find in Mountain Array (LC #1095)](https://leetcode.com/problems/find-in-mountain-array/) — Two-phase binary search involving peak finding followed by binary searching both slopes.
- [Search in Rotated Sorted Array (LC #33)](https://leetcode.com/problems/search-in-rotated-sorted-array/) — Binary search on modified monotonic properties.
