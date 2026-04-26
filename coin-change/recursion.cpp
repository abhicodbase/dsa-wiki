#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
  int minCoinCombination(vector<int> &coins, int amount, int index, int count,
                         int &mn) {
    // Base Condition: We've successfully reached the exact amount
    if (amount == 0) {
      return count;
    }
    
    // Invalid paths: Used all coin types or overshot the amount
    if (index == coins.size() || amount < 0) {
      return INT_MAX;
    }
    
    // Recursively branch into two possibilities and return the minimum valid count:
    // 1. Choose the current coin (amount decreases, count increases, stay at same coin index)
    // 2. Skip the current coin (amount unchanged, count unchanged, move to next coin index)
    return min(
        minCoinCombination(coins, amount - coins[index], index, count + 1, mn),
        minCoinCombination(coins, amount, index + 1, count, mn));
  }
  
  int coinChange(vector<int> &coins, int amount) {
    int mn = INT_MAX; // Reference variable passed down to recursion (unused in current logic)
    
    // Start recursion with initial amount, starting from coin index 0 and 0 coins used
    int val = minCoinCombination(coins, amount, 0, 0, mn);
    
    // If val is still INT_MAX, no valid combination was found
    if (val == INT_MAX) {
      return -1;
    }
    
    return val;
  }
};