#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int profitWithCooldown(vector<int>& prices, int op, int idx, vector<vector<int>>& dp) {
        if(idx >= prices.size()) return 0;
        if(dp[idx][op] != -1) return dp[idx][op];
        if(op == 0) {
            return dp[idx][op] = max(-prices[idx] + profitWithCooldown(prices, 1, idx+1, dp), profitWithCooldown(prices, 0, idx+1, dp));
        }
        return dp[idx][op] = max(prices[idx] + profitWithCooldown(prices, 0, idx+2, dp), profitWithCooldown(prices, 1, idx+1, dp));
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        return profitWithCooldown(prices, 0,0, dp);
    }
};
