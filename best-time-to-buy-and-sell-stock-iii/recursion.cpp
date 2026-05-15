#include <vector>
using namespace std;
class Solution {
public:
  /**
   * Recursive function to find the maximum profit with at most two
   * transactions.
   *
   * @param prices The list of stock prices.
   * @param buy Boolean flag indicating if we are currently holding a stock.
   * @param index The current day we are considering.
   * @param profit The accumulated profit so far.
   * @param count The number of completed transactions.
   * @return Maximum profit possible from this state.
   */
  int maxTwoTransaction(vector<int> &prices, bool buy, int index, int profit,
                        int count) {
    int n = prices.size();

    // Base Case: If we have completed 2 transactions or reached the end of
    // prices
    if (count == 2 || index == n) {
      return profit;
    }

    if (buy == false) {
      // Case 1: We are not holding any stock.
      // We can either start a transaction (buy) or skip the current day.
      return max(maxTwoTransaction(prices, true, index + 1, profit,
                                   count), // Buy today
                 maxTwoTransaction(prices, false, index + 1, profit,
                                   count)); // Skip today
    } else {
      // Case 2: We are currently holding a stock.
      if (prices[index] >= prices[index - 1]) {
        // Price is rising: Continue holding and add the daily price difference
        // to profit.
        return maxTwoTransaction(prices, true, index + 1,
                                 profit + prices[index] - prices[index - 1],
                                 count);
      } else {
        // Price is falling: We have two choices:
        // 1. Sell at the previous day's peak (count increases).
        // 2. Hold through the dip (profit decreases temporarily).
        return max(maxTwoTransaction(prices, false, index, profit, count + 1),
                   maxTwoTransaction(prices, true, index + 1,
                                     profit + prices[index] - prices[index - 1],
                                     count));
      }
    }
  }

  int maxProfit(vector<int> &prices) {
    if (prices.empty())
      return 0;
    // Initial call: Not buying, starting from day 0, 0 profit, 0 transactions.
    return maxTwoTransaction(prices, false, 0, 0, 0);
  }
};