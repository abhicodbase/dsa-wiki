/**
 * Best Time to Buy and Sell Stock IV (Recursive Approach)
 * 
 * Problem: Find the maximum profit you can achieve by completing at most k transactions
 * (each transaction consisting of buying and selling one share).
 * 
 * Approach:
 * - We use a recursive backtracking approach to simulate the decision-making process for each day.
 * - On any given day, we have two options:
 *   1. If we don't currently hold a stock (`buy` is false):
 *      - Option A: Buy the stock at the current price (decreases profit by `prices[idx]`) and transition to a "holding" state.
 *      - Option B: Skip buying on this day and remain in the "not holding" state.
 *   2. If we currently hold a stock (`buy` is true):
 *      - Option A: Sell the stock at the current price (increases profit by `prices[idx]`), complete a transaction (`txn + 1`), and transition back to a "not holding" state.
 *      - Option B: Skip selling on this day and remain in the "holding" state.
 * 
 * Complexity:
 * - Time Complexity: O(2^N) where N is the number of days, due to the binary choice at each index. This will result in TLE (Time Limit Exceeded) for larger inputs, necessitating Dynamic Programming / Memoization.
 * - Space Complexity: O(N) auxiliary space consumed by the recursive call stack.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Helper function to recursively find the maximum profit.
     * 
     * @param k The maximum allowed transactions.
     * @param prices Vector containing the stock prices for each day.
     * @param idx The current day index we are evaluating.
     * @param txn The number of transactions completed so far.
     * @param buy A flag indicating if we currently hold a stock (true) or are looking to buy (false).
     * @return The maximum profit achievable from day `idx` onwards.
     */
    int buySellMxProfit(int k, vector<int>& prices, int idx, int txn, bool buy) {
        // Base Condition 1: If we have reached the end of the price list, no more profit can be made.
        if (idx >= prices.size()) return 0;
        
        // Base Condition 2: If we have completed the maximum allowed transactions `k`, we must stop.
        if (txn == k) return 0;
        
        // Scenario 1: We are not holding any stock, meaning we can either BUY or SKIP.
        if (buy == false) {
            // Option A: Buy stock on day `idx` -> Subtract current price, transition `buy` to true.
            int buyStock = -prices[idx] + buySellMxProfit(k, prices, idx + 1, txn, true);
            
            // Option B: Skip buying -> Profit remains unchanged, transition `buy` remains false.
            int skipBuy = buySellMxProfit(k, prices, idx + 1, txn, false);
            
            // Return the maximum of these two decisions.
            return max(buyStock, skipBuy);
        } 
        
        // Scenario 2: We are holding stock, meaning we can either SELL or SKIP.
        // Option A: Sell stock on day `idx` -> Add current price, increment transaction count `txn + 1`, transition `buy` to false.
        int sellStock = prices[idx] + buySellMxProfit(k, prices, idx + 1, txn + 1, false);
        
        // Option B: Skip selling -> Profit remains unchanged, transition `buy` remains true.
        int skipSell = buySellMxProfit(k, prices, idx + 1, txn, true);
        
        // Return the maximum of these two decisions.
        return max(sellStock, skipSell);
    }

    /**
     * Main entry point to find the maximum profit.
     */
    int maxProfit(int k, vector<int>& prices) {
        // Start from day 0, with 0 transactions completed, and not holding any stock (buy = false).
        return buySellMxProfit(k, prices, 0, 0, false);
    }
};

