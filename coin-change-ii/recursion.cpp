#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Coin Change II - Number of Combinations (Recursive Approach)
     * 
     * This function uses recursion to explore all possible combinations of coins
     * that sum up to the target amount.
     * 
     * @param amount The target sum to reach
     * @param coins The available coin denominations
     * @param index The current coin we are considering
     * @return The number of ways to make change for the given amount
     */
    int count(int amount, vector<int> &coins, int index) {
        // Base case: If amount is 0, we found a valid combination
        if (amount == 0) {
            return 1;
        }

        // Base case: If we've run out of coins or the amount is negative,
        // this path is not a valid combination.
        if (index >= (int)coins.size() || amount < 0) {
            return 0;
        }

        // Recursive step:
        // 1. Include the current coin: subtract its value from the amount and
        //    stay at the same index (since we can reuse the coin - unbounded).
        // 2. Exclude the current coin: move to the next coin index.
        return count(amount - coins[index], coins, index) +
               count(amount, coins, index + 1);
    }

    /**
     * Entry point for the recursive solution.
     */
    int change(int amount, vector<int> &coins) {
        return count(amount, coins, 0);
    }
};