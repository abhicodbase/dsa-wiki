/**
 * Best Time to Buy and Sell Stock IV (Memoization / Dynamic Programming Approach)
 * 
 * Problem: Find the maximum profit you can achieve by completing at most k transactions.
 * 
 * Approach:
 * - This solution optimizes the recursive backtracking approach using Top-Down Memoization.
 * - Without memoization, we recompute the max profit for the same state `(idx, buy, txn)` multiple times.
 * - By saving the computed profit for each state in a 3D array `dp[idx][buy][txn]`, we reduce the complexity
 *   from exponential to polynomial.
 * 
 * State definition:
 * - `idx`: The current day index (0 to N-1).
 * - `buy`: A binary flag (0 = looking to buy, 1 = looking to sell).
 * - `txn`: The number of completed transactions so far (0 to k-1).
 * 
 * Complexity:
 * - Time Complexity: O(N * K) where N is the number of days and K is the transaction limit.
 *   There are at most N * 2 * K unique states, and each state transition is calculated in O(1) time.
 * - Space Complexity: O(N * K) to store the memoized states in the `dp` table + recursive stack overhead.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Memoization table: dp[idx][buy][txn]
    // 1001: Maximum number of days (constraints: prices.size() <= 1000)
    // 2: Buy state (0 = can buy, 1 = can sell)
    // 100: Maximum number of transactions (constraints: k <= 100)
    int dp[1001][2][100] = {};

    /**
     * Helper function to find the maximum profit using memoization.
     */
    int buySellMxProfit(int k, vector<int>& prices, int idx, int txn, int buy) {
        // Base Condition 1: If we have reached the end of the price list, return 0.
        if (idx >= prices.size()) return 0;
        
        // Base Condition 2: If we have completed `k` transactions, we can make no further transactions.
        if (txn == k) return 0;
        
        // Check Memoization: If this state has already been calculated, return the cached result.
        if (dp[idx][buy][txn]) return dp[idx][buy][txn];
        
        // Scenario 1: Not holding any stock (buy == 0). We can either BUY or SKIP.
        if (buy == 0) {
            // Option A: Buy stock on day `idx` -> transition buy to 1 (holding state).
            int buyStock = -prices[idx] + buySellMxProfit(k, prices, idx + 1, txn, 1);
            
            // Option B: Skip buying -> transition buy remains 0.
            int skipBuy = buySellMxProfit(k, prices, idx + 1, txn, 0);
            
            // Memoize and return the maximum.
            return dp[idx][buy][txn] = max(buyStock, skipBuy);
        } 
        
        // Scenario 2: Currently holding stock (buy == 1). We can either SELL or SKIP.
        // Option A: Sell stock on day `idx` -> increment txn by 1, transition buy to 0 (not holding).
        int sellStock = prices[idx] + buySellMxProfit(k, prices, idx + 1, txn + 1, 0);
        
        // Option B: Skip selling -> transition buy remains 1.
        int skipSell = buySellMxProfit(k, prices, idx + 1, txn, 1);
        
        // Memoize and return the maximum.
        return dp[idx][buy][txn] = max(sellStock, skipSell);
    }

    /**
     * Main entry point to find the maximum profit.
     */
    int maxProfit(int k, vector<int>& prices) {
        return buySellMxProfit(k, prices, 0, 0, 0);
    }
};


