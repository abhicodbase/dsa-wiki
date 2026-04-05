/*
 * Merge Intervals - Sorting Approach
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  merge(std::vector<std::vector<int>> &intervals) {
    if (intervals.empty())
      return {};
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> merged;
    merged.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] <= merged.back()[1]) {
        merged.back()[1] = std::max(merged.back()[1], intervals[i][1]);
      } else {
        merged.push_back(intervals[i]);
      }
    }
    return merged;
  }
};
