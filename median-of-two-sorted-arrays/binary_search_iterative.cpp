#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int n = nums1.size();
    int m = nums2.size();
    int left = 0, right = n;

    while (left <= right) {
      int partition1 = (left + right) / 2;
      int partition2 = (n + m + 1) / 2 - partition1;

      int maxLeft1 = (partition1 == 0) ? -1e9 : nums1[partition1 - 1];
      int minRight1 = (partition1 == n) ? 1e9 : nums1[partition1];

      int maxLeft2 = (partition2 == 0) ? -1e9 : nums2[partition2 - 1];
      int minRight2 = (partition2 == m) ? 1e9 : nums2[partition2];

      if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
        if ((n + m) % 2 == 0) {
          return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
        } else {
          return max(maxLeft1, maxLeft2);
        }
      } else if (maxLeft1 > minRight2) {
        right = partition1 - 1;
      } else {
        left = partition1 + 1;
      }
    }

    return 0.0;
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
