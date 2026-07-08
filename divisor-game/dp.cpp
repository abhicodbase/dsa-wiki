/*
 * LeetCode #1025 — Divisor Game (Dynamic Programming Approach)
 * Time Complexity: O(N * sqrt(N))
 * Space Complexity: O(N)
 */
#include <vector>

using namespace std;

class Solution {
public:
    bool divisorGame(int n) {
        // dp[i] represents whether the active player will win starting with number i.
        vector<bool> dp(n + 1, false);
        
        // Base case: dp[0] = false, dp[1] = false (cannot make any valid move)
        for (int i = 2; i <= n; i++) {
            // Find all divisors of i
            for (int x = 1; x * x <= i; x++) {
                if (i % x == 0) {
                    // If choosing divisor x leaves the opponent with a losing state (dp[i-x] == false),
                    // then the active player wins.
                    if (!dp[i - x]) {
                        dp[i] = true;
                        break;
                    }
                    // Check the complementary divisor i / x
                    if (x > 1 && !dp[i - (i / x)]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[n];
    }
};
