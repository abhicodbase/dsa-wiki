/*
 * LeetCode #213 — House Robber II
 * https://leetcode.com/problems/house-robber-ii/
 *
 * APPROACH: Two Linear Runs (Recursion with Memoization)
 * ──────────────────────────────────────────────────────────────
 * Since the houses are arranged in a circle, the first and last houses are
 * adjacent and cannot both be robbed. This circular dependency can be resolved
 * by running the standard linear House Robber algorithm twice:
 * 1. First run: Consider houses from index 0 to N-2 (allowing first, excluding last).
 * 2. Second run: Consider houses from index 1 to N-1 (excluding first, allowing last).
 *
 * The maximum of the two runs is the optimal solution for the circular arrangement.
 * Each linear run is solved using top-down recursion with a 1D memoization table.
 *
 * TIME  : O(N) — We perform two linear passes over the array.
 * SPACE : O(N) — Memoization tables of size N and the recursion stack.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief Helper function to perform linear House Robber recursion with memoization.
     * @param nums The input array representing money in each house.
     * @param idx  The current house index we are evaluating.
     * @param n    The boundary index (inclusive upper bound for this linear run).
     * @param dp   1D memoization vector initialized with -1.
     * @return The maximum money that can be robbed starting from `idx` up to `n`.
     */
    int robbery(vector<int>& nums, int idx, int n, vector<int>& dp) {
        // Base case: if we exceed the boundary of the current subarray, no more money
        if (idx > n) {
            return 0;
        }

        // Return cached result if already computed
        if (dp[idx] != -1) {
            return dp[idx];
        }

        // Standard DP choice: 
        // 1. Rob current house: add current value and skip adjacent (go to idx + 2)
        // 2. Skip current house: proceed to next house (go to idx + 1)
        return dp[idx] = max(
            nums[idx] + robbery(nums, idx + 2, n, dp), 
            robbery(nums, idx + 1, n, dp)
        );
    }

    /**
     * @brief Main function to find the maximum amount of money we can rob.
     * @param nums The input array representing money in each house.
     * @return Maximum money robbed without triggering alarms.
     */
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Safe check for single house scenario: circular rules don't restrict us
        if (n == 1) {
            return nums[0];
        }

        // DP tables for the two separate linear runs
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        // Return the maximum of:
        // - Run 1: Robbing from index 1 to n-1 (excluding index 0)
        // - Run 2: Robbing from index 0 to n-2 (excluding index n-1)
        return max(
            robbery(nums, 1, n - 1, dp1), 
            robbery(nums, 0, n - 2, dp2)
        );
    }
};

/*
 * ALTERNATIVE: Single Run Recursion with State Tracking
 * ──────────────────────────────────────────────────────
 * Instead of running two linear DP passes on subsegments of the array, we can track
 * whether the first house was robbed using a boolean flag `isInitConsidered` as part
 * of the recursion state. This only requires a single recursion pass but uses a 2D memoization
 * table of size N x 2.
 *
 * Trade-off: Both approaches have O(N) time and space complexity, but the two-runs approach
 * splits the logic into two cleaner, independent linear passes, avoiding extra state parameters.
 */
