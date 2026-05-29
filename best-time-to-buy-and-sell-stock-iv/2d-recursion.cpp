/**
 * Best Time to Buy and Sell Stock IV (2D Memoization / Dynamic Programming Approach)
 * 
 * Problem: Find the maximum profit you can achieve by completing at most k transactions.
 * 
 * Approach:
 * - This approach optimizes the 3D dynamic programming state `dp[idx][buy][txn]` into a 2D state `dp[idx][op]`.
 * - A transaction consists of two operations: a BUY followed by a SELL.
 * - For `k` transactions, there are at most `2 * k` operations, numbered `0` to `2 * k - 1`.
 * - Even operations (`op % 2 == 0`) represent a BUY option:
 *   - Option A: Buy stock on day `idx` -> Subtract current price, transition to next operation `op + 1`.
 *   - Option B: Skip buying on day `idx` -> Remain in current operation state `op` for the next day.
 * - Odd operations (`op % 2 != 0`) represent a SELL option:
 *   - Option A: Sell stock on day `idx` -> Add current price, transition to next operation `op + 1`.
 *   - Option B: Skip selling on day `idx` -> Remain in current operation state `op` for the next day.
 * - We memoize the results using a 2D array/vector `dp[idx][op]` of size `N x (2K + 1)`.
 * 
 * Complexity:
 * - Time Complexity: O(N * K) where N is the number of days and K is the transaction limit.
 *   There are at most N * (2 * K) unique states, and each state is calculated in O(1) time.
 * - Space Complexity: O(N * K) to store the memoized states in the `dp` table + recursive stack overhead.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Helper function to find the maximum profit using 2D memoization.
     * 
     * @param k The maximum allowed transactions.
     * @param op The current operation index (0 to 2*k - 1).
     * @param prices Vector containing the stock prices for each day.
     * @param idx The current day index we are evaluating.
     * @param dp 2D vector for memoization storing states `dp[idx][op]`.
     * @return The maximum profit achievable from day `idx` onwards given the current operation count.
     */
    int transactions(int k, int op, vector<int>& prices, int idx, vector<vector<int>> &dp) {
        // Base Condition 1: If we have reached the end of the price list, no more profit can be made.
        if (idx >= prices.size()) return 0;
        
        // Base Condition 2: If we have completed all 2*k operations, we must stop.
        if (op == 2 * k) return 0;
        
        // Check Memoization: If this state has already been calculated, return the cached result.
        if (dp[idx][op] != -1) return dp[idx][op];
        
        // Scenario 1: Even operation (0, 2, 4...) -> This is a BUY operation.
        if (op % 2 == 0) {
            // Option A: Buy stock -> Subtract current price, transition to operation `op + 1`.
            int buyStock = -prices[idx] + transactions(k, op + 1, prices, idx + 1, dp);
            // Option B: Skip buying -> Remain in the same operation `op`.
            int skipBuy = transactions(k, op, prices, idx + 1, dp);
            
            // Memoize and return the maximum of these decisions.
            return dp[idx][op] = max(buyStock, skipBuy);
        }
        
        // Scenario 2: Odd operation (1, 3, 5...) -> This is a SELL operation.
        // Option A: Sell stock -> Add current price, transition to operation `op + 1`.
        int sellStock = prices[idx] + transactions(k, op + 1, prices, idx + 1, dp);
        // Option B: Skip selling -> Remain in the same operation `op`.
        int skipSell = transactions(k, op, prices, idx + 1, dp);
        
        // Memoize and return the maximum of these decisions.
        return dp[idx][op] = max(sellStock, skipSell);
    }

    /**
     * Main entry point to find the maximum profit.
     */
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        
        // Optimization: If the number of allowed transactions (2*k) is greater than or equal to the number of days,
        // we can perform as many transactions as we want. This is equivalent to "Best Time to Buy and Sell Stock II".
        if (2 * k >= n) {
            for (int i = 1; i < n; i++) {
                profit += max(0, prices[i] - prices[i - 1]);
            }
            return profit; 
        }
        
        // 2D Memoization table of size N x (2*K + 1) initialized to -1.
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, -1));
        
        // Start from day 0 with operation 0 (looking to BUY the first stock).
        return transactions(k, 0, prices, 0, dp);
    }
};