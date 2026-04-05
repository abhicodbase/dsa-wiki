/*
 * Jump Game - Greedy Approach
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <algorithm>
#include <vector>

class Solution {
public:
  bool canJump(std::vector<int> &nums) {
    int maxReach = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i > maxReach)
        return false;
      maxReach = std::max(maxReach, i + nums[i]);
    }
    return true;
  }
};
