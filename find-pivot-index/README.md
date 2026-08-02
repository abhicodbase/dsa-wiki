# Find Pivot Index

- **Difficulty:** Easy
- **Categories:** Array, Prefix Sum

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Description |
| :--- | :--- | :--- | :--- |
| **Prefix Sum Array** | $O(N)$ | $O(N)$ | Explicit prefix sum array where `leftSum = sum[i-1]` and `rightSum = sum[n] - sum[i]`. |
| **Running Total Sum (Optimal)** | $O(N)$ | $O(1)$ | Single total sum pass, followed by a running `leftSum` pass. $O(1)$ space. |

---

Given an array of integers `nums`, calculate the **pivot index** of this array.

The **pivot index** is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the right of the index.

If the index is on the left edge of the array, the left sum is `0` because there are no elements to the left. This also applies to the right edge of the array.

Return the **leftmost pivot index**. If no such index exists, return `-1`.

**Examples:**
```text
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

Input: nums = [1,2,3]
Output: -1

Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + (-1) = 0
```

---

## Approach 1: 1-Based Prefix Sum Array

1. Build a prefix sum array `sum` of size `n + 1` where `sum[i]` represents `sum(nums[0...i-1])`.
2. For each 1-based index `i` from $1$ to $n$:
   - Left sum = `sum[i - 1]`
   - Right sum = `sum[n] - sum[i]`
   - If `leftSum == rightSum`, return `i - 1`.

---

## Approach 2: Running Total Sum ($O(1)$ Space)

1. Compute `totalSum` of the entire array using `std::accumulate`.
2. Track `leftSum` starting at `0`.
3. At index `i`, the right sum is `totalSum - leftSum - nums[i]`.
4. If `leftSum == totalSum - leftSum - nums[i]`, return `i`.
5. Update `leftSum += nums[i]`.

---

## Files

| File | Description |
| :--- | :--- |
| [`prefix_sum.cpp`](./prefix_sum.cpp) | 1-based prefix sum vector implementation |
| [`total_sum.cpp`](./total_sum.cpp) | Optimal $O(1)$ space implementation using running total sum |

---

## Learn More
- [NeetCode](https://neetcode.io/problems/find-pivot-index)
- [LeetCode](https://leetcode.com/problems/find-pivot-index/)
