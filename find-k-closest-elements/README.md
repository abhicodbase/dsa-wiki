# Find K Closest Elements

**LeetCode #658** · [LeetCode](https://leetcode.com/problems/find-k-closest-elements/) · [NeetCode](https://neetcode.io/problems/find-k-closest-elements)

- **Difficulty:** Medium
- **Categories:** Array, Binary Search, Sliding Window
- **Time Complexity:** O(log(N − K) + K)
- **Space Complexity:** O(1) — excluding the output array

---

## Problem Statement

Given a **sorted** integer array `arr`, two integers `k` and `x`, return the `k` closest integers to `x` in the array.

- Closeness is measured by **absolute difference** `|a − x|`.
- If two numbers are equally close, the **smaller** one is preferred.
- The result must be sorted in **ascending order**.

**Example:**
```
Input:  arr = [1, 2, 3, 4, 5, 6, 7, 8],  k = 3,  x = 5
Output: [4, 5, 6]
```

---

## Intuition

Since the array is sorted, the `k` closest elements will always form a **contiguous window** of size `k`. We don't need to find each element individually — we just need to find the **best starting index `lo`** for that window.

The window is `arr[lo .. lo+k-1]`. The only comparison needed at each step is:

```
Is arr[lo..lo+k-1] better than arr[lo+1..lo+k]?
```

Which reduces to a single comparison between the **left edge** `arr[mid]` and the **right edge** `arr[mid+k]` relative to `x`:

```
if (x - arr[mid]) > (arr[mid + k] - x)
    → left edge is farther → slide window right → lo = mid + 1
else
    → right edge is farther or equal → keep current or go left → hi = mid
```

---

## Approach: Binary Search on Window's Left Index

The search space for the left boundary `lo` is `[0, n − k]` (window cannot start beyond `n − k`).

```
lo = 0, hi = n − k

while lo < hi:
    mid = lo + (hi − lo) / 2
    if (x − arr[mid]) > (arr[mid + k] − x):
        lo = mid + 1   // left edge is farther from x; slide right
    else:
        hi = mid       // right edge is farther or equal; keep left side

return arr[lo .. lo + k]
```

**Why `hi = n − k`?** The window `[lo, lo+k)` must fit entirely in the array. So `lo` can be at most `n − k`.

**Why `≤` keeps hi = mid?** The problem says smaller values are preferred when equidistant. So `arr[mid]` is at most as far as `arr[mid+k]` — we keep `hi = mid` to prefer the left/smaller element.

---

## Complexity

| | Value | Notes |
|---|---|---|
| Time | O(log(N − K) + K) | O(log(N−K)) for binary search + O(K) to slice result |
| Space | O(1) | No extra data structures; result is output |

---

## Files

| File | Description |
|---|---|
| [`binary-search.cpp`](./binary-search.cpp) | Clean C++ implementation |
| [`find_k_closest_binary_search.html`](./find_k_closest_binary_search.html) | Step-by-step interactive SVG visualization (for dsa-wiki viewer) |
| [`concept.png`](./concept.png) | Static visual aid for the binary search window concept |

### Interactive Demo (`find_k_closest_binary_search.html`)

An embeddable, step-by-step visualization that shows:
- The **lo / hi / mid** pointers moving across the array
- A **green window rectangle** tracking the current k-element candidate window
- **Quadratic arcs** showing `x − arr[mid]` vs `arr[mid+k] − x` distances
- A **comparison box** with the decision and direction at each step
- The **final result** highlighted in green when `lo == hi`

---

## Edge Cases

| Scenario | Behavior |
|---|---|
| `x < arr[0]` | Window lands at `[0, k)` — leftmost k elements |
| `x > arr[n-1]` | Window lands at `[n-k, n)` — rightmost k elements |
| `x` is exactly an array element | Works correctly; ties prefer smaller value |
| `k == n` | Returns the entire array |
| Two equidistant elements | Smaller (left) is preferred by the `≤` condition |

---

## Related Problems

- [K Closest Points to Origin (LC #973)](https://leetcode.com/problems/k-closest-points-to-origin/) — Min heap / quickselect in 2D
- [Find Closest Number to Zero (LC #2239)](https://leetcode.com/problems/find-closest-number-to-zero/) — Single closest element
- [Kth Smallest Element in a BST (LC #230)](https://leetcode.com/problems/kth-smallest-element-in-a-bst/) — Related ordered traversal
- [Search in Rotated Sorted Array (LC #33)](https://leetcode.com/problems/search-in-rotated-sorted-array/) — Binary search variant
