#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief Solution to the "Container With Most Water" problem (LeetCode 11).
 *
 * Problem statement:
 * Given an array `height` where each element represents the height of a vertical
 * line on the x‑axis (the index is the x‑coordinate), find two lines that together
 * with the x‑axis form a container such that the container holds the most water.
 * Return the maximum amount of water a container can store.
 *
 * Approach (Two‑Pointer Greedy):
 *   • Start with two pointers, one at the beginning (`left`) and one at the end (`right`).
 *   • The area formed by the lines at `left` and `right` is
 *       `min(height[left], height[right]) * (right - left)`.
 *   • To potentially find a larger area, move the pointer pointing to the shorter
 *     line inward, because the height is the limiting factor; moving the taller
 *     line cannot increase the area while the shorter line remains.
 *   • Continue until the pointers meet. The maximum area encountered is the answer.
 *
 * Time Complexity: O(N) – each element is visited at most once.
 * Space Complexity: O(1) – only a few integer variables are used.
 */
class Solution {
public:
  /**
   * @brief Computes the maximum water that can be contained.
   * @param height Vector of non‑negative integers representing line heights.
   * @return Maximum water volume.
   */
  int maxArea(vector<int> &height) {
    int left = 0;                              // left pointer index
    int right = static_cast<int>(height.size()) - 1; // right pointer index
    int mx = INT_MIN;                         // tracks maximum area found

    // Continue until the two pointers converge.
    while (left < right) {
      // Minimum height between the two lines determines the water level.
      int mn = min(height[left], height[right]);
      // Width is the distance between the pointers.
      int storage = mn * (right - left);
      // Update maximum area.
      mx = max(mx, storage);

      // Move the pointer at the shorter line inward, hoping for a taller line.
      if (height[left] < height[right]) {
        ++left;
      } else {
        --right;
      }
    }
    return mx; // maximum area found
  }
};