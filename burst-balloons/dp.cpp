#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  /**
   * Helper function to find the maximum coins using top-down memoization
   * (Interval DP).
   *
   * The core challenge in Burst Balloons is that bursting a balloon merges its
   * left and right neighbors, which makes subproblems dependent on the order of
   * bursting. To solve this, we reverse our perspective: instead of asking
   * which balloon to burst *first*, we ask which balloon $k$ is burst **last**
   * in the subproblem interval $[l, r]$.
   *
   * If balloon $k$ is the last to burst in $[l, r]$, it implies that:
   * 1. All balloons to the left of $k$ (from $l$ to $k-1$) have already been
   * burst.
   * 2. All balloons to the right of $k$ (from $k+1$ to $r$) have already been
   * burst.
   *
   * Consequently, when we finally burst balloon $k$, its immediate adjacent
   * neighbors are the boundary balloons outside the interval: $nums[l-1]$ on
   * the left and $nums[r+1]$ on the right. This decouples the left subproblem
   * $[l, k-1]$ and right subproblem $[k+1, r]$ entirely!
   *
   * @param nums The padded array of balloon values.
   * @param l The left boundary index of the current active interval.
   * @param r The right boundary index of the current active interval.
   * @param dp Memoization table where dp[l][r] stores the max coins for
   * interval [l, r].
   * @return The maximum coins that can be obtained from the interval [l, r].
   */
  int findSumCoins(vector<int> &nums, int l, int r, vector<vector<int>> &dp) {
    // Base case: If the interval is invalid, no balloons can be burst,
    // returning 0.
    if (l > r)
      return 0;

    // Return the precalculated result if it exists
    if (dp[l][r] != 0)
      return dp[l][r];

    int bestCoins = 0;

    // Iterate through all possible choices of the last balloon k to burst in
    // the range [l, r]
    for (int k = l; k <= r; k++) {
      // Coins obtained from bursting k last: nums[l-1] * nums[k] * nums[r+1]
      // Plus the max coins from bursting the left sub-interval [l, k-1] and
      // right sub-interval [k+1, r]
      int coins = nums[l - 1] * nums[k] * nums[r + 1] +
                  findSumCoins(nums, l, k - 1, dp) +
                  findSumCoins(nums, k + 1, r, dp);

      bestCoins = max(bestCoins, coins);
    }

    // Store and return the computed state
    return dp[l][r] = bestCoins;
  }

  /**
   * Main function to compute the maximum coins obtainable by bursting all
   * balloons.
   */
  int maxCoins(vector<int> &nums) {
    // Pad the boundaries with virtual balloons of value 1,
    // which represents the out-of-bound walls as per problem constraints.
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    int n = nums.size();
    // DP table dimension: n x n initialized to 0
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // The original balloons are now located from index 1 to nums.size() - 2
    return findSumCoins(nums, 1, nums.size() - 2, dp);
  }
};