#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    // dp[i] represents the minimum number of coins needed to make amount i
    // Initialize array with INT_MAX as a placeholder for "unreachable"
    vector<int> dp(amount + 1, INT_MAX);
    
    // Base case: 0 coins are needed to make amount 0
    dp[0] = 0;
    int length = coins.size();
    
    // Iterate through all amounts from 1 up to the target amount
    for (int i = 1; i <= amount; i++) {
      // Try every available coin denomination
      for (int j = 0; j < length; j++) {
        int idx = i - coins[j];
        
        // If the coin is larger than the current amount, or the remaining amount is unreachable, skip
        if (idx < 0 || dp[idx] == INT_MAX)
          continue;
          
        // If using this coin yields a smaller coin count, update dp[i]
        if (dp[idx] + 1 < dp[i]) {
          dp[i] = dp[idx] + 1;
        }
      }
    }
    
    // If the target amount is still unreachable, return -1
    if (dp[amount] == INT_MAX) {
      return -1;
    }
    
    // Return the minimum coins needed for the target amount
    return dp[amount];
  }
};