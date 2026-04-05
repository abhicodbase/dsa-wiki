#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    if (n == 0)
      return 0;

    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = height[0];
    for (int i = 1; i < n; ++i) {
      leftMax[i] = max(height[i], leftMax[i - 1]);
    }

    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      rightMax[i] = max(height[i], rightMax[i + 1]);
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
      result += min(leftMax[i], rightMax[i]) - height[i];
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
