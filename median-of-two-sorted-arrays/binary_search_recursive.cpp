#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int solve(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
    if (i >= nums1.size())
      return nums2[j + k - 1];
    if (j >= nums2.size())
      return nums1[i + k - 1];
    if (k == 1)
      return min(nums1[i], nums2[j]);

    int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : 1e9;
    int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : 1e9;

    if (midVal1 < midVal2) {
      return solve(nums1, i + k / 2, nums2, j, k - k / 2);
    } else {
      return solve(nums1, i, nums2, j + k / 2, k - k / 2);
    }
  }

public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int total = n + m;

    if (total % 2 == 1) {
      return solve(nums1, 0, nums2, 0, total / 2 + 1);
    } else {
      return (solve(nums1, 0, nums2, 0, total / 2) +
              solve(nums1, 0, nums2, 0, total / 2 + 1)) /
             2.0;
    }
  }
};

int main() {
  Solution sol;
  vector<int> nums1 = {1, 3};
  vector<int> nums2 = {2};
  cout << "Input: [1,3], [2] | Output: "
       << sol.findMedianSortedArrays(nums1, nums2) << endl;

  vector<int> nums1_2 = {1, 2};
  vector<int> nums2_2 = {3, 4};
  cout << "Input: [1,2], [3,4] | Output: "
       << sol.findMedianSortedArrays(nums1_2, nums2_2) << endl;

  return 0;
}
