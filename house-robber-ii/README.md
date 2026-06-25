# House Robber II

**LeetCode #213** · [LeetCode](https://leetcode.com/problems/house-robber-ii/) · [NeetCode](https://neetcode.io/problems/house-robber-ii)

- **Difficulty:** Medium
- **Categories:** Array, Dynamic Programming
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

## Problem Statement

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array `nums` representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

**Examples:**
```
Input:  nums = [2,3,2]  →  Output: 3
Input:  nums = [1,2,3,1]  →  Output: 4
Input:  nums = [1,2,3]  →  Output: 3
```

---

## Intuition

Since the houses are arranged in a circle, the first and last houses are neighbors. If we rob the first house, we cannot rob the last house. If we skip the first house, we are free to rob the last house. We can track this circular dependency by using a helper function that carries a state flag `isInitConsidered` (indicating whether the first house at index 0 was robbed). By recording the decision made at index 0, we can dynamically prevent the last house from being robbed when `isInitConsidered` is true. This state formulation allows us to evaluate all valid circular robbing scenarios recursively and cache the results to avoid redundant calculations.

---

## Approach 1: Single Run with State Tracking (Recursion & Memoization)

1. **Circular State Tracking**: We use a helper function `dp(nums, idx, isInitConsidered, mem)`. The boolean flag `isInitConsidered` stores whether the first house at index 0 was robbed (`true`) or skipped (`false`).
2. **First House Branching**: At the very first house (`idx == 0`), we branch into two choices:
   - Rob it: Add `nums[0]`, jump to `idx + 2`, and set `isInitConsidered` to `true`.
   - Skip it: Move to `idx + 1`, and set `isInitConsidered` to `false`.
3. **Circular Constraint**: When we reach the last house (`idx == nums.size() - 1`), if `isInitConsidered` is `true`, we must skip the last house (return 0) to avoid triggering the circular alarm.
4. **General Step**: At any other house `idx`, we decide to either:
   - Rob it: Add `nums[idx]` and recurse on `idx + 2`.
   - Skip it: Recurse on `idx + 1`.
5. **Memoization**: We store the results of each state `(idx, isInitConsidered)` in a 2D memoization table `mem` of size $N \times 2$.

```cpp
// Simplified recursive function logic
int dp(vector<int>& nums, int idx, bool isInitConsidered) {
    if (idx >= nums.size()) return 0;
    if (isInitConsidered && idx == nums.size() - 1) return 0; // Circular rule

    if (idx == 0) {
        return max(nums[0] + dp(nums, 2, true), dp(nums, 1, false));
    }

    if (mem[idx][isInitConsidered] != -1) return mem[idx][isInitConsidered];

    return mem[idx][isInitConsidered] = max(
        nums[idx] + dp(nums, idx + 2, isInitConsidered),
        dp(nums, idx + 1, isInitConsidered)
    );
}
```

---

## Approach 2: Two Linear Runs (Recursion & Memoization)

Instead of passing a tracking flag through recursion, we can split the circular problem into two standard linear house-robbing subproblems:
1. **Exclude Last House**: Run recursion on range $[0 \dots N-2]$.
2. **Exclude First House**: Run recursion on range $[1 \dots N-1]$.

We return the maximum of the two runs. Each run is memoized independently using a 1D `dp` array of size $N$.

```cpp
// Simplified two-runs logic
int robbery(vector<int>& nums, int idx, int n, vector<int>& dp) {
    if (idx > n) return 0;
    if (dp[idx] != -1) return dp[idx];
    return dp[idx] = max(nums[idx] + robbery(nums, idx + 2, n, dp), robbery(nums, idx + 1, n, dp));
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    vector<int> dp1(n, -1), dp2(n, -1);
    return max(robbery(nums, 1, n - 1, dp1), robbery(nums, 0, n - 2, dp2));
}
```

---

## Complexity

| | Value | Reason |
|---|---|---|
| **Time**  | O(N) | We compute each of the $N \times 2$ states at most once, with $O(1)$ work per state. |
| **Space** | O(N) | The size of the memoization table is $N \times 2$, and the recursion stack takes up to $O(N)$ depth. |

---

## Edge Cases

| Scenario | Result |
|---|---|
| Empty array `nums = []` | `0` (handled by early return) |
| Single house `nums = [7]` | `7` (handled by returning `nums[0]` directly) |
| All identical elements e.g. `nums = [2,2,2]` | `2` (the circular constraint allows robbing at most one house) |
| Large array bounds | Handled within limits of integer representation |

---

## Files

| File | Description |
|---|---|
| [`recursion-memoization.cpp`](./recursion-memoization.cpp) | Single-run recursion with first-house state tracking |
| [`two-runs-recursion-memoization.cpp`](./two-runs-recursion-memoization.cpp) | Two linear runs of recursion with 1D memoization |
| [`README.md`](./README.md) | Problem documentation and walkthrough |

---

## Related Problems

- [House Robber (LC #198)](https://leetcode.com/problems/house-robber/) — The original version without the circular constraint.
- [House Robber III (LC #337)](https://leetcode.com/problems/house-robber-iii/) — The same concept applied to binary tree structures (Tree DP).
- [Paint House (LC #256)](https://leetcode.com/problems/paint-house/) — Another dynamic programming problem using multi-state decisions.
