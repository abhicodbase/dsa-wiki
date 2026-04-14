/*
 * Jump Game - Greedy Approach
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  bool canJump(std::vector<int> &nums) {
    int n = nums.size();
    
    // The maximum index we can currently reach
    int maxReach = 0;
    
    for (int i = 0; i < n; i++) {
      // If the current index is beyond our maximum reachable index, we can't move forward
      if (i > maxReach)
        return false;
        
      // Update our maximum reach based on the current position's jump length
      maxReach = max(maxReach, i + nums[i]);
      
      // If our maximum reach safely covers the last index, we can stop and return true
      if (maxReach >= n - 1)
        return true;
    }
    return true;
  }
};
