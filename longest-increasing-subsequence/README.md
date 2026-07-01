# Longest Increasing Subsequence

- **Difficulty:** Medium
- **Categories:** Array, Binary Search, Dynamic Programming

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Description / Inefficiencies |
| :--- | :--- | :--- | :--- |
| **Top-down Memoization** | $O(N^2)$ | $O(N^2)$ | Simple recursive formulation, but requires $O(N^2)$ extra space for the memoization table and incurs recursion stack overhead. |
| **Bottom-up DP (Iterative)** | $O(N^2)$ | $O(N)$ | Eliminates recursion overhead and reduces memory allocation down to $O(N)$ space using a 1D DP table. |
| **Patience Sorting (Binary Search)** | $O(N \log N)$ | $O(N)$ | Optimal approach. Uses binary search (`std::lower_bound`) to maintain a sorted `tails` list containing the smallest tail of each subsequence length. |

---

Given an integer array `nums`, return the length of the longest strictly increasing subsequence.

---

## Approach 1: Recursion + Memoization (Top-Down)

We recursively explore all possibilities for each index:
1. **Choice 1: Skip**: Recurse to `idx + 1` with the same `prevIdx`.
2. **Choice 2: Take**: If `nums[idx] > nums[prevIdx]` (or if `prevIdx == -1`), we can take the current element: add `1` and recurse to `idx + 1` with `prevIdx` updated to `idx`.

We cache coordinates using a 2D table `dp[idx][prevIdx]`. If `prevIdx == -1`, we bypass the cache check.

---

## Approach 2: Dynamic Programming (Bottom-Up)

1. Let `dp[i]` store the length of the LIS ending exactly at index `i`.
2. Initialize all `dp[i] = 1` since each individual element forms a valid subsequence of length 1.
3. For each index `i` from `1` to `N-1`, scan backward through all previous indices `j < i`.
4. If `nums[i] > nums[j]`, then `nums[i]` can extend the LIS ending at `j`. We update:
   $$dp[i] = \max(dp[i], dp[j] + 1)$$
5. The final answer is the maximum value found in the `dp` array.

---

## Approach 3: Patience Sorting & Binary Search (Optimal)

We maintain a sorted `tails` array, where `tails[i]` stores the smallest tail of all increasing subsequences of length `i+1` found so far.
For each element `x` in `nums`:
- Use binary search (`std::lower_bound`) to find the first element in `tails` that is $\ge x$.
- If such an element exists, replace it with `x`. This keeps our tails as small as possible, maximizing future extension opportunities.
- If all elements in `tails` are smaller than `x`, append `x` to the end of `tails` (this extends our LIS length).
The final length of the `tails` array is the length of the LIS.

---

## Files

| File | Description |
| :--- | :--- |
| [`binary_search.cpp`](./binary_search.cpp) | Optimal $O(N \log N)$ time and $O(N)$ space binary search / patience sorting solution |
| [`bottom_up_dp.cpp`](./bottom_up_dp.cpp) | Iterative $O(N^2)$ time and $O(N)$ space bottom-up dynamic programming solution |
| [`memoization.cpp`](./memoization.cpp) | Top-down $O(N^2)$ time and $O(N^2)$ space recursion + memoization solution |
| [`lis_bottom_up_dp.html`](./lis_bottom_up_dp.html) | Interactive step-by-step colored visualization of the bottom-up DP scanning process |

### Interactive Demo (`lis_bottom_up_dp.html`)

An embeddable visual guide demonstrating the $O(N^2)$ bottom-up DP approach:
- Highlight of index `i` (target node) and index `j` (scanning node).
- Real-time comparison panel checking if `nums[j] < nums[i]`.
- Dynamic updates of the `dp` array showing length growth and state transitions.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/longest-increasing-subsequence)
- [LeetCode](https://leetcode.com/problems/longest-increasing-subsequence/)
