/*
 * LeetCode #45 — Jump Game II
 * https://leetcode.com/problems/jump-game-ii/
 *
 * APPROACH: BFS-Style Dynamic Programming (Iterative Array Traversal)
 * ──────────────────────────────────────────────────────────────
 * We use a DP array `dp` of size N, where `dp[i]` represents the minimum number
 * of jumps required to reach index `i`.
 * We initialize `dp` with -1 and set the starting point `dp[0] = 0`.
 *
 * We iterate through the array from `0` to `N-1`. For each index `i`:
 * 1. If `dp[i]` is -1, it means this index is unreachable, so we skip it.
 * 2. Otherwise, we try to jump to all forward positions `i + j` (where `1 <= j <= nums[i]`).
 * 3. If a forward position `i + j` has not been visited yet (`dp[i + j] == -1`),
 *    we update `dp[i + j] = dp[i] + 1`.
 * 4. The first time we reach the last index `N-1`, we return the minimum jumps.
 *
 * TIME  : O(N^2) worst-case (though O(N) in practice due to early exit and skipping).
 * SPACE : O(N) — for the `dp` array.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        // Base case: if there's only 1 element, we are already at the destination
        if (n == 1) {
            return 0;
        }

        // dp[i] stores the minimum jumps to reach index i, initialized to -1 (unvisited)
        vector<int> dp(n, -1);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            // If the current index is unreachable, we cannot jump from it
            if (dp[i] == -1) {
                continue;
            }

            int current = dp[i];
            
            // Explore all reachable steps from index i
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < n) {
                    // If the index was already reached with fewer jumps, skip it (BFS property)
                    if (dp[i + j] != -1) {
                        continue;
                    }
                    
                    // First time reaching index i + j, set the jump count
                    dp[i + j] = current + 1;
                    
                    // Early exit if we reached the last index
                    if (i + j == n - 1) {
                        return dp[i + j];
                    }
                } else {
                    // Out of array bounds, stop exploring further jumps from i
                    break;
                } 
            }
        }
        
        return -1;   
    }
};

/*
 * ALTERNATIVE: Greedy / BFS Level Tracking (O(N) Time, O(1) Space)
 * ───────────────────────────────────────────────────────────────
 * Instead of maintaining a full DP array, we can use a greedy approach to find the minimum jumps.
 * We track the current jump's range `[left, right]` and the farthest index we can reach.
 * When our traversal index reaches `right` (the end of the current jump's reach), 
 * we increment the jump count and update `right` to the `farthest` reached index.
 *
 *   int jump(vector<int>& nums) {
 *       int jumps = 0, current_end = 0, farthest = 0;
 *       for (int i = 0; i < nums.size() - 1; i++) {
 *           farthest = max(farthest, i + nums[i]);
 *           if (i == current_end) {
 *               jumps++;
 *               current_end = farthest;
 *           }
 *       }
 *       return jumps;
 *   }
 *
 * Trade-off: The greedy alternative is highly optimal, reducing the space complexity to O(1)
 * and guaranteed O(N) time complexity.
 */
