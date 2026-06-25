/*
 * LeetCode #45 — Jump Game II
 * https://leetcode.com/problems/jump-game-ii/
 *
 * APPROACH: Greedy (BFS Range Extension)
 * ──────────────────────────────────────────────────────────────
 * We solve the problem in O(N) time and O(1) space using a greedy range-extension
 * strategy. We track the current range of indexes we can reach with the current number
 * of jumps, and find the farthest index we can reach within that range.
 *
 * We maintain:
 * - `jumps`: the minimum number of jumps to reach the current range.
 * - `curEnd`: the boundary of the current range of jumps.
 * - `farthest`: the farthest index reachable from any index in the current range.
 *
 * We iterate through the array up to `N - 2`. When we reach `curEnd`, it means we must
 * take another jump. We increment `jumps` and set the new boundary `curEnd` to `farthest`.
 *
 * TIME  : O(N) — We make a single pass over the array of size N.
 * SPACE : O(1) — We use constant auxiliary space.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int curEnd = 0;
        int farthest = 0;
        
        // Why the loop stops at n-2 (not n-1): we never need to jump from the last index — just reach it.
        // If we included i = n-1 in the loop, we'd increment jumps one extra time unnecessarily
        // whenever curEnd == n-1.
        //
        // Trace on [2, 3, 1, 1, 4]:
        // i   nums[i]   farthest    i == curEnd?   jumps   curEnd
        // 0      2          2           yes          1       2
        // 1      3          4            no          1       2
        // 2      1          4           yes          2       4
        // 3      1          4            no          2       4
        // (loop ends; answer = 2)
        for (int i = 0; i < nums.size() - 1; i++) {
            // Update the farthest index we can reach from the current index i
            farthest = max(farthest, i + nums[i]);
            
            // If we have reached the boundary of the current jump's reach,
            // we must make another jump to proceed further.
            if (i == curEnd) {
                jumps++;
                curEnd = farthest;
            }
        }
        
        return jumps;
    }
};

/*
 * ALTERNATIVE: BFS-Style Dynamic Programming (O(N) Space)
 * ────────────────────────────────────────────────────────
 * We can also use an array `dp` of size N where `dp[i]` stores the minimum jumps to reach `i`.
 * We initialize `dp` with -1, set `dp[0] = 0`, and propagate distances forward:
 * `dp[i+j] = dp[i] + 1` for all valid `j <= nums[i]` if `dp[i+j]` is not yet set.
 *
 * Trade-off: The greedy approach is strictly superior as it reduces space from O(N) to O(1)
 * and time from worst-case O(N^2) to O(N).
 */
