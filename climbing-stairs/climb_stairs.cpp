#include <vector>
using namespace std;

/**
 * @brief Solution class for the "Climbing Stairs" problem.
 *
 * The problem: Given n steps, you can climb either 1 or 2 steps at a time.
 * Determine how many distinct ways you can reach the top.
 *
 * This implementation uses a simple top‑down recursion with memoization
 * (also known as a DP cache). The recursion explores the two possible moves
 * from the current index: move one step forward or two steps forward.
 * The base cases:
 *   - When the index exceeds n, there is no valid path (return 0).
 *   - When the index exactly equals n, we have found a valid way (return 1).
 * The cache `dp` stores the result for each index to avoid recomputation,
 * giving an O(n) time complexity and O(n) space for the cache/recursion
 * stack.
 */
class Solution {
public:
  /**
   * @brief Helper recursive function.
   * @param idx Current step index (0‑based).
   * @param n   Total number of steps.
   * @param dp  Memoization vector initialized with -1.
   * @return Number of ways to reach the top from `idx`.
   */
  int steps(int idx, int n, vector<int> &dp) {
    if (idx > n)
      return 0; // Overshoot – invalid path.
    if (idx == n)
      return 1; // Exactly at the top – one valid way.
    if (dp[idx] != -1)
      return dp[idx]; // Return cached result.
    // Explore taking 1 step and 2 steps from the current position.
    return dp[idx] = steps(idx + 1, n, dp) + steps(idx + 2, n, dp);
  }

  /**
   * @brief Public API to compute the number of ways to climb `n` stairs.
   * @param n Number of stairs.
   * @return Total distinct ways to reach the top.
   */
  int climbStairs(int n) {
    // dp[i] will store the number of ways to reach the top from step i.
    vector<int> dp(n + 1, -1);
    // dp[1] = 1;
    // dp[0] = 1;
    // for(int i=2;i<=n;i++) dp[i] = dp[i-1] + dp[i-2];
    // return dp[n];
    return steps(0, n, dp);
  }
};
