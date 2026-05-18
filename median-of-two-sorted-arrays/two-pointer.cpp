#include <vector>

using namespace std;

/**
 * Approach: Two Pointers (Merge Step of Merge Sort)
 * 
 * Time Complexity: O(N + M) where N and M are the sizes of the two arrays.
 * Space Complexity: O(N + M) to store the merged array.
 * 
 * Note: A more optimal O(log(min(N, M))) approach exists using Binary Search.
 */
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    int totalLen = len1 + len2;
    vector<int> nm; // Merged array
    int idx1 = 0, idx2 = 0;

    // Merge elements from both arrays in sorted order
    while (idx1 < len1 && idx2 < len2) {
      if (nums1[idx1] < nums2[idx2]) {
        nm.push_back(nums1[idx1++]);
      } else {
        nm.push_back(nums2[idx2++]);
      }
    }

    // If there are remaining elements in nums1, append them
    while (idx1 < len1) {
      nm.push_back(nums1[idx1++]);
    }
    
    // If there are remaining elements in nums2, append them
    while (idx2 < len2) {
      nm.push_back(nums2[idx2++]);
    }

    // Determine the median based on whether the total length is odd or even
    if (totalLen % 2 == 1) {
      // Odd length: the median is the middle element
      return nm[totalLen / 2];
    } else {
      // Even length: the median is the average of the two middle elements
      return (nm[totalLen / 2 - 1] + nm[totalLen / 2]) / 2.0;
    }
  }
};