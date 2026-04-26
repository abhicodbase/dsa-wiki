#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Calculates the number of combinations that make up the given amount.
     * 
     * Time Complexity: O(N * Amount)
     * Space Complexity: O(Amount)
     */
    int change(int amount, vector<int>& coins) {
        // dp[i] represents the number of ways to make change for amount i
        // Initialize the DP array with 0
        vector<int> dp(amount + 1, 0);
        
        // Base case: There is 1 way to make change for amount 0 (using no coins)
        dp[0] = 1;
        
        int n = coins.size();
        
        // Iterate through each coin denomination
        // Outer loop on coins ensures we count combinations, not permutations
        for (int j = 0; j < n; j++) {
            // Update the dp array for all amounts from the current coin's value up to the target amount
            for (int i = coins[j]; i <= amount; i++) {
                // The number of ways to make amount 'i' is the current ways
                // plus the number of ways to make 'i - current_coin'
                dp[i] += dp[i - coins[j]];
            }
        }
        
        return dp[amount];
    }
};
