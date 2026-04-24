#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    if (height.empty())
      return 0;
      
    // Initialize two pointers, one at the beginning and one at the end
    int left = 0, right = height.size() - 1;
    
    // Variables to track the maximum height seen so far from left and right
    int leftMax = 0, rightMax = 0;
    int result = 0;

    // Move pointers towards each other until they meet
    while (left < right) {
      // The amount of water a bar can trap depends on the shorter of the max heights on its left and right.
      // We process the side with the shorter bar to ensure we are bounded by a taller bar on the other side.
      if (height[left] < height[right]) {
        // If current left bar is taller than or equal to leftMax, it can't trap water. Update leftMax.
        if (height[left] >= leftMax) {
          leftMax = height[left];
        } else {
          // It can trap water bounded by leftMax (since we know there's a taller bar on the right)
          result += leftMax - height[left];
        }
        left++; // Move the left pointer
      } else {
        // Symmetrically handle the right side
        if (height[right] >= rightMax) {
          rightMax = height[right]; // Update rightMax
        } else {
          // Trap water bounded by rightMax
          result += rightMax - height[right];
        }
        right--; // Move the right pointer
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> h1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << "Input: [0,1,0,2,1,0,1,3,2,1,2,1] | Output: " << sol.trap(h1) << endl;

  vector<int> h2 = {4, 2, 0, 3, 2, 5};
  cout << "Input: [4,2,0,3,2,5] | Output: " << sol.trap(h2) << endl;

  return 0;
}
