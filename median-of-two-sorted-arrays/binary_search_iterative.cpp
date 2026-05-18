#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

/**
 * Approach 1: Binary Search on Partition
 * 
 * Time Complexity: O(log(min(N, M))) where N and M are the sizes of the two arrays.
 * Space Complexity: O(1) auxiliary space.
 * 
 * The algorithm binary searches the smaller array to find the correct partition
 * index such that the left half has the same number of elements (or one more)
 * as the right half, and all elements in the left half are <= right half.
 */
class Solution {
public:
  double findMedian(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size(); // Guaranteed to be the shorter array
    int m = nums2.size(); // Guaranteed to be the longer array
    
    // We do binary search on the smaller array to minimize the search space.
    int low = 0;
    int high = n; // High is n, representing the number of elements we can pick from nums1

    while (low <= high) {
      // cut1 is the number of elements we pick from nums1 for the left half.
      int cut1 = (low + high) / 2;
      
      // cut2 is the number of elements we pick from nums2 for the left half.
      // (m + n + 1) / 2 ensures that if the total length is odd, the left half 
      // gets the extra element.
      int cut2 = (m + n + 1) / 2 - cut1;

      // Determine the border values on the left and right of the partition in both arrays.
      // Use INT_MIN if nothing is picked for the left half.
      int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
      int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
      
      // Use INT_MAX if all elements are picked for the left half.
      int right1 = (cut1 == n) ? INT_MAX : nums1[cut1]; 
      int right2 = (cut2 == m) ? INT_MAX : nums2[cut2]; 

      // Valid partition condition: all left elements <= all right elements.
      // Since nums1 and nums2 are already sorted, we only need to cross-check:
      if (left1 <= right2 && left2 <= right1) {
        
        // If the total number of elements is even, the median is the average
        // of the maximum of the left halves and the minimum of the right halves.
        if ((m + n) % 2 == 0) {
          return (max(left1, left2) + min(right1, right2)) / 2.0;
        }
        
        // If odd, the left half has the extra element, so the median is the 
        // maximum of the left halves.
        return max(left1, left2);
      }

      // If left1 > right2, we picked too many elements from nums1 for the left half.
      // We need to move the partition leftwards in nums1.
      if (left1 > right2) {
        high = cut1 - 1;
      } 
      // Otherwise, we didn't pick enough elements from nums1.
      // We need to move the partition rightwards in nums1.
      else {
        low = cut1 + 1;
      }
    }
    
    // Fallback return (should theoretically not be reached if inputs are valid)
    return 0.0;
  }

  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    // Ensure that nums1 is always the smaller array to guarantee O(log(min(N, M)))
    if (nums1.size() > nums2.size()) {
      return findMedian(nums2, nums1);
    }
    return findMedian(nums1, nums2);
  }
};