# Find Minimum in Rotated Sorted Array

**LeetCode #153** · [LeetCode](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) · [NeetCode](https://neetcode.io/problems/find-minimum-in-rotated-sorted-array)

- **Difficulty:** Medium
- **Categories:** Array, Binary Search
- **Time Complexity:** O(log n)
- **Space Complexity:** O(1)

---

## Problem Statement

Given a sorted array of unique integers that has been rotated between 1 and n times, return the minimum element of the array in O(log n) time.

**Examples:**
```
Input: nums = [3,4,5,1,2]   →  Output: 1
Input: nums = [4,5,6,7,0,1,2]  →  Output: 0
Input: nums = [11,13,15,17]  →  Output: 11   (not rotated / rotated n times)
```

---

## Intuition

A rotated sorted array has exactly one "break point" where the sequence wraps from large values back to small ones (e.g., `…7, 0…`). The minimum element always sits at that break point. The rest of the array is still sorted on both sides of it.

The key observation is: if `nums[mid] > nums[h]`, the break point (and therefore the minimum) must lie **strictly to the right** of `mid`, because the left portion is still in ascending order and all values there are larger than `nums[h]`. Conversely, if `nums[mid] <= nums[h]`, the right portion is sorted and the minimum is at `mid` or to its left — so we keep `mid` in the window.

Repeating this halving, the two bounds converge to the minimum in O(log n) time.

---

## Approach: Binary Search — Right Anchor Comparison

We use two pointers `l` and `h` as inclusive bounds. At each step we compute `mid` and compare it against the **right anchor** `nums[h]`:

- `nums[mid] > nums[h]` → the left subarray is sorted and all values there are **greater** than the minimum, so discard it: `l = mid + 1`.
- `nums[mid] <= nums[h]` → the right subarray is sorted; `mid` could itself be the minimum, so keep it by setting `h = mid` (not `mid - 1`).

When `l == h`, both pointers point at the minimum.

```cpp
int l = 0, h = nums.size() - 1;
while (l < h) {
    int mid = l + (h - l) / 2;     // overflow-safe midpoint

    if (nums[mid] > nums[h])
        l = mid + 1;   // min is strictly right of mid
    else
        h = mid;       // mid is a candidate — don't skip it
}
return nums[l];        // l == h, converged on the minimum
```

---

## Complexity

|           | Value    | Reason                                                              |
|-----------|----------|---------------------------------------------------------------------|
| **Time**  | O(log n) | Search space halves every iteration — classic binary search bound   |
| **Space** | O(1)     | Only two index variables (`l`, `h`); no auxiliary data structures   |

---

## Edge Cases

| Scenario                                   | Result                              |
|--------------------------------------------|-------------------------------------|
| Single element `[5]`                       | `5` — `l == h` immediately          |
| Not rotated `[1,2,3,4,5]`                  | `1` — `nums[mid] <= nums[h]` always; `h` shrinks to 0 |
| Rotated by exactly `n` steps (full circle) | Same as not rotated — first element is min |
| Minimum at last index `[2,3,4,5,1]`        | `1` — `l` jumps to `mid+1` until it reaches the last index |
| Two elements `[2,1]`                       | `1` — one iteration, `l` advances to index 1 |

---

## Alternative Approach

**Linear Scan — O(n)**

Simply track the running minimum in a single pass:

```cpp
int findMin(vector<int>& nums) {
    int mn = nums[0];
    for (int x : nums) mn = min(mn, x);
    return mn;
}
```

Use this only when the sorted+rotated constraint cannot be guaranteed. It trades the O(log n) bound for simplicity.

**Handling Duplicates (LC #154 extension)**

When duplicates are allowed, `nums[mid] == nums[h]` is ambiguous. Resolve it by shrinking the right bound by one:

```cpp
if      (nums[mid] > nums[h]) l = mid + 1;
else if (nums[mid] < nums[h]) h = mid;
else                          h--;          // ambiguous — shrink safely
```

Worst case degrades to O(n) (all identical elements), but average case stays O(log n).

---

## Files

| File | Description |
|------|-------------|
| [`binary-search-right-anchor.cpp`](./binary-search-right-anchor.cpp) | C++ solution using right-anchor binary search with full inline comments |

---

## Related Problems

- [Search in Rotated Sorted Array (LC #33)](https://leetcode.com/problems/search-in-rotated-sorted-array/) — same rotated structure; search for a target instead of the minimum
- [Find Minimum in Rotated Sorted Array II (LC #154)](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/) — duplicate elements version; requires the `h--` tie-breaking step
- [Find Peak Element (LC #162)](https://leetcode.com/problems/find-peak-element/) — binary search on an unsorted array using the same "compare mid vs. neighbor" principle
- [Search a 2D Matrix (LC #74)](https://leetcode.com/problems/search-a-2d-matrix/) — binary search applied to a flattened sorted grid
