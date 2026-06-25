/*
 * LeetCode #213 — House Robber II
 * https://leetcode.com/problems/house-robber-ii/
 *
 * APPROACH: Recursion with Memoization (Tracking First House Robbed Status)
 * ──────────────────────────────────────────────────────────────
 * Since the houses are arranged in a circle, the first and last houses are
 * adjacent. This means we cannot rob both of them. To solve this, we can
 * track whether the first house (index 0) is robbed using a boolean flag
 * (`isInitConsidered`). If we decide to rob the first house, we explicitly
 * prevent robbing the last house.
 *
 * We define a recursive helper `dp(nums, idx, isInitConsidered, mem)` where:
 * - `idx` is the current house index.
 * - `isInitConsidered` is 1 if the first house was robbed, and 0 otherwise.
 * - `mem` is a 2D memoization table storing maximum money for the state (idx, isInitConsidered).
 *
 * TIME  : O(N) — There are N * 2 distinct states, and each state takes O(1) time to compute.
 * SPACE : O(N) — Due to the 2D memoization table `mem` of size N x 2 and the recursion call stack.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief Helper function for recursion with memoization.
     * @param nums              The input vector representing money in each house.
     * @param idx               The current house index we are evaluating.
     * @param isInitConsidered  Flag indicating if the first house (idx 0) was robbed (1 = yes, 0 = no).
     * @param mem               2D DP state table initialized with -1.
     * @return The maximum money that can be robbed starting from `idx`.
     */
    int dp(vector<int>& nums, int idx, int isInitConsidered, vector<vector<int>>& mem) {
        // Base case: if we go beyond the last house, no more money can be obtained
        if (idx >= nums.size()) {
            return 0;
        }
        
        // Circular constraint check: if the first house was robbed and we reach the last house,
        // we cannot rob it since they are adjacent. We return 0.
        if (isInitConsidered && idx == nums.size() - 1) {
            return 0;
        }

        // Decision at the very first house (index 0)
        if (idx == 0) {
            return max(
                // Option A: Rob the first house (mark isInitConsidered as true/1, jump to idx + 2)
                nums[idx] + dp(nums, idx + 2, true, mem), 
                // Option B: Skip the first house (mark isInitConsidered as false/0, move to idx + 1)
                dp(nums, idx + 1, false, mem)
            );
        }

        // Return cached result if already calculated for this index and initial house decision
        if (mem[idx][isInitConsidered] != -1) {
            return mem[idx][isInitConsidered];
        }

        // Standard House Robber decisions: either rob this house or skip it,
        // and memoize the choice for the current state.
        return mem[idx][isInitConsidered] = max(
            nums[idx] + dp(nums, idx + 2, isInitConsidered, mem), // Rob this house, skip next
            dp(nums, idx + 1, isInitConsidered, mem)             // Skip this house, move to next
        ); 
    }

    /**
     * @brief Main function to find the maximum amount of money we can rob.
     * @param nums The input array representing money in each house.
     * @return Maximum money robbed without triggering alarms.
     */
    int rob(vector<int>& nums) {
        // Safe check for empty input
        if (nums.empty()) {
            return 0;
        }
        // If there's only one house, we can just rob it
        if (nums.size() == 1) {
            return nums[0];
        }

        // Memoization table: size N x 2, initialized to -1
        vector<vector<int>> mem(nums.size(), vector<int>(2, -1));
        
        // Start recursion from index 0, with first house decision not yet made (0)
        return dp(nums, 0, 0, mem);
    }
};

/*
 * ALTERNATIVE: Two Linear House Robber Runs (Iterative DP with O(1) Space)
 * ───────────────────────────────────────────────────────────────────────
 * Instead of tracking the first house decision with a boolean state, we can
 * run the standard linear House Robber I algorithm on two subsegments of the array:
 * 1. Subsegment [0...N-2]: This includes the first house and excludes the last.
 * 2. Subsegment [1...N-1]: This excludes the first house and includes the last.
 * The answer will be the maximum of the two runs.
 *
 *   int rob_linear(vector<int>& nums, int start, int end) {
 *       int prev1 = 0, prev2 = 0;
 *       for (int i = start; i <= end; ++i) {
 *           int temp = max(prev1, prev2 + nums[i]);
 *           prev2 = prev1;
 *           prev1 = temp;
 *       }
 *       return prev1;
 *   }
 *   int rob(vector<int>& nums) {
 *       int n = nums.size();
 *       if (n == 1) return nums[0];
 *       return max(rob_linear(nums, 0, n - 2), rob_linear(nums, 1, n - 1));
 *   }
 *
 * Trade-off: The alternative approach reduces space complexity to O(1) auxiliary space 
 * and avoids the call stack overhead of recursion.
 */
