#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
  // 3D DP table to store [index][buy_state][transaction_count]
  // index: up to 10^5 days
  // buy_state: 0 (not holding), 1 (holding)
  // transaction_count: up to 2 transactions
  int dp[100001][2][3];

  /**
   * Recursive function with memoization to find the maximum profit.
   * 
   * @param prices Stock prices vector.
   * @param buy 0 if we can buy, 1 if we can sell.
   * @param index Current day index.
   * @param count Number of completed transactions.
   */
  int maxTwoTransaction(vector<int> &prices, int buy, int index, int count) {
    int n = prices.size();
    
    // Base Case: Max 2 transactions reached or end of prices
    if (count == 2 || index == n) {
      return 0;
    }

    // Return memoized result if available
    if (dp[index][buy][count] != -1)
      return dp[index][buy][count];

    int currentProfit = 0;

    if (buy == 0) {
      // Case: Not holding stock. We can either Buy or Skip.
      // 1. Buy: -prices[index] (cost) and move to 'holding' state
      int buyProfit = -prices[index] + maxTwoTransaction(prices, 1, index + 1, count);
      // 2. Skip: Stay in 'not holding' state for the next day
      int skipProfit = maxTwoTransaction(prices, 0, index + 1, count);
      currentProfit = max(buyProfit, skipProfit);
    } else {
      // Case: Holding stock. We can either Sell or Skip.
      // 1. Sell: +prices[index] (revenue) and move to 'not holding' state, increment count
      // Note: We stay at 'index' to allow buying again on the same day if logic permits,
      // though moving to index+1 is also common.
      int sellProfit = prices[index] + maxTwoTransaction(prices, 0, index, count + 1);
      // 2. Skip: Continue holding for the next day
      int skipProfit = maxTwoTransaction(prices, 1, index + 1, count);
      currentProfit = max(sellProfit, skipProfit);
    }

    // Memoize and return
    return dp[index][buy][count] = currentProfit;
  }

  int maxProfit(vector<int> &prices) {
    if (prices.empty()) return 0;
    // Initialize DP table with -1
    memset(dp, -1, sizeof(dp));
    return maxTwoTransaction(prices, 0, 0, 0);
  }
};