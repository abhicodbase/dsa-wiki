#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int num = prices.size();

        // Greedy insight: since we can hold at most one stock at a time but
        // trade unlimited times, capturing every upward consecutive-day move
        // is equivalent to the optimal buy-low/sell-high strategy.
        // If prices[i] > prices[i-1], we "buy" yesterday and "sell" today.
        for (int i = 1; i < num; i++) {
            if (prices[i] >= prices[i - 1]) {
                // Positive slope: add the gain to total profit
                profit += (prices[i] - prices[i - 1]);
            }
            // Negative or flat slope: skip (holding would lose money)
        }

        return profit;
    }
};